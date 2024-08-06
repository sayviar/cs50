SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on people.id = stars.person_id
GROUP BY title HAVING people.name = 'Jennier Lawrence' AND people.name = 'Bradley Cooper';
