# EntityManager 

### Course.java

    package com.springtut.jpa_hibernate.course;
    
    import jakarta.persistence.Column;
    import jakarta.persistence.Entity;
    import jakarta.persistence.Id;
    
    @Entity
    public class Course {
    	@Id
    	private long id;
    
    	@Column(name = "name")
    	private String name;
    	@Column(name = "author")
    	private String author;
    
    	public Course() {
    
    	}
    
    	public Course(long id, String name, String author) {
    		super();
    		this.id = id;
    		this.name = name;
    		this.author = author;
    	}
    
    	public long getId() {
    		return id;
    	}
    
    	public void setId(long id) {
    		this.id = id;
    	}
    
    	public String getName() {
    		return name;
    	}
    
    	public void setName(String name) {
    		this.name = name;
    	}
    
    	public String getAuthor() {
    		return author;
    	}
    
    	public void setAuthor(String author) {
    		this.author = author;
    	}
    
    	@Override
    	public String toString() {
    		return "Course [id=" + id + ", name=" + name + ", author=" + author + "]";
    	}
    
    }

### CourseJpaRepo.java


    package com.springtut.jpa_hibernate.course.jpa;
    
    import org.springframework.stereotype.Repository;
    
    import com.springtut.jpa_hibernate.course.Course;
    
    import jakarta.persistence.EntityManager;
    import jakarta.persistence.PersistenceContext;
    import jakarta.transaction.Transactional;
    
    @Repository
    @Transactional
    public class CourseJpaRepo {
    	
    	@PersistenceContext
    	private EntityManager entityManager;
    	
    	public void insert(Course course) {
    		
    		//mapping done to Course automatically
    		entityManager.merge(course);
    	}
    	
    	
    	public Course findById(long id) {
    		return entityManager.find(Course.class, id);
    	}
    	
    	
    	public void deleteById(long id) {
    		Course course = entityManager.find(Course.class, id);
    		entityManager.remove(course);
    	}
    	
    
    }
    
