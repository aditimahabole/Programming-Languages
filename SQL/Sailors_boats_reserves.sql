-------------------------------------------------------------
/*
Sailors(sid: integer, sname: string, rating: integer, age: real)

Boats(bid: integer, bname: string, color: string)

Reserves(sid: integer, bid: integer, day: date)
----------------------------------------------------------------

1.Create the following Tables with all the constraints.

2.Insert values in the above created tables.

3.Find all information of sailors who have reserved boat number 101.

4.Find the names of sailors who have reserved a red boat, and list in the order of age.

5.Find the names of sailors who have reserved at least one boat.

5.1.Find the names of sailors who have donot have any  reserved  boat.

5.2.Find the names of sailors  and the count of boats only if they have reserved .

5.3.Find the count of boats of all sailors  .

5.4.Find the names of sailors that have 0 boats reserved .

5.5.Find the names of sailors who have reserved 2 boats.

6.Find the ids and names of sailors who have reserved two different boats on the same day.

6.1.Find the ids and names of sailors who have reserved Same boats on the different day.

7.Find the ids of sailors who have reserved a red boat or a green boat.

8.Count the number of different sailor names.

9.Calculate the average age of all sailors.

10.Find sid’s of all sailors who’ve reserved red boat but not green boat.

11.Find the average age of sailors for each rating level that has at least two sailors.

12.Find the names of the sailors who have reserved both a red and a blue boat.

13.Find the sailor id’s of sailors whose rating is better than some sailor called Nobita.

14.List the names of those sailors whose name has only five characters and third alphabet ends with 'i'.

15.Find the SID of all sailors who have reserved red boats but not green boats.

16.Find name of salilors that have only 1 boat and is of red color.

17.Find name of sailors that only have red boats and not any other color.
*/
SELECT '-----SAILORS TABLE----- ' AS message;
create table sailors
(
sid int primary key,
sname varchar(20),
rating int,
age int
);

SELECT '-----BOATS TABLE----- ' AS message;
create table boats
(
bid int primary key,
bname varchar(20),
color varchar(20)
);
SELECT '-----RESERVES TABLE----- ' AS message;
create table reserves
(
sid int,
bid int,
day varchar(20),
foreign key (sid) references sailors(sid),
foreign key (bid) references boats(bid)
);
SELECT '----- INSERT INTO SAILORS TABLE----- ' AS message;

INSERT INTO sailors values(10,'nobita',3,19);
INSERT INTO sailors values(20,'doremon',4,25);
INSERT INTO sailors values(30,'sunio',3,30);
INSERT INTO sailors values(40,'gian',1,35);
INSERT INTO sailors values(50,'shizuka',5,18);
INSERT INTO sailors values(60,'dekisuki',4,19);
INSERT INTO sailors values(70,'jaiko',3,10);
INSERT INTO sailors values(80,'dorami',5,15);
INSERT INTO sailors values(90,'pokemon',2,16);
INSERT INTO sailors values(100,'pikachu',5,5);
 SELECT '----- INSERT INTO BOATS TABLE----- ' AS message;
INSERT INTO boats values(101,'boat1','green');
INSERT INTO boats values(102,'boat2','red');
INSERT INTO boats values(103,'boat3','blue');
SELECT '----- INSERT INTO RESERVES TABLE----- ' AS message;
INSERT INTO reserves VALUES(10,101,'monday');
INSERT INTO reserves VALUES(10,101,'tuesday');
INSERT INTO reserves VALUES(10,101,'wednesday');
INSERT INTO reserves VALUES(20,101,'monday');
INSERT INTO reserves VALUES(30,102,'sunday');
INSERT INTO reserves VALUES(30,103,'saturdy');
INSERT INTO reserves VALUES(50,102,'sunday');
INSERT INTO reserves VALUES(40,103,'sunday');
INSERT INTO reserves VALUES(50,101,'tuesday');
INSERT INTO reserves VALUES(20,103,'wednesday');
INSERT INTO reserves VALUES(30,102,'thursday');
INSERT INTO reserves VALUES(60,102,'friday');
INSERT INTO reserves VALUES(60,101,'friday');
INSERT INTO reserves VALUES(40,101,'saturdy');
INSERT INTO reserves VALUES(40,102,'saturdy');
INSERT INTO reserves VALUES(70,103,'monday');
INSERT INTO reserves VALUES(80,102,'monday');
INSERT INTO reserves VALUES(10,103,'friday');
INSERT INTO reserves VALUES(10,102,'friday');
INSERT INTO reserves VALUES(50,102,'thursday');
-- INSERT INTO reserves VALUES(90,101,4);


SELECT '----- ALL TABLES----- ' AS message;
SELECT 'sid sname rating age ' AS message;
select * from sailors;
SELECT '___________________________________________ ' AS message;
SELECT 'bid bname color ' AS message;
select * from boats;
SELECT '___________________________________________ ' AS message;
SELECT 'sid bid day ' AS message;
select * from reserves;
SELECT '___________________________________________ ' AS message;


