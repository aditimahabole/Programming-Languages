
+ Install Docker

+ Paste below on command line

      docker run --detach
      --env MYSQL_ROOT_PASSWORD=dummypassword
      --env MYSQL_USER=social-media-user
      --env MYSQL_PASSWORD=dummypassword
      --env MYSQL_DATABASE=social-media-database
      --name mysql --publish 3306:3306 mysql:8-oracle

### application.properties

    spring.application.name=restful-webservice
    # spring.datasource.url = jdbc:h2:mem:testdb
    spring.jpa.defer-datasource-initialization=true
    spring.jpa.show-sql=true
    
    # -----------------connect mysql------------------------------------
    spring.datasource.url=jdbc:mysql://localhost:3306/social-media-database
    spring.datasource.username=social-media-user
    spring.datasource.password=dummypassword
    
    
    # -----------------start of app db schema will be updated-----------
    spring.jpa.hibernate.ddl-auto=update
    spring.jpa.properties.hibernate.dialect=org.hibernate.dialect.MySQLDialect

    # ----------Use below command on SQLshell command line--------------
    # \connect social-media-user@localhost:3306

    
    
    # --------------------------docker command--------------------------
    # docker run --detach 
    # --env MYSQL_ROOT_PASSWORD=dummypassword 
    # --env MYSQL_USER=social-media-user 
    # --env MYSQL_PASSWORD=dummypassword 
    # --env MYSQL_DATABASE=social-media-database 
    # --name mysql --publish 3306:3306 mysql:8-oracle

### pom.xml

    <dependency>
    			<groupId>mysql</groupId>
    			<artifactId>mysql-connector-java</artifactId>
    			<version>8.0.30</version>
    </dependency>

