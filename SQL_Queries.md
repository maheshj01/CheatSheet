### To Create A Database 
```sql
   create database database_name;
```
### create a table
```sql
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
### Inserting a single Row into database 
```
   Insert into table_name(attributes,attributes,....) VALUES('value1','value2',....);
```

e.g

```sql
   Insert into customers(firstName,lastName,zipcode) VALUES('John','Doe','345333');
```

### Inserting Multiple Rows into the Database 

```sql
  Insert into customers(firstName,lastName,zipcode) VALUES
  ('James','Bond','35333'); /* Row 1*/
  ('John','Cena','355333'); /* Row 2*/
  ('Sam','Page','365333'); /* Row 3*/
  ('Larry','Page','365233'); /* Row 4*/
```

### Update a row in the database 

```sql
   Update table_name
   SET attribute = 'value'
   Where condition;
```
   Note: if we dont specify where statement the update is applied to all the rows in 
      the database

  e.g to change the last name of person with id = 3 

```sql
   Update customers
   SET last = 'Billings'
   Where id = 3;
```
### delete a row

```sql
  DELETE from customers
  where id =3;	
```
### ALTER TABLE
  
  1. Used to modify the schema of the table like add/delete column

 *To add a column into the existing table using Alter table query*

```sql
  ALTER table customers ADD email int(100);		
```
  /* To Change datatype of existing column*/
```
   ALTER table customers
   MODIFY COLUMN email VARCHAR(100);
```

*To drop existing column*

```sql 
  ALTER TABLE customers DROP COLUMN email;
```

*SELECT STATEMENT TO RETRIEVE DATA*

  1. To retrieve all data

```sql
   SELECT * from customers;
```

  2. To retrieve limited or specific Columns	

```sql
   SELECT firstName, lastName from customers
```

  3. TO select specific row from table

```sql
   SELECT * from customers where id = 3;
```

  4. To order/sort data by Last Name

```sql
   SELECT * from customers ORDER BY lastName;	
```	

  5. To sort by DESCENDING use DESC and ASC for Ascending

```sql 
   SELECT * from customers ORDER BY lastName DESC; 		
```

*To select all unique firstnames from the database or avoids duplicate occurences *

```sql
   SELECT DISTINCT firstName from customers;
```	
# SQL OPERATORS
```sql
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

```sql
 CREATE INDEX nameindex ON customers(firstName);
```

```sql
 DROP INDEX nameindex ON customers;
```
 
## JOINS 
![](https://www.dofactory.com/Images/sql-joins.png)
Used to combine two or more rows based on some common field between the tables
types of joins :
	a) Inner Join
	b) LEFT JOIN
	c) Right Join
	d) Full Join

1. Inner Join -- returns data from both tables when there is match of specific field

e.g 
```sql
SELECT customers.firstName,customers.lastName,orders.orderNumber
FROM customers
INNER JOIN orders
ON customers.id = orders.orderId
ORDER BY orders.orderNumber
```
2. LEFT JOIN-- returns data from the LEFT TABLE with matching rows from Right table

```SQL
SELECT customers.firstName,customers.lastName,orders.orderNumber,orders.orderDate
from customers
LEFT JOIN orders ON customers.id = orders.customerId
ORDER BY customers.lastName
```

### EXAMPLES OF JOINS

```
________CITY____________ 	_____________COUNTRY______________
FIELD 		TYPE    	FIELD			TYPE
-------------------------	----------------------------------
ID		NUMBER		CODE			VARCHAR2(3)
NAME		VARCHAR(17)	NAME			VARCHAR2(44)
COUNTRYCODE 	VARCHAR(3)	CONTINENT		VARCHAR2(13)
DISTRICT	VARCHAR(20)	REGION			VARCHAR2(25)
POPULATION	NUMBER		SURFACEAREA		NUMBER
				INDEPYEAR		VARCHAR2(5)
				POPULATION		NUMBER
				LIFEEXPECTANCY		VARCHAR2(4)
				GNP			NUMBER
				GNPGOLD			VARCHAR2(9)
				LOCALNAME		VARCHAR2(44)
				GOVERNMENTFORM		VARCHAR2(44)
				HEADOFSTATE		VARCHAR2(32)
				CAPITAL			VARCHAR2(4)			
				CODE2			VARCHAR2(2)
```

1. Given the CITY and COUNTRY tables, 
query the names of all cities where the CONTINENT is 'Africa'. 

```sql
SELECT CITY.NAME
FROM CITY,COUNTRY
WHERE CITY.COUNTRYCODE = COUNTRY.CODE and COUNTRY.CONTINENT='Africa' 
```
or 

```sql
Select City.Name 
From City Inner Join Country 
On CountryCode = Code
Where Continent = 'Africa';
```

2. Given the CITY and COUNTRY tables, 
query the names of all the continents (COUNTRY.Continent) 
and their respective average city populations (CITY.Population) 
rounded down to the nearest integer.

```sql
SELECT COUNTRY.CONTINENT,FLOOR(AVG(CITY.POPULATION))
FROM CITY INNER JOIN COUNTRY
ON COUNTRYCODE=CODE
GROUP BY COUNTRY.CONTINENT 
```

*NOTE: SEEMS LIKE WITH AGGREGATE FUNCTIONS WE NEED A GROUP BY*

3. Ketty gives Eve a task to generate a report containing three columns: 
	Name, Grade and Mark.
