# Write your MySQL query statement below
Select A.user_id ,ROUND(AVG(CASE WHEN B.action ="confirmed" then 1 else 0 end),2) as  confirmation_rate from Signups as A Left Join  Confirmations as B On A.user_id  = B.user_id  group by A.user_id;
