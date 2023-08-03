# Write your MySQL query statement below
Select A.project_id, ROUND(AVG(B. experience_years),2) as average_years from Project as A join Employee  as B ON A.employee_id = B.employee_id group by A.project_id 
