

### First Normal Form (1NF)

#### Definition:
1NF ensures that the values in each column of a table are atomic (indivisible). It eliminates repeating groups and arrays.

#### Rules:
- Each table has a primary key that uniquely identifies each row.
- Each column contains only atomic (indivisible) values.
- Each column contains values of a single type.

#### Example:
Consider a table storing information about students and their enrolled courses:

| StudentID | StudentName | Courses       |
|-----------|-------------|---------------|
| 1         | Alice       | Math, Science |
| 2         | Bob         | History       |

**Non-1NF Table:**
- The "Courses" column contains multiple values.

**1NF Table:**
- Split the repeating groups into separate rows:

| StudentID | StudentName | Course   |
|-----------|-------------|----------|
| 1         | Alice       | Math     |
| 1         | Alice       | Science  |
| 2         | Bob         | History  |

### Second Normal Form (2NF)

#### Definition:
2NF ensures that the table is in 1NF and all non-key attributes are fully functionally dependent on the primary key. It eliminates partial dependencies.

#### Rules:
- The table must be in 1NF.
- All non-key columns must depend on the entire primary key (not just part of it).

#### Example:
Consider a table storing student enrollment information:

| StudentID | CourseID | StudentName | CourseName |
|-----------|----------|-------------|------------|
| 1         | 101      | Alice       | Math       |
| 1         | 102      | Alice       | Science    |
| 2         | 101      | Bob         | Math       |

**Non-2NF Table:**
- The "StudentName" and "CourseName" depend only on part of the composite key (StudentID, CourseID).

**2NF Tables:**
- Decompose into two tables to remove partial dependencies:

1. Student Table:

| StudentID | StudentName |
|-----------|-------------|
| 1         | Alice       |
| 2         | Bob         |

2. Course Table:

| CourseID | CourseName |
|----------|------------|
| 101      | Math       |
| 102      | Science    |

3. Enrollment Table:

| StudentID | CourseID |
|-----------|----------|
| 1         | 101      |
| 1         | 102      |
| 2         | 101      |

### Third Normal Form (3NF)

#### Definition:
3NF ensures that the table is in 2NF and all non-key attributes are not only fully functionally dependent on the primary key but also directly dependent on the primary key, eliminating transitive dependencies.

#### Rules:
- The table must be in 2NF.
- No transitive dependencies (a non-key column cannot depend on another non-key column).

#### Example:
Consider a table storing student, course, and instructor information:

| StudentID | CourseID | InstructorID | InstructorName |
|-----------|----------|--------------|----------------|
| 1         | 101      | 5001         | Prof. Smith    |
| 1         | 102      | 5002         | Prof. Johnson  |
| 2         | 101      | 5001         | Prof. Smith    |

**Non-3NF Table:**
- "InstructorName" depends on "InstructorID", which is a non-key attribute.

**3NF Tables:**
- Decompose into separate tables to remove transitive dependencies:

1. Student Table:

| StudentID | StudentName |
|-----------|-------------|
| 1         | Alice       |
| 2         | Bob         |

2. Course Table:

| CourseID | CourseName |
|----------|------------|
| 101      | Math       |
| 102      | Science    |

3. Instructor Table:

| InstructorID | InstructorName |
|--------------|----------------|
| 5001         | Prof. Smith    |
| 5002         | Prof. Johnson  |

4. Enrollment Table:

| StudentID | CourseID | InstructorID |
|-----------|----------|--------------|
| 1         | 101      | 5001         |
| 1         | 102      | 5002         |
| 2         | 101      | 5001         |

### Important Points to Remember

#### 1NF:
- Each column should contain atomic values.
- No repeating groups or arrays.

#### 2NF:
- Must be in 1NF.
- No partial dependency on a composite primary key.

#### 3NF:
- Must be in 2NF.
- No transitive dependencies (non-key columns should not depend on other non-key columns).

By following these normal forms, you ensure that your database is well-structured, reducing redundancy and improving data integrity.
