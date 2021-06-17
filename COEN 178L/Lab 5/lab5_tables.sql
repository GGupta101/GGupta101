PROMPT Creating AlphaCoEmp, Emp_Work, and EmpStats Tables
CREATE TABLE alphacoemp(
	name 			varchar(25) PRIMARY KEY, 
	title 			varchar(20) DEFAULT NULL, 
	salary			Number(10,2) DEFAULT 0
);
INSERT INTO alphacoemp (name) SELECT DISTINCT last from staff_2010;
CREATE TABLE emp_work(
	name 			varchar(25) PRIMARY KEY, 
	project 		varchar(20) default NULL,
	CONSTRAINT fk_alphaco FOREIGN KEY (name) REFERENCES alphacoemp(name)
);
INSERT INTO emp_work(name) SELECT DISTINCT name FROM alphacoemp WHERE REGEXP_LIKE(name,'(^[gky])','i');
ALTER TABLE emp_work DROP CONSTRAINT fk_alphaco;
ALTER TABLE emp_work ADD CONSTRAINT fk_alphaco FOREIGN KEY (name) REFERENCES alphacoemp(name) ON DELETE CASCADE;
Create table EmpStats (
	title 			VARCHAR(20) Primary KEY,
	empcount 		INTEGER, 
	lastModified 	DATE
); 
