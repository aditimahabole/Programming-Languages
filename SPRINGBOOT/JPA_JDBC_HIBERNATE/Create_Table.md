# Make Table in H2 Database

+ Make an sql file in resource folder

![image](https://github.com/user-attachments/assets/e291075e-eb1e-46e3-a20c-f9686c3908ac)

+ Create table in sql file

      create table course(
        id bigint not null,
        name varchar(255) not null,
        author varchar(255) not null,
        primary key(id)
      );

+ Refresh localhost:8080/h2-console

![image](https://github.com/user-attachments/assets/202ff177-4dac-4b3c-91af-347b54f4f7d3)

