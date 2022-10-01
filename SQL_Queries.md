## To Create A Database 
```
   create database database_name;
```
## create a table
```
   create Table table_name(
    	attribute_name  type,
	attribute_name  type,
	attribute_name  type,
	Primary KEY(attribute_name); /*(optional) */
   );

e.g create Table customers(
	id INT NOT NULL AUTO_INCREMENT,
	firstName VARCHAR(100),
	lastName VARCHAR(100),
	zipcode VARCHAR(10)
	Primary KEY(id); 
    );
```
## Inserting a single Row into database 
```
   Insert into table_name(attributes,attributes,....) VALUES('value1','value2',....);
```
e.g
```
   Insert into customers(firstName,lastName,zipcode) VALUES('John','Doe','345333');
```
## Inserting Multiple Rows into the Database 
 ```
  Insert into customers(firstName,lastName,zipcode) VALUES
  ('James','Bond','35333'); /* Row 1*/
  ('John','Cena','355333'); /* Row 2*/
  ('Sam','Page','365333'); /* Row 3*/
  ('Larry','Page','365233'); /* Row 4*/
```

## Update a row in the database 
```
   Update table_name
   SET attribute = 'value'
   Where condition;
```
   Note: if we dont specify where statement the update is applied to all the rows in 
      the database

  e.g to change the last name of person with id = 3 
```
   Update customers
   SET last = 'Billings'
   Where id = 3;
```
  /* delete a row */
```
  DELETE from customers
  where id =3;	
```
  /* ALTER TABLE */
  
  1. Used to modify the schema of the table like add/delete column

  /* To add a column into the existing table using Alter table query */
```
  ALTER table customers ADD email int(100);		
```
  /* To Change datatype of existing column*/
```
   ALTER table customers
   MODIFY COLUMN email VARCHAR(100);
```
  /* To drop existing column */
```   
  ALTER TABLE customers DROP COLUMN email;
```

  /* SELECT STATEMENT TO RETRIEVE DATA*/

  1. To retrieve all data
```
   SELECT * from customers;
```
  2. To retrieve limited or specific Columns	
```
   SELECT firstName, lastName from customers
```
  3. TO select specific row from table
```
   SELECT * from customers where id = 3;
```
  4. To order/sort data by Last Name
```
   SELECT * from customers ORDER BY lastName;	
```	
  5  To sort by DESCENDING use DESC and ASC for Ascending
```   
   SELECT * from customers ORDER BY lastName DESC; 		
```
 /* To select all unique firstnames from the database or avoids duplicate occurences */
```
   SELECT DISTINCT firstName from customers;
```	
# SQL OPERATORS
```
1. =         ---> equal to    
2. <>        ---> not equal to
3. >         ---> greater than
4. <         ---> less than
5. >=        ---> greater than or equal to
6. <=        ---> less than or equal to
7. BETWEEN   ---> between an inclusive range  e.g SELECT * FROM customers WHERE id Between 1 AND 3;
8. LIKE      ---> to match a pattern or used in searching  e.g SELECT * FROM customers WHERE firstName like '%n'; /*firstname ending with n*/
9. IS OR IS NOT  ---> 	compare to null (missing data)
10. IS NOT DISTINCT FROM ---> is equal to value or both are nulls
11. AS  	----> used to change a field name when viewing results
12. IN 		----> equal to one of multiple possible values e.g SELECT * from customers WHERE state IN ('New York','Massachusetts');  
```
# Indexes
1. To query data faster and efficiently
```
 CREATE INDEX nameindex ON customers(firstName);
```
```
 DROP INDEX nameindex ON customers;
```
 
# JOINS 
![](https://www.dofactory.com/Images/sql-joins.png)
Used to combine two or more rows based on some common field between the tables
types of joins :
	a) Inner Join
	b) LEFT JOIN
	c) Right Join
	d) Full Join

1. Inner Join -- returns data from both tables when there is match of specific field

e.g 
```
SELECT customers.firstName,customers.lastName,orders.orderNumber
FROM customers
INNER JOIN orders
ON customers.id = orders.orderId
ORDER BY orders.orderNumber
```

2. LEFT JOIN-- returns data from the LEFT TABLE with matching rows from Right table
e.g 

```
SELECT customers.firstName,customers.lastName,orders.orderNumber,orders.orderDate
from customers
LEFT JOIN orders ON customers.id = orders.customerId
ORDER BY customers.lastName
```

# Example Queries With Solutions 

#### STATION

| FIELD	|TYPE|
|:------:|:-----:|
|ID|NUMBER|
|CITY|VARCHAR2(21)|
|STATE|VARCHAR2(2)|
|LAT_N|NUMBER|
|LONG_W|NUMBER|


1.American Cities with population greater than 100000
```
SELECT * FROM CITY WHERE COUNTRYCODE=USA and POPULATION >100000
```
2.Query the two cities in STATION with the shortest and longest CITY names, as well as their respective lengths 
(i.e.: number of characters in the name). If there is more than one smallest or largest city, 
choose the one that comes first when ordered alphabetically.
```
SELECT CITY,LENGTH(CITY)
FROM STATION
ORDER BY Length(CITY) ASC ,
CITY ASC LIMIT 1;
SELECT CITY,LENGTH(CITY)
FROM STATION
ORDER BY Length(CITY) DESC ,
CITY DESC LIMIT 1;
```
3.Query the list of CITY names starting with vowels (i.e., a, e, i, o, or u) from STATION. 
Your result cannot contain duplicates.
```
SELECT DISTINCT CITY 
FROM STATION 
WHERE SUBSTRING(CITY,1,1) IN ('a','e','i','o','u');
```
Note: SUBSTRING(CITY,1,1) CREATES a substring for city from index 1 to 1

