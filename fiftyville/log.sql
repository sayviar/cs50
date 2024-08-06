-- Keep a log of any SQL queries you execute as you solve the mystery.

-- I search for the information in the chrim scene report to see what information are in general in there.
SELECT * FROM crime_scene_reports LIMIT 5;

-- I search in the same table for the specific street name 'Humphrey Street' and date 'July 28, 2023'  to see what descriptions it holds.
SELECT description FROM crime_scene_reports WHERE street = 'Humphrey Street' AND day = 28 AND month = 7 AND year = 2023;

-- I search for all the interviews that have taken place on the same day as the theft.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

-- There is a lot to take in so I decide to further filter it with the word 'thief' in the transcript.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript like '%thief%';

-- Information that I note down to continue: - Thief left parking lot, looking into security footage of bakery to find his car.
--                                           - Thief called someone less than a minute to take the earliest flight out of Fiftyville tomorrow
--                                           - Thief thief withdrew money 


