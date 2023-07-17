
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

6.Find the ids and names of sailors who have reserved two different boats on the same day.

7.Find the ids of sailors who have reserved a red boat or a green boat.

8.Count the number of different sailor names.

9.Calculate the average age of all sailors.

10.Find sid’s of all sailors who’ve reserved red boat but not green boat.

11.Find the average age of sailors for each rating level that has at least two sailors.

12.Find the names of the sailors who have reserved both a red and a yellow boat.

13.Find the sailor id’s of sailors whose rating is better than some sailor called Bob.

14.List the names of those sailors whose name has only five characters and third alphabet ends with 's'.

15.Find the SID of all sailors who have reserved red boats but not green boats.

16.Find name of salilors that have only 1 boat and is of red color.

17.Find name of sailors that only have red boats and not any other color.
*/
-----------SAILOR TABLE-------
create table sailors
(
sid int primary key,
sname varchar(20),
rating int,
age int
);

----------BOATS TABLE---------
create table boats
(
bid int primary key,
bname varchar(20),
color varchar(20)
);
--------RESERVES----------------
create table reserves
(
sid int,
bid int,
day int,
foreign key (sid) references sailors(sid),
foreign key (bid) references boats(bid)
);
---------INSERTING IN SAILORS------------
INSERT INTO sailors values(10,'nobita',5,19);
INSERT INTO sailors values(20,'doremon',4,25);
INSERT INTO sailors values(30,'sunio',3,30);
INSERT INTO sailors values(40,'gian',1,35);
INSERT INTO sailors values(50,'shizuka',5,18);
INSERT INTO sailors values(60,'dekisuki',4,19);
INSERT INTO sailors values(70,'jaiko',3,10);
INSERT INTO sailors values(80,'dorami',5,15);
INSERT INTO sailors values(90,'doramid',2,16);
--------------INSERTING INTO BOATS---------
INSERT INTO boats values(101,'boat1','green');
INSERT INTO boats values(102,'boat2','red');
INSERT INTO boats values(103,'boat3','blue');
---------------INSERTING INTO RESERVES-------------
INSERT INTO reserves VALUES(10,101,1);
INSERT INTO reserves VALUES(50,101,2);
INSERT INTO reserves VALUES(20,103,3);
INSERT INTO reserves VALUES(30,102,4);
INSERT INTO reserves VALUES(60,102,5);
INSERT INTO reserves VALUES(60,101,5);
INSERT INTO reserves VALUES(40,101,6);
INSERT INTO reserves VALUES(70,103,1);
INSERT INTO reserves VALUES(80,102,1);
INSERT INTO reserves VALUES(10,103,5);
INSERT INTO reserves VALUES(10,102,5);
INSERT INTO reserves VALUES(50,102,4);
INSERT INTO reserves VALUES(90,101,4);


