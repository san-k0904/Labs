--Q1
select t.course_id,c.title,count(t.id)
from takes t join course c on t.course_id=c.course_id
group by t.course_id,c.title;


--Q2
select dept_name,count(distinct id)
from student s
group by dept_name
having count(id)>10;


--Q3
select dept_name,count(course_id)
from course
group by dept_name;


--Q4
select dept_name,avg(salary)
from instructor
group by dept_name
having avg(salary)>42000


--Q5
select sec_id,count(distinct id)
from takes
where semester='Spring'and year=2009
group by sec_id;


--Q6
select course_id,prereq_id
from prereq
order by course_id asc;


--Q7
select * 
from instructor
order by salary desc;


--Q8
SELECT dept_name, MAX(total_salary)
FROM 
    (SELECT dept_name, SUM(salary) AS total_salary
    FROM instructor
    GROUP BY dept_name);


--Q9
select round(avg_salary,2)
from(
    select avg(salary) as avg_salary
    from instructor
    group by dept_name
    having avg(salary)>42000
);


--Q10
select max(total_student)
from(select count(distinct id) as total_student
from takes
group by sec_id, semester, year
having semester = 'Spring' and year = 2010);


--Q11
select distinct name 
from instructor natural join teaches
where course_id in(select course_id from student s natural join takes where dept_name='Comp. Sci.');


--Q12
select round(avg(avg_salary),2)
from(select avg(salary) as avg_salary
    from instructor
    group by dept_name
    having avg(salary)>50000 and count(id)>5);


--Q13
with max_department(max_budget)as(
    select max(budget) from department)
    select dept_name,budget
    from department,max_department
    where department.budget=max_budget;


--Q14
with temp (total_sal)as
    (select avg(sum(salary)) from instructor group by dept_name)
	select dept_name,sum(salary)
	from instructor,temp
	group by dept_name,total_sal
	having sum(salary)>total_sal;


--Q15
savepoint sp1;

update student set dept_name = 'Physics'
where dept_name = 'Comp. Sci.';

rollback to sp1;


--Q16
savepoint sp2;

update instructor set salary = case
when salary <= 100000 then salary*1.05
else salary*1.03
end;

rollback to sp2;
