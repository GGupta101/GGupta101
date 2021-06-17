PROMPT Creating and Populating customer, deliveryservice, and schedule
CREATE TABLE customer(
  	custid		varchar(5),
  	firstname	varchar(10),
  	lastname	varchar(10),
  	city		varchar(10),
	PRIMARY KEY 	(custid)
);
CREATE TABLE deliveryservice(
  	serviceid	varchar(10),
  	item		varchar(15),
  	location	varchar(15),
  	servicefee	decimal(4,2),
  	PRIMARY KEY	(serviceid)
);
CREATE TABLE schedule(
  	serviceid	varchar(10),
  	custid		varchar(5),
  	day			varchar(2)
  	CHECK		(day in ('m','t','w','r','f'))
);
ALTER TABLE schedule ADD FOREIGN KEY (serviceid) REFERENCES deliveryservice(serviceid);
ALTER TABLE schedule ADD FOREIGN KEY (custid) REFERENCES customer(custid);
PROMPT Inserting Base Tuples With Some Additional Tuples
INSERT INTO customer VALUES ('c1','John','Smith','SJ');
INSERT INTO customer VALUES ('c2','Mary', 'Jones','SFO');
INSERT INTO customer VALUES ('a1','Vincent','Chen','SJ');
INSERT INTO customer VALUES ('a12','Greg', 'King','SJ');
INSERT INTO customer VALUES ('c7','James','Bond','LA');
INSERT INTO customer VALUES ('x10','Susan','Blogg','SFO');
INSERT INTO customer VALUES ('g11','Gagan','Gupta','LIV');
INSERT INTO customer VALUES ('n13','Naveen','Gupta','LIV');
INSERT INTO deliveryservice VALUES ('dsg1','grocery','SJ',25.0);
INSERT INTO deliveryservice VALUES ('dsb1','books','SJ',10.0);
INSERT INTO deliveryservice VALUES ('dsm2','movies','LA',10.0);
INSERT INTO deliveryservice VALUES ('dby3','babygoods','SFO',15.0);
INSERT INTO deliveryservice VALUES ('dsg2','grocery','SFO',20.0);
INSERT INTO deliveryservice VALUES ('dg5','greengoods','SFO',30.0);
INSERT INTO deliveryservice VALUES ('dsg3','grocery','LIV',40.0);
INSERT INTO deliveryservice VALUES ('dsm3','grocery','LIV',15.0);
INSERT INTO schedule VALUES ('dsg1','c1','m');
INSERT INTO schedule VALUES ('dsg1','a12','w');
INSERT INTO schedule VALUES ('dby3','x10','f');
INSERT INTO schedule VALUES ('dg5','c1','r');
INSERT INTO schedule VALUES ('dg5','c1','t');
INSERT INTO schedule VALUES ('dg5','c32','t');
INSERT INTO schedule VALUES ('dsg3','g11','m');
INSERT INTO schedule VALUES ('dsm2','c7','r');
SELECT * FROM customer;
SELECT * FROM deliveryservice;
SELECT * FROM schedule;
PROMPT Adding ('dsg','c2','s') Values into schedule
INSERT INTO schedule VALUES ('dsg','c2','s');
PROMPT Adding Additional Tuples 
INSERT INTO customer VALUES ('s15','Shakha','Gupta','LIV');
INSERT INTO deliveryservice VALUES ('dc1','childgoods','SJ',25.50);
INSERT INTO schedule VALUES ('dc1','n13','w');
