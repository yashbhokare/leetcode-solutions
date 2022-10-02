# Write your MySQL query statement below
# SELECT p1.name as Employee 
# FROM Employee p1, Employee p2
# WHERE p1.managerId =p2.id AND p1.salary > p2.salary

select E.name as Employee from Employee E
join Employee as M
on E.ManagerId = M.Id
where E.Salary > M.Salary;