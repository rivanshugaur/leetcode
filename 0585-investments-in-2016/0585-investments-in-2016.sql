# Write your MySQL query statement below
with lere as (select * from insurance i1 where i1.tiv_2015 in (select i2.tiv_2015 from insurance i2 where i1.tiv_2015 = i2.tiv_2015 and i1.pid!=i2.pid))

select round(sum(tiv_2016),2) as tiv_2016 from lere where (lat,lon)in 
(select lat,lon from insurance group by lat,lon having count(*)=1)