

### UserResource.java

    package com.tut.webservices.restful_webservice.user;
    import java.net.URI;
    import java.util.List;
    
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.http.ResponseEntity;
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.PathVariable;
    import org.springframework.web.bind.annotation.PostMapping;
    import org.springframework.web.bind.annotation.RequestBody;
    import org.springframework.web.bind.annotation.RestController;
    import org.springframework.web.servlet.support.ServletUriComponentsBuilder;
    
    @RestController
    public class UserResource {
    	@Autowired
    	private UserDaoService service;
    
    	public UserResource(UserDaoService service) {
    		this.service = service;
    	}
    
    	// ADD A USER
    
    	 @PostMapping(path = "/users")
    	 
    	    public ResponseEntity<User> createUser(@RequestBody User user) {
    	        User savedUser = service.save(user);
    
    	        // returning user URI like user/4 or user/id
             
    	        URI location = ServletUriComponentsBuilder
    	                .fromCurrentRequest()
    	                .path("/{id}")
    	                .buildAndExpand(savedUser.getId())
    	                .toUri();
    
    	        // to send response status 201
    	        return ResponseEntity.created(location).body(savedUser);
    	 }
    
    	@GetMapping(path = "/users")
    	public List<User> getAllusers() {
    		return service.getAllUsers();
    	}
    
    	@GetMapping(path = "/users/{id}")
    	public User getUserById(@PathVariable Integer id) {
    		return service.findOneUser(id);
    	}
    
    }

<hr>

![image](https://github.com/user-attachments/assets/86a1f907-8af0-404e-a3ca-a127c3862b40)

![image](https://github.com/user-attachments/assets/1131ffbc-d9f7-470f-b5fd-ea6d265aa0c7)
