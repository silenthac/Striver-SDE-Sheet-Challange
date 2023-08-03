# Write your MySQL query statement below
Select  A.name,B.bonus from Employee as A  left join Bonus as B ON A.empId =B.empId where B.bonus<1000 OR B.bonus is NULL;
