Select max(num) as num from  (Select num  from MyNumbers group by num having count(*)=1) as num
