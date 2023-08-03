# Write your MySQL query statement below
# Select student_id,subject_name,count(subject_name) from Examinations group by student_id,subject_name
Select A.student_id,A.student_name,B.subject_name,count(C.subject_name) as attended_exams from Students as A join Subjects as B Left Join Examinations as C ON A.student_id  = C.student_id  AND B.subject_name = C.subject_name group by student_id,subject_name order by student_id,subject_name

