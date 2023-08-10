# Write your MySQL query statement below
select "Low Salary" as category, Sum(Case when income<20000 then 1 else 0 end) as accounts_count from Accounts

Union 
select "Average Salary" as category, Sum(Case when income between 20000 and 50000 then 1 else 0 end) as accounts_count from Accounts

 Union 
 select "High Salary" as category, Sum(Case when income>50000 then 1 else 0 end) as accounts_count from Accounts;
