# Write your MySQL query statement below
Select  customer_id,count(customer_id) as count_no_trans  from Visits where visit_id not in(Select visit_id from Transactions) group by customer_id
