PROMPT =====Part 1 QUESTION 1=====
CREATE TABLE alphacoemp(
	name 		varchar(25) PRIMARY KEY, 
	title 		varchar(20) DEFAULT NULL, 
	salary		Number(10,2) DEFAULT 0
);
SET ECHO ON
INSERT INTO alphacoemp (name) SELECT last from staff_2010;
INSERT INTO alphacoemp (name) SELECT DISTINCT last from staff_2010;
SELECT * FROM alphacoemp;
SET ECHO OFF
PROMPT =====Part 1 QUESTION 2=====
CREATE TABLE emp_work(
	name varchar(25) PRIMARY KEY, 
	project varchar(20) default NULL,
	CONSTRAINT fk_alphaco FOREIGN KEY (name) REFERENCES alphacoemp(name)
);
SET ECHO ON
INSERT INTO emp_work(name) SELECT DISTINCT name FROM alphacoemp WHERE REGEXP_LIKE(name,'(^[gky])','i');
SELECT name FROM alphacoemp WHERE REGEXP_LIKE(name,'(^[gky])','i');
DELETE FROM alphacoemp WHERE name='Kumar';
SET ECHO OFF
PROMPT =====Part 1 QUESTION 3=====
SET ECHO ON
ALTER TABLE emp_work DROP CONSTRAINT fk_alphaco;
ALTER TABLE emp_work ADD CONSTRAINT fk_alphaco FOREIGN KEY (name) REFERENCES alphacoemp(name) ON DELETE CASCADE;
DELETE FROM alphacoemp WHERE name='Kumar';
SELECT * FROM emp_work;
SET ECHO OFF
