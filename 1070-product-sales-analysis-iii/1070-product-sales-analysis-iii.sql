# Write your MySQL query statement below
Select product_id,year as first_year,quantity,price from Sales where (year,product_id ) in (select min(Sales.year),Sales.product_id from Sales join Product ON Sales.product_id = Product.product_id group by product_id);
