# Write your MySQL query statement below

Select B.unique_id,A.name from Employees as A Left Join EmployeeUNI as B ON A.id = B.id;