or Using Regex
```
SELECT DISTINCT CITY 
FROM STATION 
WHERE CITY REGEXP "^[aeiou]";
```
Note: ^ cap denotes beginning with and [] indicates one of a,e,i,o,u

4. Distinct CITY ending with vowels
```
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP "[aeiou]$"
```
or
```
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTRING(CITY,length(CITY),length(CITY)) IN('a','e','i','o','u');
```
5. City Begining and ending with Vowels
```
select distinct city from station 
where left(city,1) in ('a','e','i','o','u') 
and right(city, 1) in ('a','e','i','o','u')
```
or
```
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP "^[aeiou].*[aeiou]$"
```
or
```
SELECT DISTINCT CITY
FROM station
WHERE SUBSTRING(CITY,1,1) IN ('a','e','i','o','u') and SUBSTRING(CITY,length(CITY),length(CITY)) IN ('a','e','i','o','u');
```
6. Not begining with Vowels
```
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP "^[^aeiou]"
```
or
```
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTRING(CITY,1,1) NOT IN ('a','e','i','o','u');
```
7. DISTINCT CITY NOT ENDNING WITH VOWELS
```
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP ".*[^aeiou]$"
```
8. Query an alphabetically ordered list of all names in OCCUPATIONS, immediately followed by
 the first letter of each profession as a parenthetical (i.e.: enclosed in parentheses). 
For example: AnActorName(A), ADoctorName(D), AProfessorName(P), and ASingerName(S).
Query the number of ocurrences of each occupation in OCCUPATIONS. 
Sort the occurrences in ascending order, and output them in the following format: 
There are a total of [occupation_count] [occupation]s.

```
SELECT CONCAT(NAME,'(',SUBSTRING(OCCUPATION,1,1),')')
FROM OCCUPATIONS
ORDER BY NAME ASC;
```
```
select concat('There are a total of ',count(occupation),' ',lower(occupation),'s.') as total
from occupations
group by occupation
order by count(occupation)
```
# output  
```
Aamina(D) 
Ashley(P) 
Belvet(P) 
Britney(P) 
Christeen(S) 
Eve(A) 
Jane(S) 
Jennifer(A) 
Jenny(S) 
Julia(D) 
Ketty(A) 
Kristeen(S) 
Maria(P) 
Meera(P) 
Naomi(P) 
Priya(D) 
Priyanka(P) 
Samantha(A) 
There are a total of 3 doctors. 
There are a total of 4 actors. 
There are a total of 4 singers. 
There are a total of 7 professors. 
```
# Aggregations 
#### CITY
| FIELD | TYPE |
|:-----:|:----:|
|ID|NUMBER|
|NAME|VARCHAR(17)|
|COUNTRYCODE|VARCHAR(3)|
|DISTRICT|VARCHAR(20)|
|POPULATION|NUMBER|


1. SUM 
e.g Query the total population of all cities in CITY where District is California.
```
SELECT SUM(POPULATION)
FROM CITY
WHERE DISTRICT = 'CALIFORNIA'
```
e.g Query the sum of the populations for all Japanese cities in CITY. The COUNTRYCODE for Japan is JPN.
```
SELECT SUM(POPULATION)
FROM CITY
WHERE COUNTRYCODE = 'JPN'
```
2. Average
e.g Query the Average population of all cities in CITY where District is California.
```
SELECT AVG(POPULATION)
FROM CITY
WHERE DISTRICT = 'CALIFORNIA'
```
3.FLOOR
rounds downs the nearest integer
e.g -> 2.5 => 2
e.g Query the Average population of all cities in CITY round of to nearest Integer
```
SELECT FLOOR(AVG(POPULATION))
FROM CITY
```
4.CEIL
rounds Up the nearest integer
e.g -> 2.5 =>3

5. MAX AND MIN
e.g Query the difference between the maximum and minimum populations in CITY.
```
SELECT max(Population)-min(POPULATION)
FROM CITY
```
6. REPLACE
It used to Relace the perticluar character with other character

e.g ->name = 'saurabh' 
      REPLACE(name,'a','')
      at output we get 'surbh'
Question :->https://www.hackerrank.com/challenges/the-blunder/problem

# Most commonly asked queries that people find difficult

1. return employee record with max salary 
```
  select *
  from employee
  where salary = (select Max(salary) from employee)
```
2. Select highest salary from employee table 
```
   select Max(salary) from employee
```
3. select 2nd highest salary from employee table 
```
  select Max(saalary)
  from employee
  where salary NOT In (select Max(salary) form employee)
```
4. return Highest Salary,employee name,department name for each department 
```
  select e.first_name,e.last_name,e.salary,d.department
  from Employee e,Inner Join Department d ON(e.departmentId=d.DepartmentId)
  where salary IN (select Max(salary) from employee group by department_id)
```
5. select range of employee bases on Id 
```
  select * 
  from employee 
  where employee_id between 2000 and 2010
```
6. return Employee name,highest Salary and Department Name 
```  
  select e.first_name,e.last_name,e.salary,d.department
  from Employee e,Inner Join Department d ON(e.departmentId=d.DepartmentId)
  where salary IN (select Max(salary) from employee)
```
