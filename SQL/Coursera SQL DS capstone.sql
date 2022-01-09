--AB

Part 1: Yelp Dataset Profiling and Understanding

1. Profile the data by finding the total number of records for each of the tables below:
	
i. Attribute table = 10000
ii. Business table = 10000
iii. Category table = 10000
iv. Checkin table = 10000
v. elite_years table = 10000
vi. friend table = 10000
vii. hours table = 10000
viii. photo table = 10000
ix. review table = 10000
x. tip table = 10000
xi. user table = 10000

2. Find the total distinct records by either the foreign key or primary key for each table. If two foreign keys are listed in the table, please specify which foreign key.

i. Business = 10000
ii. Hours = 1562
iii. Category = 2643
iv. Attribute = 1115
v. Review = id: 10000,business_id: 8090,user_id: 9581
vi. Checkin = 493
vii. Photo = id: 10000,business_id: 6493
viii. Tip = user_id: 537, business_id: 3979
ix. User = 10000
x. Friend = 11
xi. Elite_years = 2780

Note: Primary Keys are denoted in the ER-Diagram with a yellow key icon.	

3. Are there any columns with null values in the Users table? Indicate "yes," or "no."

Answer:
No

select count(*)
from user
where (id OR name OR review_count OR yelping_since OR useful OR funny OR cool OR fans OR average_stars OR compliment_hot OR compliment_more OR compliment_profile OR compliment_cute OR compliment_list  OR compliment_note  OR compliment_plain OR compliment_cool OR compliment_funny OR compliment_writer OR compliment_photos) IS NULL

4. For each table and column listed below, display the smallest (minimum), largest (maximum), and average (mean) value for the following fields:

i. Table: Review, Column: Stars
min: 1    	max:5		avg: 3.7082
ii. Table: Business, Column: Stars
min: 1		max: 5		avg: 3.6549
iii. Table: Tip, Column: Likes
min: 0		max: 2		avg: 0.0144
iv. Table: Checkin, Column: Count
min: 1		max: 53		avg: 1.9414
v. Table: User, Column: Review_count
min: 0		max: 2000	avg: 24.2995

5. List the cities with the most reviews in descending order:

select city,sum(review_count)as review
from business 
group by city 
order by review desc;

Copy and Paste the Result Below:
+-----------------+--------+
| city            | review |
+-----------------+--------+
| Las Vegas       |  82854 |
| Phoenix         |  34503 |
| Toronto         |  24113 |
| Scottsdale      |  20614 |
| Charlotte       |  12523 |
| Henderson       |  10871 |
| Tempe           |  10504 |
| Pittsburgh      |   9798 |
| Montréal        |   9448 |
| Chandler        |   8112 |
| Mesa            |   6875 |
| Gilbert         |   6380 |
| Cleveland       |   5593 |
| Madison         |   5265 |
| Glendale        |   4406 |
| Mississauga     |   3814 |
| Edinburgh       |   2792 |
| Peoria          |   2624 |
| North Las Vegas |   2438 |
| Markham         |   2352 |
| Champaign       |   2029 |
| Stuttgart       |   1849 |
| Surprise        |   1520 |
| Lakewood        |   1465 |
| Goodyear        |   1155 |
+-----------------+--------+

6. Find the distribution of star ratings to the business in the following cities:

i. Avon

SQL code used to arrive at answer:

SELECT stars,SUM(review_count) as count
FROM business 
WHERE city = 'Avon' 
GROUP BY stars	

Copy and Paste the Resulting Table Below (2 columns – star rating and count):
+-------+-------+
| stars | count |
+-------+-------+
|   1.5 |    10 |
|   2.5 |     6 |
|   3.5 |    88 |
|   4.0 |    21 |
|   4.5 |    31 |
|   5.0 |     3 |
+-------+-------+

ii. Beachwood

SQL code used to arrive at answer:

SELECT stars,SUM(review_count)as count
FROM business 
WHERE city = 'Beachwood' 
GROUP BY stars	

Copy and Paste the Resulting Table Below (2 columns – star rating and count):

+-------+-------+
| stars | count |
+-------+-------+
|   2.0 |     8 |
|   2.5 |     3 |
|   3.0 |    11 |
|   3.5 |     6 |
|   4.0 |    69 |
|   4.5 |    17 |
|   5.0 |    23 |
+-------+-------+

7. Find the top 3 users based on their total number of reviews:
		
SQL code used to arrive at answer:

SELECT id,name,review_count as review
FROM user 
order BY review 
desc limit 3;

Copy and Paste the Result Below:

+------------------------+--------+--------+
| id                     | name   | review |
+------------------------+--------+--------+
| -G7Zkl1wIWBBmD0KRy_sCw | Gerald |   2000 |
| -3s52C4zL_DHRK0ULG6qtg | Sara   |   1629 |
| -8lbUNlXVSoXqaRRiHiSNg | Yuri   |   1339 |
+------------------------+--------+--------+	

8. Does posing more reviews correlate with more fans?
Yes looks like number of fans correlates with review count as well as the time the user has being yelping since.

Please explain your findings and interpretation of the results:

