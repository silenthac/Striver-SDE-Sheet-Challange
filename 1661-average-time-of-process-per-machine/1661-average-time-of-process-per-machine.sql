# Write your MySQL query statement below
Select A.machine_id,ROUND(AVG(a.timestamp-b.timestamp),3) as processing_time from Activity as A join Activity as B ON A.machine_id=B.machine_id AND A.process_id=B.process_id AND A.timestamp>B.timestamp group by b.machine_id

