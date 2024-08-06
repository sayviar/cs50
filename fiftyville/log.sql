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
--                                           - Thief thief withdrew money early morning ATM on Legget Street


-- Looking into bakery_security_logs database to see if the thief's car is clearly identifiable by looking for the day month year hour and the activity 'exit'
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = 'exit';
