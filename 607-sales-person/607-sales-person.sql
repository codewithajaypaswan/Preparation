# Write your MySQL query statement below
SELECT name from SalesPerson WHERE sales_id NOT IN(
    SELECT sales_id from Orders WHERE com_id IN(
        SELECT com_id from Company WHERE name = "RED"
    )
)
