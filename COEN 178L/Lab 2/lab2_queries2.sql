SET ECHO ON
SELECT empname FROM L_EMP,L_DEPT WHERE L_EMP.deptid=L_DEPT.deptid AND L_DEPT.deptname='Testing';
SET ECHO OFF

