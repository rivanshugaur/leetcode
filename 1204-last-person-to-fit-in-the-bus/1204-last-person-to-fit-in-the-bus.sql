# Write your MySQL query statement below
with lere as (select *,sum(weight) over(order by turn) as num from queue )

 select lere.person_name from lere where lere.num = (select max(lere.num) from lere where lere.num<=1000 )