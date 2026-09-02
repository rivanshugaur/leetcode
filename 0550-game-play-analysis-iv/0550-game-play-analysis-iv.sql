# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from activity),2) as fraction from activity as a left join (select player_id ,min(event_date) as event_date from activity group by player_id) as b on a.player_id = b.player_id where  datediff(a.event_date,b.event_date)=1;

