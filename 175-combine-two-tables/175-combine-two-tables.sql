# Write your MySQL query statement below
SELECT P.firstName,P.lastName,A.city,A.state
FROM Person P
LEFT JOIN Address A
ON A.personId = P.personId;