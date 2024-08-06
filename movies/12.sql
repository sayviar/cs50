SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on people.id = stars.person_id
WHERE people.name = 'Jennifer Lawrence' OR people.name = 'Bradley Cooper'
GROUP BY title HAVING COUNT(name) = 2;
