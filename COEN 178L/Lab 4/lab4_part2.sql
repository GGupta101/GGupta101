PROMPT ==========Part 2 QUESTION 4==========
CREATE OR REPLACE Procedure DisplayMessage(message in varchar)
AS
BEGIN
	DBMS_OUTPUT.put_line('Hello '||message);
END;
/
SHOW Errors;
EXEC DisplayMessage('include a message');
PROMPT ==========Part 2 QUESTION 5==========
SELECT ROUND(DBMS_RANDOM.value (10,100)) FROM DUAL;
CREATE or REPLACE Procedure setSalaries(low in integer, high in integer)
AS
Cursor emp_cur IS
	SELECT * FROM alphacoemp;
	l_emprec emp_cur%rowtype;
	l_salary alphacoemp.salary%type;
BEGIN
	FOR l_emprec IN emp_cur
	loop
		l_salary := ROUND(dbms_random.value(low,high));
		UPDATE alphacoemp SET salary = l_salary WHERE name = l_emprec.name;	 
	END LOOP;
	COMMIT;
END;
/
SHOW errors;
EXEC setSalaries (75000,90000);
SELECT * FROM alphacoemp;
PROMPT ==========Part 2 QUESTION 6==========
SELECT name, salary FROM alphacoemp WHERE salary>=80000 AND salary<90000 ORDER BY name;
PROMPT ==========Part 2 QUESTION 7==========
SELECT * FROM alphacoemp WHERE name='Young';
CREATE or REPLACE Procedure setEmpSalary(p_name in varchar, low in integer, high in integer)
AS
BEGIN
	UPDATE alphacoemp SET salary = ROUND(dbms_random.value(low,high)) WHERE name = p_name;
	COMMIT;
END;
/
SHOW errors;
EXEC setEmpSalary ('Young',95000,100000);
SELECT * FROM alphacoemp WHERE name='Young';
PROMPT ==========Part 2 QUESTION 8==========
Create or Replace FUNCTION getEmpSalary(p_name in VARCHAR)
Return NUMBER IS
	l_salary alphacoemp.salary%type;	
BEGIN
	SELECT salary INTO l_salary FROM AlphaCoEmp WHERE name = p_name;
   	return l_salary;
END;
/
SHOW errors;
SELECT getEmpSalary('Young') FROM Dual;
