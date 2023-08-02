/* Write your T-SQL query statement below */
Select tweet_id from Tweets where LEN(content)>15;