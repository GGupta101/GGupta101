PROMPT Creating EMP7, Project7, and EMP_Project Tables 
CREATE TABLE EMP7 (
	empid 		VARCHAR(5) PRIMARY KEY, 
	empName 	VARCHAR(20), 
	deptId 		VARCHAR(5),
	salary 		NUMBER (10,2)
);
CREATE TABLE Project7 (
	projectID VARCHAR(5) PRIMARY KEY, 
	title VARCHAR(20), 
	budget NUMBER(10,2),
	startDate DATE,
	endDate DATE, 
	managerId VARCHAR(5)
);
CREATE TABLE EMP_Project (
	projectID 	VARCHAR(5),
	empid 		VARCHAR(5), 
	commission 	NUMBER(10,2)
);
CREATE TABLE MyExpenses (
	category 	VARCHAR(15), 
	price 		NUMBER(10, 2)
);
CREATE TABLE ItemOrder (
	orderNo 	VARCHAR(5) PRIMARY KEY, 
	qty 		INTEGER
);
CREATE TABLE Course (
    courseNo   INTEGER PRIMARY KEY,
    courseName VARCHAR(20)
);
CREATE TABLE Course_Prereq (
    courseNo   INTEGER ,
    prereqNo Integer,
	CONSTRAINT fk_prereqNo FOREIGN KEY(prereqNo) REFERENCES Course (courseNo)
);
insert into EMP7 values ('e1','J.Smith','d1',100000);
insert into EMP7 values ('e2','M.Jones','d1',120000);
insert into EMP7 values ('e3','D.Clark','d2',200000);
insert into EMP7 values ('e4','G.Gupta','d3',150000);
insert into EMP7 values ('e5','N.Gupta','d2',175000);
insert into  Project7 values ('pj1','Research', 1000000, '10-Jan-2019','20-Feb-2020','e1');
insert into  Project7 values ('pj2','Research', 100000, '10-Feb-2019','20-Apr-2019','e2');
insert into  Project7 values ('pj3','Professional', 150000, '15-Jan-2020','20-Sep-2020','e4');
insert into  Project7 values ('pj4','Professional', 200000, '18-Sep-2020','6-Jan-2021','e5');
insert into  EMP_Project values ('pj2','e2',10000);
insert into  EMP_Project values ('pj3','e4',15000);
insert into  EMP_Project values ('pj1','e1',12500);
