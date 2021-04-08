SELECT - extracts data from a database
UPDATE - updates data in a database
DELETE - deletes data from a database
INSERT INTO - inserts new data into a database
CREATE DATABASE - creates a new database
ALTER DATABASE - modifies a database
CREATE TABLE - creates a new table
ALTER TABLE - modifies a table
DROP TABLE - deletes a table
CREATE INDEX - creates an index (search key)
DROP INDEX - deletes an index


-----------------------------------------------
SELECT * FROM Customers
WHERE Country='Germany' AND City='Berlin';

SELECT * FROM Customers
WHERE Country LIKE 'Germany';

SELECT Count(*) AS DistinctCountries
FROM (SELECT DISTINCT Country FROM Customers);

----------------------------------------------
SELECT * FROM Customers
WHERE City='Berlin' OR City='München';

SELECT (COUNT(*))FROM Customers
WHERE City='Berlin' OR City='München';

-----------------------------------------------
SELECT * FROM Customers ORDER BY City DESC;

SELECT * FROM Customers ORDER BY Country, City;

SELECT * FROM Customers ORDER BY Country ASC, CustomerName DESC;

SELECT * FROM Customers WHERE PostalCode is null;

----------------------------------------------
INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
VALUES ('Cardinal', 'Tom B. Erichsen', 'Skagen 21', 'Stavanger', '4006', 'Norway');

----------------------------------------------
UPDATE Customers SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
WHERE CustomerID = 1;

UPDATE Customers SET ContactName='Juan' WHERE Country='Mexico';

UPDATE Customers SET City = 'Oslo', Country = 'Norway'
WHERE CustomerID = 32;

----------------------------------------------
DELETE FROM Customers WHERE CustomerName='Alfreds Futterkiste';

----------------------------------------------
SELECT * FROM Customers LIMIT 3;    //mySQL

SELECT * FROM Customers WHERE Country='Germany' LIMIT 3;

----------------------------------------------
SELECT MIN(Price) AS SmallestPrice FROM Products; 

SELECT COUNT(*) FROM Products WHERE Price = 18;

----------------------------------------------
SELECT * FROM Customers WHERE City NOT LIKE 'a%';

SELECT * FROM Customers WHERE City LIKE '[!bsp]%';

'a%'	Finds any values that start with "a"
'%a'	Finds any values that end with "a"
'%or%'	Finds any values that have "or" in any position
'_r%'	Finds any values that have "r" in the second position
'a_%'	Finds any values that start with "a" and are at least 2 characters in length
'a__%'	Finds any values that start with "a" and are at least 3 characters in length
'a%o'	Finds any values that start with "a" and ends with "o"