+------------------------+-----------+------+--------------+---------------------+
| id                     | name      | fans | review_count | yelping_since       |
+------------------------+-----------+------+--------------+---------------------+
| -9I98YbNQnLdAmcYfb324Q | Amy       |  503 |          609 | 2007-07-19 00:00:00 |
| -8EnCioUmDygAbsYZmTeRQ | Mimi      |  497 |          968 | 2011-03-30 00:00:00 |
| --2vR0DIsmQ6WfcSzKWigw | Harald    |  311 |         1153 | 2012-11-27 00:00:00 |
| -G7Zkl1wIWBBmD0KRy_sCw | Gerald    |  253 |         2000 | 2012-12-16 00:00:00 |
| -0IiMAZI2SsQ7VmyzJjokQ | Christine |  173 |          930 | 2009-07-08 00:00:00 |
| -g3XIcCb2b-BD0QBCcq2Sw | Lisa      |  159 |          813 | 2009-10-05 00:00:00 |
| -9bbDysuiWeo2VShFJJtcw | Cat       |  133 |          377 | 2009-02-05 00:00:00 |
| -FZBTkAZEXoP7CYvRV2ZwQ | William   |  126 |         1215 | 2015-02-19 00:00:00 |
| -9da1xk7zgnnfO1uTVYGkA | Fran      |  124 |          862 | 2012-04-05 00:00:00 |
| -lh59ko3dxChBSZ9U7LfUw | Lissa     |  120 |          834 | 2007-08-14 00:00:00 |
| -B-QEUESGWHPE_889WJaeg | Mark      |  115 |          861 | 2009-05-31 00:00:00 |
| -DmqnhW4Omr3YhmnigaqHg | Tiffany   |  111 |          408 | 2008-10-28 00:00:00 |
| -cv9PPT7IHux7XUc9dOpkg | bernice   |  105 |          255 | 2007-08-29 00:00:00 |
| -DFCC64NXgqrxlO8aLU5rg | Roanna    |  104 |         1039 | 2006-03-28 00:00:00 |
| -IgKkE8JvYNWeGu8ze4P8Q | Angela    |  101 |          694 | 2010-10-01 00:00:00 |
| -K2Tcgh2EKX6e6HqqIrBIQ | .Hon      |  101 |         1246 | 2006-07-19 00:00:00 |
| -4viTt9UC44lWCFJwleMNQ | Ben       |   96 |          307 | 2007-03-10 00:00:00 |
| -3i9bhfvrM3F1wsC9XIB8g | Linda     |   89 |          584 | 2005-08-07 00:00:00 |
| -kLVfaJytOJY2-QdQoCcNQ | Christina |   85 |          842 | 2012-10-08 00:00:00 |
| -ePh4Prox7ZXnEBNGKyUEA | Jessica   |   84 |          220 | 2009-01-12 00:00:00 |
| -4BEUkLvHQntN6qPfKJP2w | Greg      |   81 |          408 | 2008-02-16 00:00:00 |
| -C-l8EHSLXtZZVfUAUhsPA | Nieves    |   80 |          178 | 2013-07-08 00:00:00 |
| -dw8f7FLaUmWR7bfJ_Yf0w | Sui       |   78 |          754 | 2009-09-07 00:00:00 |
| -8lbUNlXVSoXqaRRiHiSNg | Yuri      |   76 |         1339 | 2008-01-03 00:00:00 |
| -0zEEaDFIjABtPQni0XlHA | Nicole    |   73 |          161 | 2009-04-30 00:00:00 |
+------------------------+-----------+------+--------------+---------------------+
	
9. Are there more reviews with the word "love" or with the word "hate" in them?

Answer:

Love: 1780 while Hate:232

SELECT count(*)
FROM review 
where text like '%love%'

SELECT count(*)
FROM review 
where text like '%hate%'

10. Find the top 10 users with the most fans:

SQL code used to arrive at answer:

SELECT id,name,fans
FROM user 
ORDER BY fans desc
LIMIT 10;


Copy and Paste the Result Below:

+------------------------+-----------+------+
| id                     | name      | fans |
+------------------------+-----------+------+
| -9I98YbNQnLdAmcYfb324Q | Amy       |  503 |
| -8EnCioUmDygAbsYZmTeRQ | Mimi      |  497 |
| --2vR0DIsmQ6WfcSzKWigw | Harald    |  311 |
| -G7Zkl1wIWBBmD0KRy_sCw | Gerald    |  253 |
| -0IiMAZI2SsQ7VmyzJjokQ | Christine |  173 |
| -g3XIcCb2b-BD0QBCcq2Sw | Lisa      |  159 |
| -9bbDysuiWeo2VShFJJtcw | Cat       |  133 |
| -FZBTkAZEXoP7CYvRV2ZwQ | William   |  126 |
| -9da1xk7zgnnfO1uTVYGkA | Fran      |  124 |
| -lh59ko3dxChBSZ9U7LfUw | Lissa     |  120 |
+------------------------+-----------+------+
	