---------------SHOWING VALUES-----------
select * from sailors;
select * from boats;
select * from reserves;
----------LETS WRITE QUERY-------------
-- 3
select * from sailors s,reserves r
where s.sid=r.sid AND r.bid=101;
-------------------------------------------------------------
-- 4
select s.sname from sailors s,boats b, reserves r
where s.sid=r.sid AND b.bid=r.bid AND b.color='red'
order by s.age;
-------------------------------------------------------------
-- 
select s.sname from sailors s, reserves r
where s.sid=r.sid group by s.sid 
---------------------------------------------
-- 5
select s.sname,count(r.bid) from sailors s,reserves r
where s.sid=r.sid 
group by s.sname having count(r.bid)=2;
Select s.sname  from sailors s, reserves r 
where s.sid=r.sid  
group by r.sid 
having count (r.sid) =2;
-- --------------------------------------------
-- 6
-- problem in this part
select s.sid,s.sname from sailors s,reserves r1,reserves r2
where s.sid=r1.sid AND s.sid =r2.sid AND r1.sid!=r2.sid  AND r1.day=r2.day;
-------------------------------------------------------------
-- 7
select s.sid,s.sname,b.color,b.bid from sailors s,boats b,reserves r
where s.sid=r.sid AND b.bid=r.bid AND (b.color='red' OR b.color='green') order by s.sid;
-- syntax 2
select s1.sid,s1.sname,r1.bid from sailors s1,boats b1,reserves r1
where s1.sid=r1.sid AND r1.bid=b1.bid AND b1.color='red'
union
select s2.sid,s2.sname,r2.bid from sailors s2,boats b2,reserves r2
where  s2.sid =r2.sid AND r2.bid=b2.bid AND b2.color='green';
-------------------------------------------------------------
-- 8
select count(distinct s.sname)from sailors s;
-------------------------------------------------------------
-- 9
select avg(age) from sailors;
------------------------------------------------------
-- 10
select s.sid,s.sname,b.color from sailors s,boats b,reserves r
where s.sid=r.sid AND b.bid=r.bid AND b.color!='green'AND b.color='red' ;
-- syntax 2
select s1.sid,s1.sname from sailors s1,boats b1,reserves r1
where s1.sid=r1.sid AND b1.bid=r1.bid AND b1.color='red'
EXCEPT
select s2.sid,s2.sname from sailors s2,boats b2,reserves r2
where s2.sid=r2.sid AND b2.bid=r2.bid AND b2.color='green';
-------------------------------------------------------------------
-- 11
select s1.rating ,avg(s1.age),count(s1.rating)from sailors s1,sailors s2
where s1.sid!=s2.sid AND s1.rating = s2.rating 
group by s1.rating having count(s1.rating)>1;
-- -- syntax 2
select s.rating,avg(s.age) from sailors s
group by s.rating
having count(s.rating)>1;
-------------------------------------------------------------------
-- 12
--problem
select s1.sname from sailors s1,reserves r1,boats b1
where s1.sid=r1.sid and b1.bid = r1.bid and  b1.color='red'
intersect
select s2.sname from sailors s2,reserves r2,boats b2
where s2.sid=r2.sid and b2.bid = r2.bid and  b2.color='blue'
EXCEPT
select s3.sname from sailors s3,reserves r3,boats b3
where s3.sid=r3.sid and b3.bid = r3.bid and  b3.color='green';
-- ------
-- select r.bid from sailors s,reserves r
-- where s.sid=r.sid AND s.sname='dekisuki';
-------------------------------------------------------------------
--13
select s2.sname ,s2.rating from sailors s2 where s2.rating <
(select s1.rating from sailors s1 where s1.sname='jaiko');
-- syntax 2
select s1.sid,s1.sname,s1.rating from sailors s1,sailors s2
where s1.rating > s2.rating AND s2.sname='doramid';
-- ------------------------------------------------------
-- 14
select s.sname from sailors s 
where s.sname like '__b___';
-- syntax 2
select s.sname from sailors s 
where len(s.sname)=5 AND s.sname like '__b%';
-------------------------------------------------------------------
-- 15
select s.sid from sailors s,reserves r,boats b
where s.sid = r.sid and b.bid=r.bid and b.color='red'
EXCEPT
select s1.sid from sailors s1,reserves r1,boats b1
where s1.sid=r1.sid and b1.bid=r1.bid and b1.color='green';
-----------------------------------------------------------------
-- 16
only red boats and only one boat 
select * from sailors s2,reserves r2,boats b2
where s2.sid = r2.sid and b2.bid=r2.bid 
group by s2.sid
having count(r2.bid)=1 and b2.color='red';
-------------------------------------------------------------------
-- 17
name of sailors that have  boats that are only red and not any other color
select * from sailors s2,reserves r2,boats b2
where s2.sid = r2.sid and b2.bid=r2.bid 
group by s2.sid
having count(r2.bid)>=1 and b2.color='red';
-------------------------------------------------------------
