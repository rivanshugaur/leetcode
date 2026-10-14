# Write your MySQL query statement below
with cte as (
    select d.name as Department , e.name as Employee, e.salary from Employee as e join Department as d on e.departmentId=d.id
)
select * from cte as c1 where 3>=(
    select count(distinct salary) from cte as c2 where c2.department=c1.department and c1.salary<=c2.salary
)