--Q1
select course_ID,title
from(
    select c.course_id,c.title
    from course c, teaches t
    where t.semester = 'Fall' and t.year = 2009 and t.course_ID = c.course_ID
	)
	union
	(
    select c.course_id,c.title
    from course c, teaches t
    where t.semester = 'Spring' and t.year = 2010 and t.course_ID = c.course_ID
	);



--Q2
select course_ID,title
from(
    select c.course_id,c.title
    from course c, teaches t
    where t.semester = 'Fall' and t.year = 2009 and t.course_ID = c.course_ID
	)
	intersect
	(
    select c.course_id,c.title
    from course c, teaches t
    where t.semester = 'Spring' and t.year = 2010 and t.course_ID = c.course_ID
	);


--Q3
select course_ID,title
from(
    select c.course_id,c.title
    from course c, teaches t
    where t.semester = 'Fall' and t.year = 2009 and t.course_ID = c.course_ID
	)
	minus
	(
    select c.course_id,c.title
    from course c, teaches t
    where t.semester = 'Spring' and t.year = 2010 and t.course_ID = c.course_ID
	);


--Q4
select * from takes where course_id='BIO-347';
select * from course;
select * from teaches;
SELECT c.title
FROM course c
WHERE not exists (
    SELECT 1
    FROM takes t
    WHERE t.course_id = c.course_id
);


--Q5
select * from teaches where (semester='Fall' and year=2009 ) or (year=2010 and semester='Spring' ) order by year;
select c.course_id,c.title
from course c,teaches t
where t.year=2009 and t.semester='Fall' and t.course_id in(select course_id from teaches  where year=2010 and semester='Spring')
and t.course_id=c.course_id;


--Q6
select count(distinct id)
from takes
where course_id in(select tea.course_id 
from teaches tea ,instructor i
where i.id = 10101 and tea.id=i.id);


--Q7
/*select c.course_id,c.title
from course c,teaches t
where t.semester='Fall' and t.year=2009 and t.course_id not in (select course_id from teaches t2 where semester='Spring'and year=2010 and 
    t2.course_id=t.course_id) and t.course_id=c.course_id;*/

select c.course_id,c.title
from course c,teaches t
where t.semester='Fall' and t.year=2009 and t.course_id not in (select course_id from teaches where semester='Spring'and year=2010)
    and t.course_id=c.course_id;


--Q8
select name 
from student 
where name in(select name from instructor);


--Q9
select name
from instructor
where salary>some (select salary from instructor where dept_name='Biology');


--Q10
select name
from instructor
where salary>all (select salary from instructor where dept_name='Biology');


--Q11
select dept_name,avg(salary)
from instructor
group by dept_name
having avg(salary) >=all(select avg(salary) from instructor group by dept_name);


--Q12
select dept_name,budget
from department
where budget<=all(select avg(salary) from instructor);


--Q13
select c.course_id,c.title
from course c,teaches t
where t.year=2009 and t.semester='Fall' and exists(select 1 from teaches q where q.semester='Spring' and q.year=2010 
    and t.course_id=q.course_id) 
    and t.course_id=c.course_id;


--Q14
select s.id,s.name
from student s
where exists(
    select 1 
    from takes t , course c
    where c.dept_name='Biology' and c.course_id=t.course_id and t.id=s.id
);


--Q15
select t.course_id,c.title
from teaches t,course c
where t.course_id in(
    select course_id
    from teaches
    where year=2009
    group by course_id
    having count(course_id)<2)and t.course_id=c.course_id;


--Q16
select s.id,s.name
from student s,takes t
where (
    select count(t2.course_id)
    from takes t2,course c
    where c.dept_name='Comp. Sci.' and t2.course_id=c.course_id and  s.id=t.id
)>=2;


--Q17
select round(avg_sal,2)
from (
    select avg(salary) as avg_sal
    from instructor
    group by dept_name
    having avg(salary)>42000
);


--Q18
create view all_courses as
select sec.course_id, sec.sec_id, sec.building,sec.room_number
from section sec
where sec.course_id in(select c.course_id from course c where c.dept_name='Physics' and sec.course_id=c.course_id )
    and sec.semester='Fall'and sec.year=2009;


--Q19
select * from all_courses;


--Q20
create view department_total_salary as
select dept_name,sum(salary) as total_salary
from instructor
group by dept_name;