SELECT '3.Find all information of sailors who have reserved boat number 101. ' AS message;
select * from sailors s,reserves r
where s.sid=r.sid AND r.bid=101;
SELECT '___________________________________________ ' AS message;

SELECT '4.Find the names of sailors who have reserved a red boat, and list in the order of age.' AS message;
select s.sname from sailors s,boats b, reserves r
where s.sid=r.sid AND b.bid=r.bid AND b.color='red'
order by s.age asc;
SELECT '___________________________________________ ' AS message;

-- TO BE NOTED 
-- ON: The ON clause is used in a join operation (such as INNER JOIN, LEFT JOIN, etc.) 
--     to specify the condition that determines how the tables are related to each other.
-- WHERE: The WHERE clause is used to filter rows based on specific conditions,
--        regardless of whether the tables are joined or not.

SELECT '<<<<<Use of LEFT JOIN in Next Question>>>>' AS message;
SELECT s.sname , r.bid from sailors s LEFT JOIN reserves r ON s.sid == r.sid;
SELECT '___________________________________________ ' AS message;

SELECT '5.Find the names of sailors who have reserved at least one boat.' AS message;
SELECT s.sname from sailors s, reserves r WHERE s.sid==r.sid group by s.sid ;
SELECT '___________________________________________ ' AS message;

SELECT '5.1.Find the names of sailors who have donot have any  reserved  boat.' AS message;
SELECT s.sname
FROM sailors s
LEFT JOIN reserves r ON s.sid = r.sid
WHERE r.sid IS NULL;
SELECT '___________________________________________ ' AS message;

SELECT '5.2.Find the names of sailors  and the count of boats only if they have reserved .' AS message;
select s.sname,count(r.bid) from sailors s,reserves r
where s.sid=r.sid 
group by s.sname ;
-- having count(r.bid)=2;
SELECT '___________________________________________ ' AS message;

SELECT '5.3.Find the count of boats of all sailors .' AS message;
select s.sname,count(r.bid) from sailors s LEFT JOIN reserves r
on s.sid=r.sid 
group by s.sid ;
SELECT '___________________________________________ ' AS message;

SELECT '5.4.Find the names of sailors that have 0 boats reserved .' AS message;
select s.sname,count(r.bid) from sailors s 
LEFT JOIN reserves r
on s.sid=r.sid 
group by s.sid
having count(r.bid) == 0 ;
SELECT '___________________________________________ ' AS message;

SELECT '5.5.Find the names of sailors who have reserved 2 boats.' AS message;
Select s.sname  from sailors s, reserves r 
where s.sid=r.sid  
group by r.sid 
having count (r.sid) =2;
SELECT '___________________________________________ ' AS message;

SELECT '6.Find the ids and names of sailors who have reserved two different boats on the same day.' AS message;
-- select s.sid,s.sname from sailors s,reserves r1,reserves r2
-- where s.sid=r1.sid AND s.sid =r2.sid AND r1.sid!=r2.sid  AND r1.day=r2.day AND r1.bid!=r2.bid;
SELECT s.sname , r1.bid , r1.day
FROM sailors s
JOIN reserves r1 ON s.sid = r1.sid
JOIN reserves r2 ON s.sid = r2.sid
WHERE r1.day = r2.day AND r1.bid != r2.bid ;
SELECT '___________________________________________ ' AS message;

SELECT '6.1.Find the ids and names of sailors who have reserved Same  boats on the different day.' AS message;
-- select s.sid,s.sname from sailors s,reserves r1,reserves r2
-- where s.sid=r1.sid AND s.sid =r2.sid AND r1.sid!=r2.sid  AND r1.day=r2.day AND r1.bid=r2.bid;
SELECT s.sid, s.sname , r1.bid, r1.day
FROM sailors s
JOIN reserves r1 ON s.sid = r1.sid
JOIN reserves r2 ON s.sid = r2.sid
WHERE r1.day != r2.day AND r1.bid = r2.bid group by r1.day ;
SELECT '___________________________________________ ' AS message;

