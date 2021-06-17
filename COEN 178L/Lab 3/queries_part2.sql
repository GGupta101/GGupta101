SET ECHO ON
PROMPT ----------LAB 3 PART 2----------
PROMPT Part 2 Exercise 7
SELECT deptid AS deptno, COUNT(*) AS empcount FROM L_EMP GROUP BY deptid ORDER BY empcount;
PROMPT Part 2 Exercise 8a
SELECT deptno, deptname, empcount FROM (SELECT deptid AS deptno, COUNT(*) AS empcount FROM L_EMP GROUP BY deptid),L_DEPT WHERE deptno = L_DEPT.deptid;
PROMPT Part 2 Exercise 8b
SELECT deptno, deptname, empcount FROM (SELECT deptid AS deptno, COUNT(*) AS empcount FROM L_EMP GROUP BY deptid),L_DEPT WHERE deptno = L_DEPT.deptid ORDER BY empcount;
PROMPT Part 2 Exercise 9 Attempt 1
SELECT deptid, MAX(COUNT(*)) FROM L_EMP GROUP BY deptid;
PROMPT Part 2 Exercise 9 Attempt 2
SELECT deptid FROM L_EMP GROUP BY deptid HAVING COUNT(*) = (SELECT COUNT(*) FROM L_EMP GROUP BY deptid);
PROMPT Part 2 Exercise 9a
SELECT deptid FROM L_EMP GROUP BY deptid HAVING COUNT(*) = (SELECT MAX(COUNT(*)) FROM L_EMP GROUP BY deptid);
PROMPT Part 2 Exercise 9b
SELECT deptno, deptname, empcount FROM (SELECT deptid AS deptno, COUNT(*) AS empcount FROM L_EMP GROUP BY deptid HAVING COUNT(*) = (SELECT MAX(COUNT(*)) FROM L_EMP GROUP BY deptid)),L_DEPT WHERE deptno = L_DEPT.deptid;
PROMPT Part 2 Exercise 10a
SELECT * FROM L_EMP NATURAL JOIN L_DEPT;
PROMPT Part 2 Exercise 10b
SELECT L_EMP.deptid, empno, empname, deptname FROM L_EMP, L_DEPT WHERE L_EMP.deptid=L_DEPT.deptid;
SET ECHO OFF
