# Write your MySQL query statement below
# we have to explicityly mention for NULL values otherwise it will  not take
Select name from Customer where referee_id<>2 OR referee_id is NULL;
