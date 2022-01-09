
/* WEEK 4 WARM-UP
=============================
*/

--STRINGS
SELECT lastname
SUBSTR(lastname,5,7)
FROM employees;

SELECT Company, Name, Company || ' ('|| Name||')'
FROM tablex

--(TRIM, RTRIM, LTRIM))
SELECT TRIM("  SQL Tutorial   ") AS Trimmed;

SELECT UPPER(column_name)
FROM tablex;

--DATE, TIME 

/* SQLite:
DATE()
TIME()
DATETIME()
JULIANDAY()
STRFTIME()
*/

SELECT Birthdate, 
    STRFTIME('%Y', Birthdate) AS Year, 
    STRFTIME('%m', Birthdate) AS Months,
    STRFTIME('%d', Birthdate) AS Year AS Day,
    DATE(('now') - Birthdate) AS Age
FROM employees;

SELECT DATE('now');

SELECT STRTIME('%Y %m %d', 'now');

SELECT STRTIME('%H %M %S %s', 'now'); --now, down to millisec


--CASE

SELECT emplid, fname, lname,
    CASE city 
        WHEN 'Berlin' THEN 'Berlin'
        ELSE 'Other'
    END Berlin
FROM employees
ORDER BY lname, fname;

SELECT trachid, bytes, 
    CASE 
        WHEN bytes < 300000 THEN 'small' --individual rows
        WHEN bytes >= 300001 THEN 'medium'
        WHEN bytes >= 500001 THEN 'large'
        ELSE 'Other'
    END media_size --this will be the new column
FROM tracks;

--VIEWS (not stored, only in mem)

CREATE VIEW my_view AS 
    SELECT 
        x.xxx,
        y.yyy
FROM tablex r
INNER JOIN territories t on x.xxxID = y.yyyID

SELECT * 
FROM my_view --above
DROP VIEW my_view; --remove from mem

-- DATA GOVERNANCE and SANDBOXING




/* WEEK 4 WARM-UP
=============================
*/









/*
WEEK 4 CODING QUIZ
=============================
1. 
*/ 



