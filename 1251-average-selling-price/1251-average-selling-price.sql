# Write your MySQL query statement below
Select A.product_id, ROUND(sum(A.price*B.units)/sum(B.units),2) as average_price from Prices as A join UnitsSold as B ON  A.product_id  =B.product_id  and (B.purchase_date between a.start_date and a.end_date )  group by A.product_id 
