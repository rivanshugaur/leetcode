# Write your MySQL query statement below
with ctc as (select * from employee e1 where 3>=(select count(distinct e2.salary) from employee e2 where e2.salary>=e1.salary and e1.departmentId = e2.departmentId))

select d.name as Department, c.name as Employee, c.salary as Salary from ctc c join Department as d on c.departmentId = d.id