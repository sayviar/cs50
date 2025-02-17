-- Keep a log of any SQL queries you execute as you solve the mystery.

-- I search for the information in the chrim scene report to see what information are in general in there.
SELECT * FROM crime_scene_reports LIMIT 5;

-- I search in the same table for the specific street name 'Humphrey Street' and date 'July 28, 2023'  to see what descriptions it holds. 10.15 am
SELECT description FROM crime_scene_reports WHERE street = 'Humphrey Street' AND day = 28 AND month = 7 AND year = 2023;

-- I search for all the interviews that have taken place on the same day as the theft.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

-- There is a lot to take in so I decide to further filter it with the word 'thief' in the transcript.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript like '%thief%';

-- Information that I note down to continue: - Thief left parking lot, looking into security footage of bakery to find his car.
--                                           - Thief called someone less than a minute to take the earliest flight out of Fiftyville tomorrow
--                                           - Thief thief withdrew money early morning ATM on Leggett Street


-- Looking into bakery_security_logs table to see if the thief's car is clearly identifiable by looking for the day month year hour and the activity 'exit'
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = 'exit';


-- To find out what types of transactions there are in the atm_transaction table I search for all information '*'
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023;

-- Now I get more specific to find the differen transactions in the Leggett Street on that day
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- Find the names of the atm_transactions on that day at that atm and find the passengers on the flight on the day after if there are any correlations
SELECT people.name FROM passengers
JOIN flights ON flights.id = passengers.flight_id
JOIN people ON passengers.passport_number = people.passport_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.day = 29 AND atm_transactions.month = 7 AND atm_transactions.year = 2023 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';

-- Look into phone calls to see which calls were less than a minute long on that day

SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2023 AND duration < 60;

-- Adjusting the earlier SQL Query to have more information to filter with for example airports and phone numbers

SELECT people.name, people.id
FROM passengers
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON flights.origin_airport_id = airports.id
JOIN people ON passengers.passport_number = people.passport_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bakery_security_logs as bake ON bake.license_plate = people.license_plate
WHERE flights.day = 29 AND flights.month = 7 AND flights.year = 2023 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw'
AND city = 'Fiftyville' AND phone_calls.duration < 60 AND bake.day = 28 AND bake.month = 7 AND bake.year = 2023 AND bake.hour = 10 AND bake.minute BETWEEN 15 AND 25 AND bake.activity = 'exit';;

-- only two people remaining who could be the possible thief Bruce and Diana I consider adding the flight time to the Query so I can see which of those two booked the earlier flight or if they flew with the same machine
SELECT people.name, people.id, flights.hour, flights.minute
FROM passengers
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON flights.origin_airport_id = airports.id
JOIN people ON passengers.passport_number = people.passport_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bakery_security_logs as bake ON bake.license_plate = people.license_plate
WHERE flights.day = 29 AND flights.month = 7 AND flights.year = 2023 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw'
AND city = 'Fiftyville' AND phone_calls.duration < 60 AND bake.day = 28 AND bake.month = 7 AND bake.year = 2023 AND bake.hour = 10 AND bake.minute BETWEEN 15 AND 25 AND bake.activity = 'exit';;


-- Bruce Flew 7 hours and 40 minutes earlier than Diana so it's safe to assume because it said that he booked the earliest flight out of fiftyville that he is the one with the earlier flight
-- to clear things up I know search for the person Bruce tried to call and see if he also flew with that plane

SELECT receiver.name, receiver.id FROM people
JOIN phone_calls AS caller ON caller.caller = people.phone_number
JOIN people AS receiver ON caller.receiver = receiver.phone_number
WHERE people.id = 686048 AND day = 28 AND month = 7 AND year = 2023 AND duration < 60;

-- Robin is his complice now I only need to find out where they are heading which I do by searching for the flights with them on it

SELECT city FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE (people.id = 864400 OR people.id = 686048) AND day = 29 AND month = 7 AND year = 2023
GROUP BY city
HAVING COUNT(*) = 2;


-- I just realized that the complice isn't flying with the thief so I have to search for the flight differently
SELECT city FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE people.id = 686048 AND day = 29 AND month = 7 AND year = 2023