SELECT '7.Find the ids of sailors who have reserved a red boat or a green boat.' AS message;
select s.sid,s.sname,r.bid from sailors s,boats b,reserves r
where s.sid=r.sid AND b.bid=r.bid AND (b.color='red' OR b.color='green') order by s.sid,r.bid,b.color;
SELECT '___________________________________________ ' AS message;
SELECT 'Syntax 2 for 7. ' AS message;
select s1.sid,s1.sname,r1.bid from sailors s1,boats b1,reserves r1
where s1.sid=r1.sid AND r1.bid=b1.bid AND b1.color='red'
union
select s2.sid,s2.sname,r2.bid from sailors s2,boats b2,reserves r2
where  s2.sid =r2.sid AND r2.bid=b2.bid AND b2.color='green';
SELECT '___________________________________________ ' AS message;
SELECT '8.Count the number of different sailor names. ' AS message;
select count(distinct s.sname)from sailors s;
SELECT '___________________________________________ ' AS message;
SELECT '9.Calculate the average age of all sailors. ' AS message;
select avg(age) from sailors;
SELECT '___________________________________________ ' AS message;
SELECT '10.Find sid’s of all sailors who’ve reserved red boat but not green boat.' AS message;
-- select s.sid,s.sname,b.color from sailors s,boats b,reserves r
-- where  s.sid=r.sid AND b.bid=r.bid AND b.color!='green'AND b.color='red' ;
SELECT s.sid, s.sname
FROM sailors s
JOIN reserves r ON s.sid = r.sid
JOIN boats b ON r.bid = b.bid
WHERE b.color = 'red'
AND s.sid NOT IN (
    SELECT s.sid
    FROM sailors s
    JOIN reserves r ON s.sid = r.sid
    JOIN boats b ON r.bid = b.bid
    WHERE b.color = 'green'
  ) 
group by s.sname 
order by s.sid;
SELECT '___________________________________________ ' AS message;

SELECT 'Syntax 2 for 10.' AS message;
select s1.sid,s1.sname from sailors s1,boats b1,reserves r1
where s1.sid=r1.sid AND b1.bid=r1.bid AND b1.color='red'
EXCEPT
select s2.sid,s2.sname from sailors s2,boats b2,reserves r2
where s2.sid=r2.sid AND b2.bid=r2.bid AND b2.color='green';
SELECT '___________________________________________ ' AS message;

SELECT '11.Find the average age of sailors for each rating level that has at least two sailors.' AS message;
select s1.rating ,avg(s1.age) from sailors s1,sailors s2
where s1.sid!=s2.sid AND s1.rating = s2.rating 
group by s1.rating having count(s1.rating)>1;
SELECT '___________________________________________ ' AS message;

SELECT 'Syntax 2 for 11.' AS message;
select s.rating,avg(s.age) from sailors s
group by s.rating
having count(s.rating)>1;
SELECT '___________________________________________ ' AS message;

SELECT '12.Find the names of the sailors who have reserved both a red and a blue boat.' AS message;
select s1.sname from sailors s1,reserves r1,boats b1
where s1.sid=r1.sid and b1.bid = r1.bid and  b1.color='red'
intersect
select s2.sname from sailors s2,reserves r2,boats b2
where s2.sid=r2.sid and b2.bid = r2.bid and  b2.color='blue'
EXCEPT
select s3.sname from sailors s3,reserves r3,boats b3
where s3.sid=r3.sid and b3.bid = r3.bid and  b3.color='green';
SELECT '___________________________________________ ' AS message;
SELECT '13.Find the sailor id’s of sailors whose rating is better than some sailor called Nobita.' AS message;
select s2.sname ,s2.rating from sailors s2 where s2.rating >
(select s1.rating from sailors s1 where s1.sname='nobita');
SELECT '___________________________________________ ' AS message;
SELECT 'Syntax 2 for 13. ' AS message;
select s1.sid,s1.sname,s1.rating from sailors s1,sailors s2
where s1.rating > s2.rating AND s2.sname='nobita';
SELECT '___________________________________________ ' AS message;

SELECT '14.List the names of those sailors whose name has only five characters and third alphabet ends with i' AS message;
select s.sname from sailors s 
where s.sname like '__i__';
SELECT '___________________________________________ ' AS message;

SELECT '15.Find the SID of all sailors who have reserved red boats but not green boats.' AS message;
select s.sid from sailors s,reserves r,boats b
where s.sid = r.sid and b.bid=r.bid and b.color='red'
EXCEPT
select s1.sid from sailors s1,reserves r1,boats b1
where s1.sid=r1.sid and b1.bid=r1.bid and b1.color='green';
SELECT '___________________________________________ ' AS message;

SELECT '16.Find name of salilors that have only 1 boat and is of red color.' AS message;
-- only red boats and only one boat 
select * from sailors s2,reserves r2,boats b2
where s2.sid = r2.sid and b2.bid=r2.bid 
group by s2.sid
having count(r2.bid)=1 and b2.color='red';
SELECT '___________________________________________ ' AS message;

SELECT '17.Find name of sailors that only have red boats and not any other color.' AS message;
-- name of sailors that have  boats that are only red and not any other color
select * from sailors s2,reserves r2,boats b2
where s2.sid = r2.sid and b2.bid=r2.bid 
group by s2.sid
having count(r2.bid)>=1 and b2.color='red';
SELECT '___________________________________________ ' AS message;
