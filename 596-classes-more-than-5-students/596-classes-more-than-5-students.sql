# Write your MySQL query statement below
SELECT S.class
FROM (
    SELECT class,COUNT(class) as total
    FROM Courses
    GROUP BY class
) S
WHERE S.Total >=5
