PROMPT ==========QUESTION 4==========
CREATE OR REPLACE TRIGGER ItemOrder_after_insert_trig
AFTER INSERT
   ON ItemOrder
   FOR EACH ROW
DECLARE
   v_quantity Integer;
BEGIN
   SELECT qty
   INTO v_quantity
   FROM ItemOrder
   WHERE orderNo = 'o1';
END;
/
SHOW ERRORS;
INSERT INTO ItemOrder VALUES ('o1',100);
PROMPT ==========QUESTION 5==========
INSERT INTO Course VALUES (10,'C++');
INSERT INTO Course VALUES (11,'Java');
INSERT INTO Course VALUES (12,'Python');
INSERT INTO Course VALUES (121,'Web');
INSERT INTO Course VALUES (133,'Software Eng');
CREATE OR REPLACE TRIGGER LimitTest
    BEFORE INSERT OR UPDATE ON Course_Prereq
    FOR EACH ROW
DECLARE
     v_MAX_PREREQS CONSTANT INTEGER := 2;
     v_CurNum INTEGER;	
BEGIN
	BEGIN
		SELECT COUNT(*) INTO v_CurNum FROM Course_Prereq 
		WHERE courseNo = :new.CourseNo Group by courseNo;
		EXCEPTION
			WHEN no_data_found THEN
                 DBMS_OUTPUT.put_line('not found');
				 v_CurNum := 0;
	END;	
	if v_curNum > 0 THEN
		IF v_CurNum + 1 > v_MAX_PREREQS THEN
			RAISE_APPLICATION_ERROR(-20000,'Only 2 prereqs for course');
		END IF;
	END IF;	
END;
/
SHOW ERRORS;
INSERT INTO Course_Prereq VALUES (121,11);
INSERT INTO Course_Prereq VALUES (121,10);
SELECT * FROM Course_Prereq;
INSERT INTO Course_Prereq VALUES (121,12);
SELECT * FROM Course_Prereq;
INSERT INTO Course_Prereq VALUES (133,12);
SELECT * FROM Course_Prereq;
UPDATE COURSE_PREREQ SET courseno = 121 WHERE courseno= 133;
SELECT * FROM Course_Prereq;
PROMPT ==========QUESTION 6==========
DELETE FROM Course_Prereq;
CREATE OR REPLACE TRIGGER LimitTest
FOR INSERT OR UPDATE
ON Course_Prereq
COMPOUND TRIGGER
v_MAX_PREREQS CONSTANT INTEGER := 2;
     v_CurNum INTEGER := 1;	
	 v_cno INTEGER;
BEFORE EACH ROW IS
BEGIN
	v_cno := :NEW.COURSENO;
END BEFORE EACH ROW;
AFTER STATEMENT IS
BEGIN
SELECT COUNT(*) INTO v_CurNum FROM Course_Prereq 
		WHERE courseNo = v_cno Group by courseNo;
		IF v_CurNum  > v_MAX_PREREQS THEN
			RAISE_APPLICATION_ERROR(-20000,'Only 2 prereqs for course');
		END IF;
END AFTER STATEMENT;
END ;
/
SHOW ERRORS;
INSERT INTO Course_Prereq values (121,11);
INSERT INTO Course_Prereq values (121,10);
INSERT INTO Course_Prereq values (121,12);
INSERT INTO Course_Prereq values (133,12);
SELECT * FROM Course_Prereq;
UPDATE COURSE_PREREQ SET courseno = 121 WHERE courseno= 133;
SELECT * FROM Course_Prereq;

