from cs50 import SQL
from flask import Flask, render_template, redirect, request

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")


SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee", "Football"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():

    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id= ?", id)
        return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("error.html", message="Error")


    db.execute("INSERT INTO registrants (name, sport) VALUES(?,?)", name, sport)


    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)

