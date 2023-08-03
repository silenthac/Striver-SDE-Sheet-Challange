# Write your MySQL query statement below
Select Register.contest_id , ROUND(((count(distinct(user_id))*100)/(Select count(*) from Users)),2) as percentage from Register  group by contest_id order by percentage desc , contest_id
