-- create a table
CREATE TABLE Worker (

  WORKER_ID  INTEGER PRIMARY KEY NOT NULL,
  FIRST_NAME char(25),
  LAST_NAME char(25),
  SALARY INTEGER(15),
  JOINING_DATE datetime,
  DEPARTMENT char(25)
);
-- insert some values

INSERT INTO Worker VALUES (001, 'Monika', 'Arora',100000,'14-02-20 09.00.00','HR');
INSERT INTO Worker VALUES (002, 'Niharika', 'Verma',80000,'14-06-11 09.00.00','Admin');
INSERT INTO Worker VALUES (003, 'Vishal', 'Verma',300000,'14-06-11 09.00.00','Admin');
INSERT INTO Worker VALUES (004, 'Amitab', 'Verma',500000,'14-06-11 09.00.00','Admin');
INSERT INTO Worker VALUES (005, 'Vivek', 'Verma',500000,'14-06-11 09.00.00','Admin');
INSERT INTO Worker VALUES (006, 'Vipul', 'Verma',200000,'14-06-11 09.00.00','Admin');
INSERT INTO Worker VALUES (007, 'Satish', 'Verma',75000,'14-06-11 09.00.00','Admin');
INSERT INTO Worker VALUES (008, 'Geetika', 'Verma',90000,'14-06-11 09.00.00','Admin');
SELECT 'All Workers' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT * FROM Worker;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Ascending order' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT FIRST_NAME,SALARY FROM Worker ORDER BY SALARY asc;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Descending order' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT FIRST_NAME,SALARY FROM Worker ORDER BY SALARY desc;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Selecting Total count of SALARY ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(SALARY)  FROM Worker;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Selecting Count of distinct SALARY ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY)  FROM Worker;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more than 75000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 75000;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more  than 80000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 80000;

SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more  than 90000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 90000;

SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more  than 100000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 100000;

SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more  than 200000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 200000;

SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more  than 300000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 300000;

SELECT '-------------------------------------------- ' AS message;
SELECT 'Distinct count of salary more  than 500000 ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT COUNT(DISTINCT SALARY) FROM Worker w1 WHERE w1.SALARY >= 500000;

SELECT '-------------------------------------------- ' AS message;


SELECT 'Selecting nth max salary from worker table ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT DISTINCT SALARY,FIRST_NAME
FROM Worker w1
WHERE 2 == (
    SELECT COUNT(DISTINCT SALARY)
    FROM Worker w2
    WHERE w2.SALARY >= w1.SALARY
)
ORDER BY SALARY DESC;
SELECT '-------------------------------------------- ' AS message;
SELECT 'Selecting n max salaries from worker table ' AS message;
SELECT '-------------------------------------------- ' AS message;
SELECT DISTINCT SALARY,FIRST_NAME
FROM Worker w1
WHERE 2 >= (
    SELECT COUNT(DISTINCT SALARY)
    FROM Worker w2
    WHERE w2.SALARY >= w1.SALARY
)
ORDER BY SALARY DESC;
SELECT '-------------------------------------------- ' AS message;
-- OUTPUT 
All Workers
-------------------------------------------- 
1|Monika|Arora|100000|14-02-20 09.00.00|HR
2|Niharika|Verma|80000|14-06-11 09.00.00|Admin
3|Vishal|Verma|300000|14-06-11 09.00.00|Admin
4|Amitab|Verma|500000|14-06-11 09.00.00|Admin
5|Vivek|Verma|500000|14-06-11 09.00.00|Admin
6|Vipul|Verma|200000|14-06-11 09.00.00|Admin
7|Satish|Verma|75000|14-06-11 09.00.00|Admin
8|Geetika|Verma|90000|14-06-11 09.00.00|Admin
-------------------------------------------- 
Ascending order
-------------------------------------------- 
Satish|75000
Niharika|80000
Geetika|90000
Monika|100000
Vipul|200000
Vishal|300000
Amitab|500000
Vivek|500000
-------------------------------------------- 
Descending order
-------------------------------------------- 
Amitab|500000
Vivek|500000
Vishal|300000
Vipul|200000
Monika|100000
Geetika|90000
Niharika|80000
Satish|75000
-------------------------------------------- 
Selecting Total count of SALARY 
-------------------------------------------- 
8
-------------------------------------------- 
Selecting Count of distinct SALARY 
-------------------------------------------- 
7
-------------------------------------------- 
Distinct count of salary more  than equal to 75000 
-------------------------------------------- 
7
-------------------------------------------- 
Distinct count of salary more  than equal to 80000 
-------------------------------------------- 
6
-------------------------------------------- 
Distinct count of salary more  than equal to 90000 
-------------------------------------------- 
5
-------------------------------------------- 
Distinct count of salary more  than equal to 100000 
-------------------------------------------- 
4
-------------------------------------------- 
Distinct count of salary more  than equal to 200000 
-------------------------------------------- 
3
-------------------------------------------- 
Distinct count of salary more  than equal to 300000 
-------------------------------------------- 
2
-------------------------------------------- 
Distinct count of salary more  than equal to  500000 
-------------------------------------------- 
1
-------------------------------------------- 
Selecting nth max salary from worker table 
-------------------------------------------- 
300000|Vishal
-------------------------------------------- 
Selecting n max salaries from worker table 
-------------------------------------------- 
500000|Amitab
500000|Vivek
300000|Vishal
-------------------------------------------- 
