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

----------------------------------------------
SELECT * FROM Customers
WHERE Country IN ('Germany', 'France', 'UK');

SELECT * FROM Customers
WHERE Country IN (SELECT Country FROM Suppliers);

----------------------------------------------
SELECT * FROM Products WHERE Price BETWEEN 10 AND 20;

----------------------------------------------
SELECT CustomerName AS Customer, ContactName AS 'Contact Person'
FROM Customers;

SELECT CustomerName, Address + ', ' + PostalCode + ' ' + City + ', ' + Country AS Address
FROM Customers;

SELECT CustomerName, CONCAT(Address,', ',PostalCode,', ',City,', ',Country) AS Address
FROM Customers;

----------------------------------------------
SELECT Orders.OrderID, Orders.OrderDate, Customers.CustomerName
FROM Customers, Orders
WHERE Customers.CustomerName='Around the Horn' AND Customers.CustomerID=Orders.CustomerID;

SELECT o.OrderID, o.OrderDate, c.CustomerName
FROM Customers AS c, Orders AS o
WHERE c.CustomerName='Around the Horn' AND c.CustomerID=o.CustomerID;

----------------------------------------------
-- A JOIN clause is used to combine rows from two or more tables, based on a related column between them.

The different types of the JOINs in SQL:
(INNER) JOIN: Returns records that have matching values in both tables
LEFT (OUTER) JOIN: Returns all records from the left table, and the matched records from the right table
RIGHT (OUTER) JOIN: Returns all records from the right table, and the matched records from the left table
FULL (OUTER) JOIN: Returns all records when there is a match in either left or right table

SELECT column_name(s)
FROM table1
RIGHT JOIN table2
ON table1.column_name = table2.column_name;

SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
INNER JOIN Customers ON Orders.CustomerID=Customers.CustomerID;

SELECT Orders.OrderID, Customers.CustomerName, Shippers.ShipperName
FROM ((Orders INNER JOIN Customers ON Orders.CustomerID = Customers.CustomerID)
INNER JOIN Shippers ON Orders.ShipperID = Shippers.ShipperID);

----------------------------------------------
SELECT column_name(s) FROM table1
UNION
SELECT column_name(s) FROM table2;

----------------------------------------------
SELECT COUNT(CustomerID), Country
FROM Customers
GROUP BY Country
HAVING COUNT(CustomerID) > 5;

----------------------------------------------
SELECT column_name(s)
FROM table_name
WHERE EXISTS
(SELECT column_name FROM table_name WHERE condition);

----------------------------------------------
SELECT ProductName 
FROM Products
WHERE ProductID = ANY (SELECT ProductID FROM OrderDetails WHERE Quantity = 10);

----------------------------------------------
SELECT * INTO newtable [IN externaldb] FROM oldtable WHERE condition;

INSERT INTO Customers (CustomerName, City, Country)
SELECT SupplierName, City, Country FROM Suppliers
WHERE Country='Germany';

----------------------------------------------
-- The CASE statement goes through conditions and returns a value when the first condition is met (like an if-then-else statement). So, once a condition is true, it will stop reading and return the result. If no conditions are true, it returns the value in the ELSE clause.

CASE
    WHEN condition1 THEN result1
    WHEN condition2 THEN result2
    WHEN conditionN THEN resultN
    ELSE result
END;

SELECT OrderID, Quantity,
    CASE
        WHEN Quantity > 30 THEN 'The quantity is greater than 30'
        WHEN Quantity = 30 THEN 'The quantity is 30'
        ELSE 'The quantity is under 30'
    END AS QuantityText
FROM OrderDetails;

----------------------------------------------
SELECT ProductName, UnitPrice * (UnitsInStock + IFNULL(UnitsOnOrder, 0))
FROM Products;
----------------------------------------------
CREATE PROCEDURE procedure_name 
AS sql_statement
GO;

EXEC sql_statement;


CREATE PROCEDURE SelectAllCustomers @City nvarchar(30)
AS SELECT * FROM Customers WHERE City = @City
GO;

EXEC SelectAllCustomers @City = 'London';

----------------------------------------------
CREATE DATABASE databasename;

DROP DATABASE databasename;

BACKUP DATABASE databasename
TO DISK = 'filepath'
WITH DIFFERENTIAL;

----------------------------------------------
CREATE TABLE Persons (
    PersonID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    CHECK (Age>=18)
);

INSERT INTO Persons (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);

TRUNCATE TABLE Persons;

DROP TABLE Persons;

----------------------------------------------
CREATE TABLE TestTable AS
SELECT customername, contactname
FROM customers;

ALTER TABLE Persons
ADD Birthday DATE;

ALTER TABLE table_name
ADD column_name datatype;

----------------------------------------------
CREATE VIEW [Brazil Customers] AS
SELECT CustomerName, ContactName
FROM Customers
WHERE Country = 'Brazil';

----------------------------------------------

----------------------------------------------

----------------------------------------------

----------------------------------------------

----------------------------------------------
