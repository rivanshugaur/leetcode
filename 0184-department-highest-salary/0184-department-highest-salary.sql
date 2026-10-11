# Write your MySQL query statement below
select d.name as Department,e1.name as Employee, e1.salary as Salary from Employee as e1 join Department as d on e1.departmentId = d.id
where (e1.salary , e1.departmentId) in
(select max(salary) , departmentId from employee group by departmentId )