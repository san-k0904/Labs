--Q1
create table employee(EmpNo numeric(2),EmpName varchar(20)not null,Gender varchar(10) not null,Salary numeric(10,2) not null ,
    Address varchar(30) not null, DNo numeric(4),
    Primary key(EmpNo),
    check (Gender in ('M','F')));


--Q2
create table department(DeptNo numeric(4),DeptName varchar(20), Location varchar(30),
    primary key(DeptNo),
    unique(DeptName));


--Q3
Alter table employee add constraint fk_department foreign key (DNo) references department(DeptNo);


--Q4
insert into department values(314,'CSE','Manipal_MIT');
insert into department values(312,'IT','Manipal_MIT');
insert into department values(303,'CCE','Banglore_MIT');
insert into employee values(1,'jessica','F',5000,'Manipal',312);
insert into employee values(2,'sankalp','M',25000,'Delhi',314);
insert into employee values(3,'ashwin','M',3000,'Manglore',303);
insert into employee values(34,'mukesh','M',10000,'Durgapur',null);


--Q5
insert into employee values(34,null,'M',null,null,314);
insert into employee values(35,'xyz','m',250,'Dholakpur',303);


--Q6
delete from department where deptno=303;


--Q7
alter table employee drop constraint fk_department;
alter table employee add constraint fk_department foreign key (DNo) references department(DeptNo) on delete cascade; 

--Q8
alter table Employee modify(constraint defSal Salary default 10000);

--Q9
alter table employee drop constraint fk_department;

--RUN University.sql



select * from employee;
select name,dept_name
from Student;


--Q10
select name
from instructor
where dept_name='Comp. Sci.';


--Q11
select title
from Course
where dept_name='Comp. Sci.' and credits=3;


--Q12
select c. course_id,c.title,s.name
from course c, takes t, student s 
where s.id=t.id and t.course_id=c.course_id and s.id=12345;

--Q13
select *
from instructor
where salary between 40000 and 90000;


--Q14
select id,name
from instructor i
where id not in(select id
    			from teaches t
    			where i.id=t.id);


--Q15
select * from SECTION;
select distinct s.name,c.title,sec.year
from student s, course c, SECTION sec , takes t
where sec.room_number in(select room_number from SECTION where room_number=303) and c.course_id=sec.course_id and c.course_id=t.course_id
    and t.id=s.id;


--Q16
select * from takes;
select distinct s.name,c.title as c_name,c.course_id
from student s,course c, takes t
where t.year=2015 and c.course_id=t.course_id and s.id=t.id;


--Q17
select name,salary as min_salary
from instructor
where dept_name='Comp. Sci.' and salary in(select min(salary) from instructor where dept_name='Comp. Sci.');

select name,salary as inst_salary
from instructor
where salary >some(select salary from instructor where dept_name='Comp. Sci.');


--Q18
select name
from instructor 
where dept_name like '%ch%';


--Q19
select name,Length(name) as name_length
from student;


--Q20
select dept_name,substr(dept_name,3,3) as substring
from department;


--Q21
select Upper(name) as NAME
from instructor;


--Q22
update takes set Grade=NVL(Grade,'NA');
select * from takes;


--Q23
select name,salary ,round(salary/3,2) as rounded_salary
from instructor;


--Q24
alter table employee add(DOB  date);
update employee set DOB=date'2004-03-31'where empname='jessica';
update employee set DOB=date'2004-04-09'where empname='sankalp';
update employee set DOB=date'2004-03-19'where empname='ashwin';
update employee set DOB=date'2004-07-20'where empname='mukesh';
update employee set DOB=date'2004-12-31'where empname='ramesh';

update employee set DOB=to_date('20041223','YYYYMMDD')where empname='ramesh';

select empname,to_char(DOB,'DD-MON-YYYY')
from employee;

select empname,to_char(DOB,'DD-MON-YY')
from employee;

select empname,to_char(DOB,'DD-MM-YY')
from employee;


--Q25
select empname,to_char(DOB,'YEAR')
from employee;

select empname,to_char(DOB,'Year')
from employee;

select empname,to_char(DOB,'year')
from employee;


--ADDITIONAL EXERCISE


--Q1
delete from employee where salary<=5000;
select * from employee order by empno asc;

--Q2
select DOB, to_char(DOB,'Q') as Quarter_year
from employee;