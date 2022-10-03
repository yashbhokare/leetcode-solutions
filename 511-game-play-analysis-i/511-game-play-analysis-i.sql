# Write your MySQL query statement below
# SELECT p1.player_id,p1.event_date as first_login 
# FROM Activity p1, Activity ( SELECT DISTINCT(player_id) from Activity)
# WHERE (p1.player_id=p2.player_id AND p1.event_date < p2.event_date)

select player_id, min(event_date) as first_login
from activity 
group by player_id