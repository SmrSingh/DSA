# Write your MySQL query statement below
select player_id, min(event_date)AS FIRST_LOGIN
from activity
group by player_id