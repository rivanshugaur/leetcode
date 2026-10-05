# Write your MySQL query statement below
with lere as (select employee_id, 0 as bonus from employees  where name like 'M%' or employee_id%2=0)

select employee_id,salary as bonus from employees where name not like 'M%' and employee_id%2!=0
union
select * from lere
order by employee_id