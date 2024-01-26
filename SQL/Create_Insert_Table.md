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




