
### User.java 
    package com.tut.webservices.restful_webservice.user;
    import java.time.LocalDate;
    public class User {
    	
    	private Integer id;
    	private String name;
    	private LocalDate birthDate;
    	
    	public User(Integer id, String name, LocalDate birthDate) {
    		super();
    		this.id = id;
    		this.name = name;
    		this.birthDate = birthDate;
    	}
    	public Integer getId() {
    		return id;
    	}
    	public void setId(Integer id) {
    		this.id = id;
    	}
    	public String getName() {
    		return name;
    	}
    	public void setName(String name) {
    		this.name = name;
    	}
    	public LocalDate getBirthDate() {
    		return birthDate;
    	}
    	public void setBirthDate(LocalDate birthDate) {
    		this.birthDate = birthDate;
    	}
    }

### UserDaoService.java

    package com.tut.webservices.restful_webservice.user;
    import java.time.LocalDate;
    import java.util.ArrayList;
    import java.util.List;
    import java.util.function.Predicate;
    
    import org.springframework.stereotype.Component;
    
    @Component   
    // this makes instance of class 
    // and by using @Autowired we can inject object of type this class
    // into another class 
    public class UserDaoService {
    	
    	// we use JPA / Hibernate to talk to >  Database
    	// In this we are making static list 
    	
    	// UserDaoService > static 
    	private static List<User> users = new ArrayList<>();
    	
    	
    //	static initializer block.
    	static {
    		users.add(new User(1,"Monalisa",LocalDate.now().minusYears(30)));
    		users.add(new User(2,"Aman",LocalDate.now().minusYears(23)));
    		users.add(new User(3,"Molly",LocalDate.now().minusYears(22)));
    	}
    	
    //	returning all users list
    	public List<User> getAllUsers(){
    		return users;
    	}
    	// not implemented
    	public User save(User user) {
    		return null;
    	}
    
    	public User findOneUser(Integer id) {
    	    Predicate<User> predicate = user -> user.getId().equals(id);
    	    return users.stream()
    	                .filter(predicate)
    	                .findFirst()
    	                .orElse(null); // Returns null if no user is found
    	}
    }


### UserResource.java

    package com.tut.webservices.restful_webservice.user;
    import java.util.List;
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.PathVariable;
    import org.springframework.web.bind.annotation.RestController;
    
    @RestController
    public class UserResource {
    	@Autowired
    	private UserDaoService service;
    	
    	public UserResource(UserDaoService service) {
    		this.service = service;
    	}
    	
    	@GetMapping(path = "/users")
    	public List<User> getAllusers(){
    		return service.getAllUsers();
    	}
    	
    	@GetMapping(path = "/user/{id}")
    	public User getUserById(@PathVariable Integer id){
    		return service.findOneUser(id);
    	}
    
    }

<hr>

![image](https://github.com/user-attachments/assets/323c7505-1675-4a8d-a1c5-927d2d789d2f)




