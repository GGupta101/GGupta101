PROMPT ==========QUESTION 6==========
DROP TRIGGER titlecountchange_trig; 
CREATE OR Replace TRIGGER countchange_trig 
AFTER INSERT OR DELETE ON AlphaCoEmp 
FOR EACH ROW 
BEGIN 
IF DELETING THEN 
UPDATE EmpStats 
SET Empcount = Empcount -1, lastmodified = SYSDATE WHERE title = :old.title; 
END IF; 
IF Inserting THEN 
UPDATE EmpStats SET Empcount = Empcount + 1, lastmodified = SYSDATE WHERE title = :new.title; 
END IF; 
END;
/ 
Show errors; 
DELETE FROM alphacoemp WHERE name='mickeymouse';
SELECT * FROM empstats;
