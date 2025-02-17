import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    portfolio = db.execute(
        """SELECT DISTINCT port.symbol, port.shares, hist.share_price, round((port.shares * hist.share_price),2) as total, users.cash
                           FROM portfolio as port
                           JOIN users ON users.id = port.user_id
                           JOIN history hist ON hist.user_id = port.user_id AND hist.symbol = port.symbol
                           WHERE users.id = ?""",
        session["user_id"],
    )
    if not portfolio:
        return render_template("portfolio.html")
    cash = portfolio[0]["cash"]
    total = 0
    for row in portfolio:
        total += row["total"]
    total += cash
    return render_template(
        "portfolio.html", portfolio=portfolio, cash=cash, total=total
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not try_int(request.form.get("shares")):
            return apology("Shares has to be a number!")
        shares = int(request.form.get("shares"))
        symbol = request.form.get("symbol")
        if shares < 1:
            return apology("Please choose the numbers of shares at least 1.")
        if not symbol or not shares:
            return apology("Please provide a valid symbol!")

        quote = lookup(symbol)
        if not quote:
            return apology("The stock couldn't be found.")

        money = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        # spent = db.execute(
        #   "SELECT SUM(round(shares * share_price,2)) as spent FROM history WHERE user_id = ?", session["user_id"])[0]["spent"]
        # if spent == None:
        #   spent = 0
        money = money[0]["cash"]
        if money * 100 < quote["price"] * 100 * shares:
            return apology("Sorry, your balance isn't enough for this purchase.")

        stock = db.execute(
            "SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?",
            session["user_id"],
            symbol,
        )
        if len(stock) < 1:
            db.execute(
                "INSERT INTO portfolio (user_id, symbol, shares) VALUES(?,?,?)",
                session["user_id"],
                symbol,
                shares,
            )
        else:
            db.execute(
                "UPDATE portfolio SET shares = shares + ? WHERE user_id = ? AND symbol = ?",
                shares,
                session["user_id"],
                symbol,
            )
        db.execute(
            "INSERT INTO history (user_id, symbol, shares, share_price, total) VALUES(?,?,?,?,?)",
            session["user_id"],
            symbol,
            shares,
            quote["price"],
            quote["price"] * 100 * (-shares),
        )
        db.execute(
            "UPDATE users SET cash = cash - ? WHERE id = ?",
            quote["price"] * (shares),
            session["user_id"],
        )

        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT * FROM history WHERE user_id = ?", session["user_id"])
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["user"] = rows[0]["username"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Please type in a symbol")

        quote = lookup(symbol)
        if not quote:
            return apology("Please type in a valid symbol")

        return render_template("quoted.html", quote=quote)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        if (
            not request.form.get("username")
            or not request.form.get("password")
            or not request.form.get("confirmation")
        ):
            return apology("Please fill in the form!")
        username = request.form.get("username")
        password = generate_password_hash(
            request.form.get("password"), method="pbkdf2", salt_length=16
        )
        if not (request.form.get("password") == request.form.get("confirmation")):
            return apology("Password and confirmation has to be equal!")
        userExists = db.execute("SELECT * FROM users WHERE username=?", username)
        if not userExists:
            db.execute(
                "INSERT INTO users (username, hash) values(?, ?)", username, password
            )
            flash("User has been created!")
            rows = db.execute(
                "SELECT * FROM users WHERE username = ?", request.form.get("username")
            )
            session["user_id"] = rows[0]["id"]
            session["user"] = rows[0]["username"]
            return redirect("/")
        else:
            return apology("User is already taken!")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        if not try_int(request.form.get("shares")):
            return apology("Shares has to be a number!")
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        ownedShares = db.execute(
            "SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?",
            session["user_id"],
            symbol,
        )
        if not symbol:
            return apology("Missing Symbol")
        elif not shares:
            return apology("Missing Shares")
        elif shares < 1:
            return apology("Invalid Shares")
        elif shares > ownedShares[0]["shares"]:
            return apology("Too many shares.")
        elif shares == ownedShares[0]["shares"]:
            db.execute(
                "DELETE FROM portfolio WHERE user_id = ? AND symbol = ?",
                session["user_id"],
                symbol,
            )
        else:
            db.execute(
                "UPDATE portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ?",
                shares,
                session["user_id"],
                symbol,
            )
        history = db.execute(
            "SELECT * FROM history WHERE user_id =? AND symbol =?",
            session["user_id"],
            symbol,
        )
        db.execute(
            "INSERT INTO history (user_id, symbol, shares, share_price, total) VALUES(?,?,?,?,?)",
            session["user_id"],
            symbol,
            -shares,
            history[0]["share_price"],
            history[0]["share_price"] * 100 * shares,
        )
        db.execute(
            "UPDATE users SET cash = cash + ? WHERE id = ?",
            history[0]["share_price"] * shares,
            session["user_id"],
        )
        flash("Sold!")
        return redirect("/")

    stocks = db.execute(
        "SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"]
    )
    return render_template("sell.html", stocks=stocks)


@app.route("/changePassword", methods=["GET", "POST"])
@login_required
def changePassword():
    """Change Password"""
    if request.method == "POST":
        newPassword = request.form.get("newPassword")
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        if not check_password_hash(rows[0]["hash"], request.form.get("oldPassword")):
            return apology("Old password wrong!", 420)
        else:
            db.execute(
                "UPDATE users SET hash = ? WHERE id = ?",
                generate_password_hash(newPassword, method="pbkdf2", salt_length=16),
                session["user_id"],
            )
            flash("Password has been changed!")
            return redirect("/portfolio")
    return render_template("changePassword.html")


def try_int(s):
    try:
        int(s)
    except ValueError:
        return False
    else:
        return True
