PROMPT ==========QUESTION 1==========
CREATE Or Replace VIEW CurrentProjects AS
SELECT projectid, title, managerid 
FROM Project7
WHERE (enddate-SYSDATE)>0;
CREATE Or Replace VIEW PastProjects AS
SELECT title, managerid 
FROM Project7
WHERE (SYSDATE-enddate)>0;
SELECT * FROM CurrentProjects;
SELECT * FROM PastProjects;
INSERT INTO CurrentProjects VALUES ('p99','Testing','e2');
SELECT * FROM Project7;
INSERT INTO PastProjects VALUES ('Testing','e2');
CREATE Or Replace VIEW ManagedProjects AS
SELECT projectID, title AS Project_Title, empName AS ManagerName
FROM Project7, EMP7
WHERE EMP7.empid = Project7.managerId;
SELECT * FROM ManagedProjects;
INSERT INTO ManagedProjects VALUES ('p88','Design','Mary Mason');
