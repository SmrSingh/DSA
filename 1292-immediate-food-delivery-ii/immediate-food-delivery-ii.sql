# Write your MySQL query statement below
WITH first_order AS (
    SELECT
        customer_id,
        MIN(order_date) AS first_date
    FROM Delivery
    GROUP BY customer_id
)
SELECT
    ROUND(
        100.0 * SUM(
            CASE
                WHEN d.order_date = d.customer_pref_delivery_date
                THEN 1
                ELSE 0
            END
        ) / COUNT(*),
        2
    ) AS immediate_percentage
FROM first_order f
JOIN Delivery d
    ON f.customer_id = d.customer_id
   AND f.first_date = d.order_date;