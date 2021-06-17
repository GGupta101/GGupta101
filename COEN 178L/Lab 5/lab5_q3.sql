PROMPT ==========QUESTION 3==========
CREATE OR REPLACE Function countByTitle(p_title IN AlphaCoEmp.title%type) 
RETURN NUMBER IS 
l_cnt Integer; 
BEGIN
SELECT count(title) INTO l_cnt FROM AlphaCoEmp GROUP BY title HAVING title=p_title;
return l_cnt; 
END; 
/ 
SHOW Errors;
SELECT countByTitle('director') FROM Dual; 
SELECT countByTitle('advisor') FROM Dual;

