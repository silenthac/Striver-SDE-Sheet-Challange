# Write your MySQL query statement below
 select a.employee_id ,a.name  ,b.cnt  as reports_count, b.ag as average_age from Employees a inner join  (Select reports_to,count(*) as cnt,ROUND(AVG(age)) as ag from Employees group by reports_to having count(*)>=1)b ON a.employee_id = b.reports_to order by employee_id;
#