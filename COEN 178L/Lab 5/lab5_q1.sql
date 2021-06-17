PROMPT ==========QUESTION 1==========
CREATE OR REPLACE Procedure assignJobTitlesAndSalaries 
AS 
type titlesList IS VARRAY(5) OF AlphaCoEmp.title%type; 
type salaryList IS VARRAY(5) OF AlphaCoEmp.salary%type; 
v_titles titlesList; 
v_salaries salaryList; 
Cursor Emp_cur IS SELECT * FROM AlphaCoEmp; 
l_emprec Emp_cur%rowtype; 
l_title AlphaCoEmp.title%type; 
l_salary AlphaCoEmp.salary%type; 
l_randomnumber INTEGER := 1; 
BEGIN 
v_titles := titlesList('advisor', 'director', 'assistant', 'manager', 'supervisor'); 
v_salaries := salaryList(130000, 100000, 600000, 500000, 800000);
FOR l_emprec IN Emp_cur 
LOOP 
l_randomnumber := dbms_random.value(1,5);
l_title := v_titles(l_randomnumber);
l_salary := v_salaries(l_randomnumber); 
UPDATE AlphaCoEmp SET title = l_title WHERE name = l_emprec.name;  
UPDATE AlphaCoEmp SET salary = l_salary WHERE name = l_emprec.name; 
END LOOP; 
COMMIT; 
END; 
/ 
SHOW errors; 
EXEC assignJobTitlesAndSalaries();
SELECT * FROM AlphaCoEmp; 
CREATE OR REPLACE Procedure assignJobTitlesAndSalaries 
AS 
type titlesList IS VARRAY(6) OF AlphaCoEmp.title%type; 
type salaryList IS VARRAY(6) OF AlphaCoEmp.salary%type; 
v_titles titlesList; 
v_salaries salaryList; 
Cursor Emp_cur IS SELECT * FROM AlphaCoEmp; 
l_emprec Emp_cur%rowtype; 
l_title AlphaCoEmp.title%type; 
l_salary AlphaCoEmp.salary%type; 
l_randomnumber INTEGER := 1; 
BEGIN 
v_titles := titlesList('advisor', 'director', 'assistant', 'manager', 'supervisor', 'clerk'); 
v_salaries := salaryList(130000, 100000, 600000, 500000, 800000, 10000);
FOR l_emprec IN Emp_cur 
LOOP 
l_randomnumber := dbms_random.value(1,6);
l_title := v_titles(l_randomnumber);
l_salary := v_salaries(l_randomnumber); 
UPDATE AlphaCoEmp SET title = l_title WHERE name = l_emprec.name;  
UPDATE AlphaCoEmp SET salary = l_salary WHERE name = l_emprec.name; 
END LOOP; 
COMMIT; 
END; 
/ 
SHOW errors; 
EXEC assignJobTitlesAndSalaries();
SELECT * FROM AlphaCoEmp; 
