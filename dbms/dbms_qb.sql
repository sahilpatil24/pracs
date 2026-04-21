create database temp;
use temp;
CREATE TABLE dept (
    dno INT PRIMARY KEY,
    dname VARCHAR(50),
    dmgrid INT,
    appointedate DATE
);

CREATE TABLE emp (
    empid INT PRIMARY KEY,
    empname VARCHAR(50),
    bdate DATE,
    address VARCHAR(100),
    salary INT CHECK (salary BETWEEN 10000 AND 30000),
    mgrid INT,
    dno INT,
    FOREIGN KEY (dno) REFERENCES dept(dno)
);

CREATE TABLE dept_location (
    dno INT,
    dlocation VARCHAR(50),
    FOREIGN KEY (dno) REFERENCES dept(dno)
);

INSERT INTO dept VALUES
(1,'HR',101,'2020-01-01'),
(2,'IT',102,'2021-02-01'),
(3,'Sales',103,'2022-03-01'),
(4,'Finance',104,'2023-04-01'),
(5,'Admin',105,'2023-05-01'),
(6,'Support',106,'2023-06-01');

INSERT INTO emp VALUES
(101,'Amit','2000-01-01','Mumbai',20000,NULL,1),
(102,'Rahul','1999-02-02','Pune',25000,101,2),
(103,'Neha','2001-03-03','Delhi',15000,101,1),
(104,'Priya','2000-04-04','Chennai',30000,102,3),
(105,'Karan','1998-05-05','Nagpur',10000,102,2),
(106,'Riya','2002-06-06','Goa',22000,103,3);

INSERT INTO dept_location VALUES
(1,'Mumbai'),
(1,'Pune'),
(2,'Delhi'),
(3,'Chennai'),
(3,'Bangalore'),
(4,'Hyderabad');

#queries
#1) List department numbers which are located at multiple locations.
select dno from dept_location group by dno having count(dlocation)>1;

#2) List department, its manager and number of employees in the dept. 
select dept.dno, dept.dmgrid, count(*) from emp inner join dept on emp.dno = dept.dno group by dno;

#3) List employees who do not have any manager. 
select * from emp where mgrid is null;

#4) Delete an employee having salary 10000
delete from emp where salary = 10000;

#5)Write a function to calculate annual salary
delimiter $$
create function annual_salary(sal int)
returns int
deterministic
begin
	#sql statements
    declare annual int;
    set annual = sal * 12;
    return annual;
end $$

delimiter ;

select empname,annual_salary(salary) from emp;

#6)Procedure to increase salary by 10% for a department 
delimiter $$
create procedure increase(dept_number int)
begin
	update emp set salary = salary * 1.10 where emp.dno = dept_number;
end $$

delimiter ;

call increase(2);
select * from emp;

#7)Trigger to prevent salary below 10000

#8)Create a View showing employee and department details
create view view1 as
select emp.empname,emp.dno,dept.dname from emp inner join dept on emp.dno = dept.dno;

select * from view1;