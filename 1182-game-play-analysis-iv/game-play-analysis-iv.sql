# Write your MySQL query statement below
WITH first_login AS (
    SELECT
        player_id,
        MIN(event_date) AS first_day
    FROM Activity
    GROUP BY player_id
),
returned AS (
    SELECT
        f.player_id,
        MAX(
            CASE
                WHEN a.event_date = DATE_ADD(f.first_day, INTERVAL 1 DAY)
                THEN 1
                ELSE 0
            END
        ) AS returned_next_day
    FROM first_login f
    LEFT JOIN Activity a
        ON f.player_id = a.player_id
    GROUP BY f.player_id
)
SELECT ROUND(AVG(returned_next_day), 2) AS fraction
FROM returned;