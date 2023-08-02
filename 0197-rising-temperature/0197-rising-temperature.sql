# Write your MySQL query statement below
Select a.id from Weather as a inner join Weather as b ON datediff(a.recordDate,b.recordDate)=1 AND a.temperature>b.temperature


