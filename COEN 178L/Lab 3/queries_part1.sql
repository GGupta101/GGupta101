SET ECHO ON
PROMPT ----------LAB 3 PART 1----------
PROMPT Part 1 Exercise 1 Approach 1
SELECT first||last AS fullname, salary FROM staff_2010 WHERE salary = (SELECT MAX(salary) from Staff_2010);
PROMPT Part 1 Exercise 1 Approach 2
SELECT first||last AS fullname, salary FROM staff_2010 WHERE salary >= ALL(SELECT salary from Staff_2010);
PROMPT Part 1 Exercise 2a
SELECT last, salary FROM staff_2010 WHERE salary = (SELECT salary from staff_2010 WHERE LOWER(last) = 'zichal');
PROMPT Part 1 Exercise 2b
SELECT last, salary FROM staff_2010 WHERE salary = (SELECT salary from staff_2010 WHERE LOWER(last) = 'young');
PROMPT Part 1 Exercise 2b FIXED
SELECT last, salary FROM staff_2010 WHERE salary = ANY (SELECT salary from staff_2010 WHERE LOWER(last) = 'young') ORDER BY salary DESC;
PROMPT Part 1 Exercise 3
SELECT COUNT(salary) AS SALARIES_100K_ABOVE FROM staff_2010 WHERE salary > 100000;
PROMPT Part 1 Exercise 4
SELECT salary, COUNT(salary) AS SALARIES_100K_ABOVE FROM staff_2010 WHERE salary > 100000 GROUP BY salary ORDER BY salary DESC;
PROMPT Part 1 Exercise 5
SELECT salary, salaries_100k_above FROM (SELECT salary, count(salary) AS SALARIES_100K_ABOVE FROM staff_2010 WHERE salary > 100000 GROUP BY salary) WHERE salaries_100k_above>=10 ORDER BY salary DESC;
PROMPT Part 1 Exercise 6
SELECT last FROM staff_2010 WHERE REGEXP_LIKE (last, '([aeiou])\1', 'i');
SET ECHO OFF