11. Is there a strong relationship (or correlation) between having a high number of fans and being listed as "useful" or "funny?" Out of the top 10 users with the highest number of fans, what percent are also listed as “useful” or “funny”?

Key:
0% - 25% - Low relationship
26% - 75% - Some relationship
76% - 100% - Strong relationship

SQL code used to arrive at answer:

SELECT name,fans,useful,funny
FROM user 
order by fans desc

+-----------+------+--------+--------+
| name      | fans | useful |  funny |
+-----------+------+--------+--------+
| Amy       |  503 |   3226 |   2554 |
| Mimi      |  497 |    257 |    138 |
| Harald    |  311 | 122921 | 122419 |
| Gerald    |  253 |  17524 |   2324 |
| Christine |  173 |   4834 |   6646 |
| Lisa      |  159 |     48 |     13 |
| Cat       |  133 |   1062 |    672 |
| William   |  126 |   9363 |   9361 |
| Fran      |  124 |   9851 |   7606 |
| Lissa     |  120 |    455 |    150 |
| Mark      |  115 |   4008 |    570 |
| Tiffany   |  111 |   1366 |    984 |
| bernice   |  105 |    120 |    112 |
| Roanna    |  104 |   2995 |   1188 |
| Angela    |  101 |    158 |    164 |
| .Hon      |  101 |   7850 |   5851 |
| Ben       |   96 |   1180 |   1155 |
| Linda     |   89 |   3177 |   2736 |
| Christina |   85 |    158 |     34 |
| Jessica   |   84 |   2161 |   2091 |
| Greg      |   81 |    820 |    753 |
| Nieves    |   80 |   1091 |    774 |
| Sui       |   78 |      9 |     18 |
| Yuri      |   76 |   1166 |    220 |
| Nicole    |   73 |     13 |     10 |
+-----------+------+--------+--------+

Please explain your findings and interpretation of the results:
	
-- There seems to be some correlation between fans, useful and funny. More than half of people with high useful and funny have a high number of fans.

Part 2: Inferences and Analysis

1. Pick one city and category of your choice and group the businesses in that city or category by their overall star rating. Compare the businesses with 2-3 stars to the businesses with 4-5 stars and answer the following questions. Include your code.
	
i. Do the two groups you chose to analyze have a different distribution of hours?
-- The two groups show similar hours.

ii. Do the two groups you chose to analyze have a different number of reviews?
-- Yes the 5 star rated has more reviews than 2-3 star but the sample size is too small for forming conclusions only 4 observations.
         
iii. Are you able to infer anything from the location data provided between these two groups? Explain.
No the location data looks inconclusive.

SELECT 
    c.business_id,
    c.category,
    b.name,
    b.city,
    b.stars,
    b.review_count,
    h.hours
FROM business b 
    INNER JOIN hours h on B.id = H.business_id 
    INNER JOIN category c on b.id=c.business_id 
where (b.city == 'Phoenix' and c.category == 'Food') 
group by b.stars
order by b.stars asc;

2. Group business based on the ones that are open and the ones that are closed. What differences can you find between the ones that are still open and the ones that are closed? List at least two differences and the SQL code you used to arrive at your answer.
		
i. Difference 1:
-- reviews are better for open business. Avg review count of open business 31.75 vs closed 23.19
	
ii. Difference 2:
-- starts are also better Avg star open business: 3.6 vs closed 3.5

SELECT 
    count(id),
    avg(review_count),
    sum(review_count),
    avg(stars),
    is_open
FROM business 
group by is_open;

3. For this last part of your analysis, you are going to choose the type of analysis you want to conduct on the Yelp dataset and are going to prepare the data for analysis.

Ideas for analysis include: Parsing out keywords and business attributes for sentiment analysis, clustering businesses to find commonalities or anomalies between them, predicting the overall star rating for a business, predicting the number of fans a user will have, and so on. These are just a few examples to get you started, so feel free to be creative and come up with your own problem you want to solve. Provide answers, in-line, to all of the following:
	
i. Indicate the type of analysis you chose to do:
-- Lets analyse food categories and their ratings
         
ii. Write 1-2 brief paragraphs on the type of data you will need for your analysis and why you chose that data:
-- I compare german and italian food ratings

iii. Output of your finished dataset:
+-----------+----------+----------------------+-------------------+------------+
| city      | category | Number_Of_Resturants | AVG(review_count) | AVG(stars) |
+-----------+----------+----------------------+-------------------+------------+
| Hemmingen | German   |                    1 |               3.0 |        3.0 |
| Stuttgart | German   |                    1 |              50.0 |        3.0 |
| Mesa      | Italian  |                    1 |             129.0 |        4.0 |
| Montréal  | Italian  |                    1 |              19.0 |        3.0 |
+-----------+----------+----------------------+-------------------+------------+
         
iv. Provide the SQL code you used to create your final dataset:

SELECT b.city, c.category,COUNT(b.name) AS
Number_Of_Resturants,AVG(review_count),AVG(stars)
FROM business b
INNER JOIN category c ON c.business_id = b.id
WHERE c.category IN ("German", "Italian")
GROUP BY b.city, c.category
ORDER BY c.category;

