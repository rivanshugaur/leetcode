# Write your MySQL query statement below
with lere as (select product_id,new_price as price from products
 WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date)
    FROM products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
))
select * from lere
union

select distinct p.product_id, 10 as price from products as p
where p.product_id not in (select product_id from lere)
