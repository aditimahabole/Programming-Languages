
### UserNotFound.java
    
    package com.tut.webservices.restful_webservice.user;
    
    import org.springframework.http.HttpStatus;
    import org.springframework.web.bind.annotation.ResponseStatus;
    
    @ResponseStatus (code = HttpStatus.NOT_FOUND)
    // to make a class return a response status
    
    public class UserNotFoundException extends RuntimeException {
    // it extends RuntimeException
    
    	public UserNotFoundException(String message) {
    		super(message);
    	}
    }

### UserResource.java


    @GetMapping(path = "/users/{id}")
    	public User getUserById(@PathVariable Integer id) {
    		
    		User user = service.findOneUser(id);
    		if(user == null) {
    			
    			throw new UserNotFoundException("id : "+ id);
    		}
    		return user;
    	}

### UserDaoService.java

    public User findOneUser(Integer id) {
    		Predicate<User> predicate = user -> user.getId().equals(id);
    		return users.stream().filter(predicate).findFirst().orElse(null); // Returns null if no user is found
    	}

+ User with id = 6 not found
<hr>

![image](https://github.com/user-attachments/assets/2df9c834-8be8-4163-95ce-ecf3249a6ae4)
