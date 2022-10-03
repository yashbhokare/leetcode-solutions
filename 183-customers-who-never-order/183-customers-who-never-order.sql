# Write your MySQL query statement below
SELECT name as Customers
FROM Customers 
WHERE Customers.ID NOT IN (SELECT customerId from Orders)