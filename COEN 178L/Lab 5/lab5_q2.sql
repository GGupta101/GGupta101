PROMPT ==========QUESTION 2==========
CREATE OR REPLACE Function calcSalaryRaise(p_name IN AlphaCoEmp.name%type, percentRaise IN NUMBER) 
RETURN NUMBER IS 
l_salary AlphaCoEmp.salary%type; 
l_raise AlphaCoEmp.salary%type; 
l_cnt Integer; 
BEGIN 
SELECT salary INTO l_salary FROM AlphaCoEmp WHERE name = p_name; 
l_raise := l_salary * (percentRaise/100.0); 
SELECT COUNT(*) INTO l_cnt FROM Emp_Work WHERE name = p_name; 
if l_cnt >= 1 THEN 
l_raise := l_raise + 1000; 
END IF; 
return l_raise;
END; 
/ 
SHOW Errors;
SELECT name, title, salary CURRENTSALARY, (trunc(calcSalaryRaise(name,2))+salary) NEWSALARY 
FROM AlphaCoEmp WHERE upper(name) = upper('Young'); 

