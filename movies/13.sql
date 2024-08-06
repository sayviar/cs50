SELECT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movies_id
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Kevin Bacon'
GROUP BY movies.title;

SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958;

SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958);

SELECT name FROM people WHERE id in
(SELECT person_id FROM stars WHERE movie_id in
(SELECT movie_id FROM stars WHERE person_id =
(SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958)));
