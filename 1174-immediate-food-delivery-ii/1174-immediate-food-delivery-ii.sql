 Select ROUND(AVG(CASE WHEN datediff(customer_pref_delivery_date,order_date)=0 then 1 else 0 end)*100 ,2) as immediate_percentage  from delivery where (customer_id,order_date) IN(
    select customer_id,min(order_date) from Delivery group by customer_id);
    
  
    
    
    
