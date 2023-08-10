# Write your MySQL query statement below
Select employee_id,department_id from Employee where primary_flag = 'Y' UNION  select employee_id,department_id from Employee group by employee_id having count(*)=1
