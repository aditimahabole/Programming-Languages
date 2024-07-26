# @Repository

+ The @Repository annotation in Spring is used to mark a class as a Data Access Object (DAO) or repository.
+ responsible for interacting with the database and managing entities.

### CourseJdbcRepo.java


    package com.springtut.jpa_hibernate.course.jdbc;
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.jdbc.core.JdbcTemplate;
    import org.springframework.stereotype.Repository;
    
    @Repository
    // class talks to database
    public class CourseJdbcRepo {
    	
    	@Autowired
    	private JdbcTemplate springJdbcTemplate;
    	private static String INSERT_QUERY = """
    			insert into course (id,name,author)
    			values (1,'Learn AWS' , 'Aditi');
    			""";
    	public void insert() {
    		springJdbcTemplate.update(INSERT_QUERY);
    	}
    }


### CourseJdbcCommandLineRunner.java

    package com.springtut.jpa_hibernate.course.jdbc;
    
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.boot.CommandLineRunner;
    import org.springframework.stereotype.Component;
    
    @Component
    public class CourseJdbcCommandLineRunner implements CommandLineRunner {
    
    	@Autowired
    	private CourseJdbcRepo repo;
    
    	@Override
    	public void run(String... args) throws Exception {
    		repo.insert();
    	}
    
    }



<hr>

![image](https://github.com/user-attachments/assets/3ac1fd47-2a2c-492f-af27-22ad1cb059bf)

