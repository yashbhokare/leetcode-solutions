# Write your MySQL query statement below
SELECT p1.name as Employee 
FROM Employee p1, Employee p2
WHERE p1.managerId =p2.id AND p1.salary > p2.salary

