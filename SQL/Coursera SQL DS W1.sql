/*
WEEK 1 WARM-UP
=============================
*/
SELECT * FROM Artists;
-----------------------------
SELECT Playlistid, Name
FROM Playlists;
-----------------------------
SELECT CustomerId,
    InvoiceDate, 
    BillingCity 
FROM Invoices;
-----------------------------
Select FirstName,
    LastName, 
    Email, 
    Phone
From Customers;
-----------------------------
Select TrackId, 
    GenreId, 
    Composer, 
    UnitPrice 
From Tracks
ORDER BY UnitPrice DESC;
-----------------------------
Select * From Playlist_track 
Limit 10;
-----------------------------

/*
WEEK 1 CODING QUIZ
=============================
1. Retrieve all the records from the Employees table. What is Robert King's mailing address? Note: You will have to scroll to the right in order to see it. 
*/ 
SELECT * 
FROM employees 
WHERE LastName = 'King'

/* 
Retrieve the FirstName, LastName, Birthdate, Address, City, and State from the Employees table.
Which of the employees listed below has a birthdate of 3-3-1965?
*/
SELECT FirstName, LastName, Birthdate, Address, City, State 
FROM employees

/*
Retrieve all the columns from the Tracks table, but only return 20 rows. What is the runtime in milliseconds for the 5th track, entitled "Princess of the Dawn"? Note: 
*/
SELECT * 
FROM tracks 
WHERE name = 'Princess of the Dawn'
