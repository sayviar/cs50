SELECT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
GROUP BY movies.title HAVING people.name = 'Kevin Bacon';
