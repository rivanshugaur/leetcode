# Write your MySQL query statement below
with cte as(select e.name,e.salary,d.name as department from Employee as e join Department as d on e.departmentId =d.id )
select department , name as Employee , salary from cte where (salary, department) in (select max(salary), department from cte group by department)

