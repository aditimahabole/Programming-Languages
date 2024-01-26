<h2>Create EmployeeInfo Table</h2>

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

<h2>Insert into EmployeeInfo Table</h2>

+      INSERT INTO EmployeeInfo (EmpID, EmpFname, EmpLname, Department, Project, Address, DOB, Gender) VALUES
      (1, 'Sanjay', 'Mehra', 'HR', 'P1', 'Hyderabad(HYD)', '1976-12-01', 'M'),
      (2, 'Ananya', 'Mishra', 'Admin', 'P2', 'Delhi(DEL)', '1968-05-02', 'F'),
      (3, 'Rohan', 'Diwan', 'Account', 'P3', 'Mumbai(BOM)', '1980-01-01', 'M'),
      (4, 'Sonia', 'Kulkarni', 'HR', 'P1', 'Hyderabad(HYD)', '1992-05-02', 'F'),
      (5, 'Ankit', 'Kapoor', 'Admin', 'P2', 'Delhi(DEL)', '1994-07-03', 'M');

<h2>Create EmployeePosition Table</h2>

+     CREATE TABLE EmployeePosition (
      EmpID INT,
      EmpPosition VARCHAR(50),
      DateOfJoining DATE,
      Salary INT
      );

<h2>Insert Into EmployeePosition Table</h2>

+     INSERT INTO EmployeePosition (EmpID, EmpPosition, DateOfJoining, Salary) VALUES
      (1, 'Manager', '2024-05-01', 500000),
      (2, 'Executive', '2024-05-02', 75000),
      (3, 'Manager', '2024-05-01', 90000),
      (2, 'Lead', '2024-05-02', 85000),
      (1, 'Executive', '2024-05-01', 300000);
  <hr>
  <img width="342" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/2c7d3cc7-31ff-4ea5-9b85-5dea35462a81">

  <img width="342" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/1cfa8630-f2d9-48e0-8c34-10d6500a653b">

  <img width="342" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/3e77e17a-4aa7-4fa1-9b14-2ca38e7f8d5e">

  <img width="919" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/19ed5acb-f0f9-4499-b8a6-dcdd0770a79f">

  <hr>
  <h2> Write a query to fetch the EmpFname from the EmployeeInfo table in upper case and use the ALIAS name as EmpName.</h2>

  +     select UPPER(EmpFname) as Ename from EmployeeInfo;
  <hr>
  <img width="591" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/4b1644c1-6129-4c6e-b580-7533ddaa1f7c">
  <hr>





