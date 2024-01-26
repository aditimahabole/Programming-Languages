<h4>Create EmployeeInfo Table</h4>

+     CREATE TABLE EmployeeInfo (
      EmpID INT,
      EmpFname VARCHAR(50),
      EmpLname VARCHAR(50),
      Department VARCHAR(50),
      Project VARCHAR(50),
      Address VARCHAR(100),
      DOB DATE,
      Gender CHAR(1)
       );

<h4>Insert into EmployeeInfo Table</h4>

+      INSERT INTO EmployeeInfo (EmpID, EmpFname, EmpLname, Department, Project, Address, DOB, Gender) VALUES
      (1, 'Sanjay', 'Mehra', 'HR', 'P1', 'Hyderabad(HYD)', '1976-12-01', 'M'),
      (2, 'Ananya', 'Mishra', 'Admin', 'P2', 'Delhi(DEL)', '1968-05-02', 'F'),
      (3, 'Rohan', 'Diwan', 'Account', 'P3', 'Mumbai(BOM)', '1980-01-01', 'M'),
      (4, 'Sonia', 'Kulkarni', 'HR', 'P1', 'Hyderabad(HYD)', '1992-05-02', 'F'),
      (5, 'Ankit', 'Kapoor', 'Admin', 'P2', 'Delhi(DEL)', '1994-07-03', 'M');
<hr>
  <img width="342" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/2c7d3cc7-31ff-4ea5-9b85-5dea35462a81">

  <img width="342" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/1cfa8630-f2d9-48e0-8c34-10d6500a653b">
<hr>

<h4>Create EmployeePosition Table</h4>

      CREATE TABLE EmployeePosition (
      EmpID INT,
      EmpPosition VARCHAR(50),
      DateOfJoining DATE,
      Salary INT
      );

<h4>Insert Into EmployeePosition Table</h4>

      INSERT INTO EmployeePosition (EmpID, EmpPosition, DateOfJoining, Salary) VALUES
      (1, 'Manager', '2024-05-01', 500000),
      (2, 'Executive', '2024-05-02', 75000),
      (3, 'Manager', '2024-05-01', 90000),
      (2, 'Lead', '2024-05-02', 85000),
      (1, 'Executive', '2024-05-01', 300000);
  <hr>

  <img width="342" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/3e77e17a-4aa7-4fa1-9b14-2ca38e7f8d5e">

  <img width="919" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/19ed5acb-f0f9-4499-b8a6-dcdd0770a79f">

  <hr>
  <h4> Write a query to fetch the EmpFname from the EmployeeInfo table in upper case and use the ALIAS name as EmpName.</h4>

        select UPPER(EmpFname) as Ename from EmployeeInfo;
<hr>
<img width="591" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/4b1644c1-6129-4c6e-b580-7533ddaa1f7c">
<hr>
<h4>Write a query to fetch the number of employees working in the department ‘HR’.</h4>
<li>HR only </li>
  
      select count(EmpID) as HRcount from EmployeeInfo
      where Department = 'HR' 
      group by Department ;
<li>Admin only</li>

      select count(EmpID) as Admincount from EmployeeInfo
      where Department = 'Admin' 
      group by Department ;
 <li>Account only</li>
 
      select count(EmpID) as Accountcount from EmployeeInfo
      where Department = 'Account' 
      group by Department ;


<hr>
<img width="609" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/e8d25094-4bbb-415a-a975-d25e0558be98">
<hr>
<h4>Show number of employees in each department and they should be sorted in descending order by salary and ascending by Department name</h4>

      select count(EmpID) as NoOfEmp , Department
      from EmployeeInfo
      group by Department
      order by NoOfEmp desc , Department asc;
<hr>
<img width="588" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/60399cac-39e0-4baf-a7e7-4b2482ed4973">
<hr>

<h4>Write a query to retrieve the first four characters of  EmpLname from the EmployeeInfo table.</h4>

       select substring(EmpLname, 1,4) as shortLName
       from EmployeeInfo ;
<hr>
<img width="930" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/5e5ec504-4431-4cda-9ce9-8fa84112e466">
<hr>
<h4>Write a query to fetch only the place name(string before brackets) from the Address column of EmployeeInfo table.</h4>
<li>In SQL server </li>

      select substring(Address , 1 ,CHARINDEX('(' , Address) - 1 )
      as CityName 
      from EmployeeInfo ;

<li>In MySQL server you can use below one </li>

      SELECT MID(Address, 0, LOCATE('(',Address))
      FROM EmployeeInfo;

<hr>
<img width="921" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/0188e8ad-f352-42e3-aeda-2dec2b233adb">
<hr>
<h4> Write a query to create a new table which consists of data and structure copied from the other table.</h4>

      create table MynewTable as
      Select * from EmployeeInfo
      where 1 = 0;
