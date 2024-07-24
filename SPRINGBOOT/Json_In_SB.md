### Hello.java

    package com.tut.webservices.restful_webservice.hello;
    
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.RestController;
    
    @RestController
    public class Hello {
    	@GetMapping(path = "/hello-bean")
    	public HelloBean hellobean() {
    		return new HelloBean("Hello",24); // an object is created which looks in json format
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

![image](https://github.com/user-attachments/assets/2254977b-e35b-4908-bc61-3c1eb364a466)




