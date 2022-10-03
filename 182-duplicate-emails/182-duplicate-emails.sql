# Write your MySQL query statement below
SELECT email
FROM(
SELECT COUNT(p1.email) as total,id,email
FROM Person p1
GROUP BY p1.email
    ) as temp
WHERE total>1