# Create A User 

### UserDaoService.java
    
    package com.tut.webservices.restful_webservice.user;
    import java.time.LocalDate;
    import java.util.ArrayList;
    import java.util.List;
    import java.util.function.Predicate;
    
    import org.springframework.stereotype.Component;
    
    @Component   
    public class UserDaoService {
    
    	private static List<User> users = new ArrayList<>();
     
     //--------- userId gets automatically alloted to new user---------------
    	private static Integer userCount = 0;
    
    	static {
    		users.add(new User(++userCount,"Monalisa",LocalDate.now().minusYears(30)));
    		users.add(new User( ++userCount,"Aman",LocalDate.now().minusYears(23)));
    		users.add(new User( ++userCount ,"Molly",LocalDate.now().minusYears(22)));
    	}
    	public List<User> getAllUsers(){
    		return users;
    	}
     //------------- Save User --------------------
    	public void save(User user) {
    		System.out.println("User Saved!");
    		user.setId(++userCount); // automatically Id is set
    		users.add(user);
    		
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
    import org.springframework.web.bind.annotation.PostMapping;
    import org.springframework.web.bind.annotation.RequestBody;
    import org.springframework.web.bind.annotation.RestController;
    
    @RestController
    public class UserResource {
    	@Autowired
    	private UserDaoService service;
    	
    	public UserResource(UserDaoService service) {
    		this.service = service;
    	}
    	
    	// -----------ADD A USER---------------
    	@PostMapping(path = "/users")
    	public void createUser(@RequestBody User user) {
    		service.save(user);
    		
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
    
