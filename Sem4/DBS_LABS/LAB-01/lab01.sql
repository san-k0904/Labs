-- Q1
create table employee(emp_no numeric(2),emp_name varchar(20),emp_address varchar(30));
-- Q2
insert into employee values(1,'Suresh','Durgapur');
insert into employee (emp_name,emp_address,emp_no)values('Jessica','Manipal',2);
insert into employee values (3,'Ramesh','Gorakhpur');
insert into employee values (3,'Mukesh','Dholakpur');
insert into employee values(4,'Rohan','Mumbai');
insert into employee values (5,'Raj','Chattisgarh');
-- Q3
select emp_name as names
from employee
order by emp_no;
-- Q4
select * 
from employee
where emp_address='Manipal';
-- Q5
alter table employee add(salary numeric(10,2));
-- Q6
update employee set salary =10000
where emp_no=1;
update employee set salary =5000
where emp_no=2;
update employee set salary =15000
where emp_no=3;
update employee set salary =25000
where emp_no=4;
update employee set salary =10000
where emp_no=5;
-- Q7
desc employee;
-- Q8
update employee set emp_address='Mangalore'
where emp_no=5;
delete from employee
where emp_address='Mangalore';
-- Q9
rename employee to employee1;
-- Q10
drop table employee1;
