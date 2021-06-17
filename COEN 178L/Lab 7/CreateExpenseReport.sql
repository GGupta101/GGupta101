SET PAGESIZE 40 
SET LINESIZE 120
BREAK ON TODAY
COLUMN TODAY NEW_VALUE report_date
SELECT TO_CHAR(SYSDATE, 'fmMonth DD, YYYY') TODAY
FROM DUAL;
SET termout OFF
ttitle center "Expense Report  "  report_date skip 2
btitle center "Gagan Gupta COEN 178 Lab-7"
spool ExpenseReport.txt
COLUMN category FORMAT a20 heading "Category"
COLUMN price FORMAT $9999999,999 heading "Expense"
BREAK ON category SKIP 1
COMPUTE AVG MAXIMUM SUM OF price ON category
SELECT category, price FROM MyExpenses ORDER BY category;
spool OFF;
CLEAR COLUMNS
CLEAR BREAK
TTITLE OFF 
BTITLE OFF
SET VERIFY OFF 
SET FEEDBACK OFF
SET RECSEP OFF
SET ECHO OFF
