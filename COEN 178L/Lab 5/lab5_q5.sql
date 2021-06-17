PROMPT ==========QUESTION 5==========
CREATE OR Replace TRIGGER titlecountchange_trig 
AFTER INSERT ON AlphaCoEmp 
FOR EACH ROW 
BEGIN
UPDATE EmpStats SET Empcount = Empcount + 1, lastmodified = SYSDATE WHERE title = :new.title; 
END; 
/ 
SHOW errors; 
INSERT INTO AlphaCoEmp VALUES('mickeymouse','advisor',null);
SELECT * FROM empstats;
