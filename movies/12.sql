SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on people.id = stars.person_id
WHERE people.name = 'Jennier Lawrence' OR people.name = 'Bradley Cooper';
GROUP BY title HAVING people.name = 'Jennier Lawrence' AND people.name = 'Bradley Cooper';
