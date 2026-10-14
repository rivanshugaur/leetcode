# Write your MySQL query statement below
with cte as (
    select d.name as Department , e.name as Employee, e.salary from Employee as e join Department as d on e.departmentId=d.id
),
lun as (select *, dense_rank() over(partition by department order by salary desc) as ranki from cte)
select department , employee , salary from lun where lun.ranki<=3