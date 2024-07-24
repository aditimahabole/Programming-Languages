# Path parameters
### Hello.java 

    package com.tut.webservices.restful_webservice.hello;
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.PathVariable;
    import org.springframework.web.bind.annotation.RestController;
    
    @RestController
    public class Hello {
    	// Path Parameters
    	
    	//--> /hello/path-param/aditi
    	
    	@GetMapping(path = "/hello/path-param/{name}")
    	public HelloBean helloPathVariable(@PathVariable String name) {
    		return new HelloBean(String.format("Hello , %s",name),24);
    	}
    
    }


### HelloBean.java
    
    package com.tut.webservices.restful_webservice.hello;
    
    public class HelloBean {
    	
    	private String message;
    	private Integer number;
    	public String getMessage() {
    		return message;
    	}
    
    	public void setMessage(String message) {
    		this.message = message;
    	}
    
    	public Integer getNumber() {
    		return number;
    	}
    
    	public void setNumber(Integer number) {
    		this.number = number;
    	}
    	public HelloBean(String message, int number) {
    		this.message = message;
    		this.number = number;
    	}
    }

<hr>

![image](https://github.com/user-attachments/assets/b32b2ede-759b-46b3-b5c7-4b8f69da735d)


    
