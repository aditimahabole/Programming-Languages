# Delete From Table

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
       //------------------INSERT QUERY--------------------------
    
    	private static String INSERT_QUERY = """
    			insert into course (id,name,author)
    			values (?,?,?);
    
    			""";
       //------------------DELETE QUERY--------------------------
       
    	private static String DELETE_QUERY = """
    			delete from  course where id = ? ;
    			""";
      //------------------INSERT--------------------------
      
    	public void insert(Course course) {
    		springJdbcTemplate.update(INSERT_QUERY, course.getId(), course.getName(), course.getAuthor());
    	}
      //-------------------DELETE--------------------------
      
    	public void deleteById(long id) {
    		springJdbcTemplate.update(DELETE_QUERY, id);
    	}
    
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
    		repo.insert(new Course(2, "Springboot", "hello"));
    		repo.insert(new Course(1, "AWS", "momo"));
    		repo.insert(new Course(3, "JAVA", "panipuri"));
    
    		repo.deleteById(1);
    	}
    
    }

<hr>

![image](https://github.com/user-attachments/assets/50d0b242-6b6b-4478-8cc8-7f66fbdce21f)

    
