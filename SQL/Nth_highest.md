<h1>Create a Employee Table </h1>

+     CREATE TABLE EmployeePosition (
       EmployeeID INT PRIMARY,
       Salary INT,
       Position VARCHAR(50)
       );
<hr>
<img width="960" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/415f2c76-c0fb-4ceb-a77f-bff135a6c963">
<hr>


<h1>Insert into Employee Table </h1>

+     INSERT INTO EmployeePosition (EmployeeID, Salary, Position) VALUES
       (1, 50000, 'Manager'),
       (2, 60000, 'Engineer'),
       (3, 55000, 'Analyst'),
       (4, 70000, 'Manager'),
       (5, 65000, 'Engineer'),
       (6, 100000, 'Engineer');
<hr>
<img width="958" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/38394fa8-347f-4355-afb8-a24214f697d9">

<img width="960" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/fc2782d5-e9ab-47bb-8ff6-a1e4e0d17f68">

<hr>
<h1>Dropping Table</h1>

+      DROP TABLE IF EXISTS EmployeePosition;
<h1>Sort table according to Salary in descending order</h1>

+     select * from EmployeePosition order by Salary desc;
<hr>
<img width="960" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/fef58eef-7e77-4e12-87a3-82be03bf3c67">
<hr>


<h1>1.Write a query to find the Nth highest salary from the table without using TOP/limit keyword</h1> 
-- esi salary batao jisse koi bada nhi

+      SELECT distinct( Salary ) as maxSalary
       FROM EmployeePosition E1
       WHERE 0 =  (SELECT COUNT(DISTINCT E2.Salary) 
       FROM EmployeePosition E2 
       WHERE E2.Salary > E1.Salary);
   
-- esi salary batao jisse sirf 1 bada hai
+       SELECT distinct( Salary ) as secmaxSalary
        FROM EmployeePosition E1 
        WHERE (SELECT COUNT(DISTINCT E2.Salary) 
        FROM EmployeePosition E2 
        WHERE E2.Salary > E1.Salary) = 1;
 -- esi salary batao jisse sirf 2 bade hai
+       SELECT distinct( Salary ) as secmaxSalary
        FROM EmployeePosition E1 
        WHERE (SELECT COUNT(DISTINCT E2.Salary) 
        FROM EmployeePosition E2 
        WHERE E2.Salary > E1.Salary) = 2;
       
 -- esi salary batao jisse sirf 3 bade hai
+       SELECT distinct( Salary ) as secmaxSalary
        FROM EmployeePosition E1 
        WHERE (SELECT COUNT(DISTINCT E2.Salary) 
        FROM EmployeePosition E2 
        WHERE E2.Salary > E1.Salary) = 3;

-- inner loop tells how many from e2 salary are bigger than the current e1 salary
-- so when we get count = n  means n are greater than that e1 salary 

<hr>
<img width="959" alt="image" src="https://github.com/aditimahabole/DSA-SQL-PYTHON-ALL-TECH-STUFF/assets/78752342/46e631ca-e83b-4651-911a-bd65247a7b0b">
<hr>




