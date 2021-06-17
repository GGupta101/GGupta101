PROMPT ==========QUESTION 4==========
CREATE or REPLACE procedure saveCountByTitle 
AS 
title_count EmpStats.empcount%type;
Cursor Emp_cur IS SELECT DISTINCT title FROM AlphaCoEmp; 
l_emprec Emp_cur%rowtype; 
BEGIN 
DELETE FROM EmpStats;
FOR l_emprec IN Emp_cur 
LOOP 
title_count:=countByTitle(l_emprec.title);
INSERT INTO EmpStats VALUES (l_emprec.title,title_count,SYSDATE);
END LOOP;
END; 
/ 
SHOW errors; 
EXEC saveCountByTitle();
SELECT * FROM empstats;
