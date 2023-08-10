# Write your MySQL query statement below
Select a.product_name,SUM(b.unit) as unit from Products as a left join Orders as b ON a.product_id = b.product_id where substr(order_date,1, 7) = '2020-02' group by b.product_id having sum(b.unit)>=100
