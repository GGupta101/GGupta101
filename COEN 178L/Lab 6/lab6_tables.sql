PROMPT Creating BankCust_6, Accounts_6, and Totals_6 Tables
CREATE TABLE BANKCUST_6 (
	custno 		VARCHAR(5) Primary Key,
	custname 	VARCHAR(20),
	street 		VARCHAR(30), 
	city 		VARCHAR(20)
);

CREATE TABLE ACCOUNTS_6 (
	AccountNo 	VARCHAR(5) Primary Key,
	accountType VARCHAR(10), 
	amount 		NUMBER(10,2), 
	custno 		VARCHAR(5),
	CONSTRAINT accounts_fkey FOREIGN Key (custno)REFERENCES BANKCUST_6(custno)
);

CREATE TABLE TOTALS_6 (
	custno 		VARCHAR(5), 
	totalAmount NUMBER(10,2), 
	CONSTRAINT totals_fkey FOREIGN Key (custno)REFERENCES BANKCUST_6(custno)
);

