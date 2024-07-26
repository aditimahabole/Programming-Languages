

![image](https://github.com/user-attachments/assets/018863bc-67ec-4a09-bb85-0f7cc969076a)

<hr>

### CourseJdbcRepo.java

    package com.springtut.jpa_hibernate.course.jdbc;
    
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.jdbc.core.JdbcTemplate;
    import org.springframework.stereotype.Repository;
    
    import com.springtut.jpa_hibernate.course.Course;
    
    @Repository
    // class talks to database
    public class CourseJdbcRepo {
    
    	@Autowired
    	private JdbcTemplate springJdbcTemplate;
     //---------use ? for unkown values------------------
    
    	private static String INSERT_QUERY = """
    			insert into course (id,name,author)
    			values (?,?,?);
    
    			""";
    
    	public void insert(Course course) {
    		springJdbcTemplate.update(INSERT_QUERY, course.getId(), course.getName(), course.getAuthor());
    	}
     //---------------------------------------------------
    
    }
    
### CourseJdbcCommandLineRunner.java


    package com.springtut.jpa_hibernate.course.jdbc;
    
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.boot.CommandLineRunner;
    import org.springframework.stereotype.Component;
    
    import com.springtut.jpa_hibernate.course.Course;
    
    @Component
    public class CourseJdbcCommandLineRunner implements CommandLineRunner {
    
    	@Autowired
    	private CourseJdbcRepo repo;
    
    	@Override
    	public void run(String... args) throws Exception {
    		repo.insert(new Course(2 , "Springboot", "hello"));
    	}
    
    }

<hr>

![image](https://github.com/user-attachments/assets/e4ff028d-fc39-4759-94a5-4ba9e4f2e8f9)

