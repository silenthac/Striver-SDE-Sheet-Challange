# Write your MySQL query statement below
Select user_id, concat(UPPER(left(name,1)),LOWER(RIGHT(name,LENGTH(name)-1))) as name  from users   order by user_id ;