<br>
<li>1 = 0 will be false so nothing will be selected from EmployeeInfo means we copied structure same as EmployeeInfo in MynewTable and not its data</li>
<br>

      create table OtherMynewTable as
      Select * from EmployeeInfo
      where 1 = 1;
<br>
<li>Data will also be copied along with structure</li>
<hr>
<img width="650" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/ca700729-a0ff-4197-bc6c-deda75cc130b">

<img width="650" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/9fff3172-3f3a-4402-af1e-2dc9cf51335c">

<hr>

<h4>Write q query to find all the employees whose salary is between 50000 to 100000.</h4>

      select * from EmployeePosition 
      where Salary
      BETWEEN '50000' AND '100000';
<br>
<hr>
<img width="765" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/cc02cb2a-8bb7-4f0f-8057-3c97058a9ecf">
<hr>


<h4> Write a query to find the names of employees that begin with ‘S’</h4>

      select * from EmployeeInfo
      where EmpFname 
      LIKE 'S%';
      
+ Using Substring
  
      SELECT EmpFname, EmpLname
      FROM EmployeeInfo
      WHERE SUBSTRING(EmpFname,1, 1) = 'S';      
<br>
<hr>
<img width="765" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/cc02cb2a-8bb7-4f0f-8057-3c97058a9ecf">
<hr>
<h4>Names of employees having last letter as n or anything you want</h4>

      SELECT EmpFname, EmpLname , LENGTH(EmpFname) as len
      FROM EmployeeInfo
      WHERE SUBSTRING(EmpFname, LENGTH(EmpFname), LENGTH(EmpFname)) = 'n' ;
<hr>
<img width="710" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/16482e62-a001-4ef9-91ee-3cd82aecc6a1">
<hr>
<h4>Write a query to fetch top N records. IMPORTANT </h4>

      SELECT * FROM EmployeePosition ORDER BY Salary DESC LIMIT 3;

<li>Second method IMPORTANT</li>

+ Top Two salary
+ The inner query tells us that how many salary in e2 are greater than e1 and if it is < 2 then we return 
+ 4th from first means 3 salary are more than that salary
+ 3rd from first means 2 salary are more than that salary
+ 2nd from first means 1 salary is more than that salary
+ 1st from first means no salary is greater than that salary
+ So we will calculate how many salaries of e2 are '>' Greater than e1 table salary

 
       SELECT e1.Salary FROM EmployeePosition e1
       WHERE 
       (SELECT COUNT(DISTINCT Salary) 
       FROM EmployeePosition e2
       WHERE e2.Salary>e1.Salary
       ) < 2
       order by e1.Salary desc;

+ top 2 : esi salary batao jisse ya to 1 badi koi present ho ya fir koi bhi badi present na ho
+ 90,000 se sirf 2 badi hai count = 2 to ye nhi aaegi result me
+ 3,00,000 se sirf ek hi badi salary hai 5,00,000 count = 1
+ 5,00,000 se bada koi nhi count = 0
<hr>
<img width="783" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/49dd05d8-43fe-40f2-9dc7-36b370796591">
<hr>


+ Top Three salary
+ top 3 : esi salary batao jisse ya to 3 badi koi present ho ya jisse 2 bai ho ya fir koi bhi badi present na ho
+ 90,000 se sirf 2 badi hai count = 2
+ 3,00,000 se sirf ek hi badi salary hai 5,00,000 count = 1
+ 5,00,000 se bada koi nhi count = 0
  
      SELECT e1.Salary FROM EmployeePosition e1
      WHERE 
      (SELECT COUNT(DISTINCT Salary) 
       FROM EmployeePosition e2
       WHERE e2.Salary>e1.Salary
       ) < 3
       order by e1.Salary desc;
<hr>
<img width="785" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/56148655-ed43-471d-aa70-c5d0406f001e">
<hr>
<h4>Top n Salaries from Last / Last N salaries</h4>
+ Top n Salaries from last
- Top 2 Salary from last 
- The inner query tells us that how many salary in e2 are less than e1 and if it is < 2 then we return 
- 4th from last mean 3 salary are less than that salary
- 3rd from last means 2 salary are smaller than that salary
- 2nd from last means only 1 is smaller than that salary
- 1st from last means no salary is smaller than that salary
- So we will calculate how many salaries of e2 are smaller '<' than e1 table salary

      SELECT e1.Salary FROM EmployeePosition e1
      WHERE 
      (SELECT COUNT(DISTINCT Salary) 
       FROM EmployeePosition e2
       WHERE e2.Salary<e1.Salary
       ) < 2
       order by e1.Salary desc;
 - esi salary batao jisse 1 ya 0 chote salary chote ho
 - 85000 se ek choti salary hai ie 75000 so ye aaega
 - 75000 se ek bhi chota nhi hai count = 0 <2 hai so ye bhi aaega
 - For Top N we use e2>e1 and for Last N we use e2<e1 Just a Trick to remember
<hr>
<img width="757" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/570c513c-6e75-4db0-8e29-97fde22a6ba9">
<hr>

 
 