- Ketty doesn't want the NAMES of those students who received a grade lower than 8. 
- The report must be in descending order by grade -- i.e. higher grades are entered first. 
  If there is more than one student with the same grade (8-10) assigned to them, 
- order those particular students by their name alphabetically. 
- Finally, if the grade is lower than 8, use "NULL" as their name and list them by their grades in descending order. 
- If there is more than one student with the same grade (1-7) assigned to them, 
  order those particular students by their marks in ascending order.


# Example Queries With Solutions 

#### STATION

```
| FIELD	|TYPE|
|:------:|:-----:|
|ID|NUMBER|
|CITY|VARCHAR2(21)|
|STATE|VARCHAR2(2)|
|LAT_N|NUMBER|
|LONG_W|NUMBER|
```

1.American Cities with population greater than 100000

```sql
SELECT * FROM CITY WHERE COUNTRYCODE=USA and POPULATION >100000
```

2.Query the two cities in STATION with the shortest and longest CITY names, as well as their respective lengths 
(i.e.: number of characters in the name). If there is more than one smallest or largest city, 
choose the one that comes first when ordered alphabetically.

```sql
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

```sql
SELECT DISTINCT CITY 
FROM STATION 
WHERE SUBSTRING(CITY,1,1) IN ('a','e','i','o','u');
```

*Note: SUBSTRING(CITY,1,1) CREATES a substring for city from index 1 to 1*

or Using Regex

```sql
SELECT DISTINCT CITY 
FROM STATION 
WHERE CITY REGEXP "^[aeiou]";
```
*Note: ^ cap denotes beginning with and [] indicates one of a,e,i,o,u*

4. Distinct CITY ending with vowels

```sql
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP "[aeiou]$"
```
or

```sql
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTRING(CITY,length(CITY),length(CITY)) IN('a','e','i','o','u');
```
5. City Begining and ending with Vowels

```sql
select distinct city from station 
where left(city,1) in ('a','e','i','o','u') 
and right(city, 1) in ('a','e','i','o','u')
```
or

```sql
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP "^[aeiou].*[aeiou]$"
```
or

```sql
SELECT DISTINCT CITY
FROM station
WHERE SUBSTRING(CITY,1,1) IN ('a','e','i','o','u') and SUBSTRING(CITY,length(CITY),length(CITY)) IN ('a','e','i','o','u');
```

6. Not begining with Vowels

```sql
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP "^[^aeiou]"
```
or

```sql
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTRING(CITY,1,1) NOT IN ('a','e','i','o','u');
```

7. DISTINCT CITY NOT ENDNING WITH VOWELS

```sql
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

```sql
SELECT CONCAT(NAME,'(',SUBSTRING(OCCUPATION,1,1),')')
FROM OCCUPATIONS
ORDER BY NAME ASC;
```

```sql
select concat('There are a total of ',count(occupation),' ',lower(occupation),'s.') as total
from occupations
group by occupation
order by count(occupation)
```

# output  

```sql
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

### Aggregations 

 CITY
```
| FIELD | TYPE |
|:-----:|:----:|
|ID|NUMBER|
|NAME|VARCHAR(17)|
|COUNTRYCODE|VARCHAR(3)|
|DISTRICT|VARCHAR(20)|
|POPULATION|NUMBER|
```

1. SUM 
e.g Query the total population of all cities in CITY where District is California.

```sql
SELECT SUM(POPULATION)
FROM CITY
WHERE DISTRICT = 'CALIFORNIA'
```

e.g Query the sum of the populations for all Japanese cities in CITY. The COUNTRYCODE for Japan is JPN.

```sql
SELECT SUM(POPULATION)
FROM CITY
WHERE COUNTRYCODE = 'JPN'
```
2. Average
e.g Query the Average population of all cities in CITY where District is California.

```sql
SELECT AVG(POPULATION)
FROM CITY
WHERE DISTRICT = 'CALIFORNIA'
```

3.FLOOR
rounds downs the nearest integer
e.g -> 2.5 => 2
e.g Query the Average population of all cities in CITY round of to nearest Integer

```sql
SELECT FLOOR(AVG(POPULATION))
FROM CITY
```

4.CEIL
rounds Up the nearest integer
e.g -> 2.5 =>3

5. MAX AND MIN
e.g Query the difference between the maximum and minimum populations in CITY.

```sql
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

```sql
  select *
  from employee
  where salary = (select Max(salary) from employee)
```

2. Select highest salary from employee table 

```sql
   select Max(salary) from employee
```
3. select 2nd highest salary from employee table 

```sql
  select Max(saalary)
  from employee
  where salary NOT In (select Max(salary) form employee)
```

4. return Highest Salary,employee name,department name for each department 
```sql
  select e.first_name,e.last_name,e.salary,d.department
  from Employee e,Inner Join Department d ON(e.departmentId=d.DepartmentId)
  where salary IN (select Max(salary) from employee group by department_id)
```
5. select range of employee bases on Id 

```sql
  select * 
  from employee 
  where employee_id between 2000 and 2010
```
6. return Employee name,highest Salary and Department Name 

```sql  
  select e.first_name,e.last_name,e.salary,d.department
  from Employee e,Inner Join Department d ON(e.departmentId=d.DepartmentId)
  where salary IN (select Max(salary) from employee)
```
