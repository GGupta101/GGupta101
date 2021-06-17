PROMPT Creating and Populating L_EMP and L_DEPT
CREATE TABLE L_EMP(
	empno		integer PRIMARY KEY,
	empname		varchar(10),
	deptid		varchar(5)
);
CREATE TABLE L_DEPT(
	deptid		varchar(5) PRIMARY KEY,
	deptname	varchar(10)
);
insert into L_EMP values(1,'smith','d1');
insert into L_EMP values(2,'jones','d2');
insert into L_EMP values(3,'wayne','d1');
insert into L_EMP values(4,'moor','d3');
insert into L_EMP values(5,'king','d1');
insert into L_EMP values(6,'chen','d1');
insert into L_EMP values(7,'winger','d3');
insert into L_DEPT values('d1','Research');
insert into L_DEPT values('d2','Devt');
insert into L_DEPT values('d3','Testing');
insert into L_DEPT values('d4','Advert');
