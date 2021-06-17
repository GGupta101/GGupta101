SET ECHO ON
SELECT custid,firstname||' '||lastname AS Fullname,city FROM customer;
SELECT * FROM customer ORDER BY lastname;
SELECT * FROM schedule ORDER BY serviceid ASC, custid DESC;
SELECT serviceid FROM deliveryservice MINUS SELECT serviceid FROM schedule;
SELECT firstname||' '||lastname AS name FROM customer WHERE custid IN (SELECT custid FROM schedule WHERE day='m');
SELECT lastname FROM customer WHERE custid IN (SELECT custid FROM schedule);
SELECT MAX(servicefee) AS Highest_ServiceFee FROM deliveryservice;
SELECT day,COUNT(day) FROM schedule GROUP BY day;
SELECT A.custid,B.custid,A.city FROM customer A, customer B WHERE A.city=B.city AND A.custid<>B.custid;
SELECT C.firstname||' '||C.lastname AS name FROM schedule A, deliveryservice B, customer C WHERE B.location=C.city AND A.serviceid=B.serviceid AND A.custid=C.custid;
SELECT MAX(salary) AS Highest_Salary,MIN(salary) AS Lowest_Salary FROM staff_2010;
SET ECHO OFF

