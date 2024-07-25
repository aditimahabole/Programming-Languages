


### Add dependency in pom.xml
    <dependency>
    			<groupId>org.springframework.boot</groupId>
    			<artifactId>spring-boot-starter-validation</artifactId>
    </dependency>

### User.java
    
    package com.tut.webservices.restful_webservice.user;
    import java.time.LocalDate;
    import jakarta.validation.constraints.Past;
    import jakarta.validation.constraints.Size;
    public class User {
      //----------------Validations-------------------
    	private Integer id;
    	@Size(min = 3, message = "Name should have atleast 2 characters")
    	private String name;
    
    	@Past // the date should be in past only not future
    	private LocalDate birthDate;
     //-----------------------------------------------
    
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

### Customized Response Entity Handler
    
    package com.tut.webservices.restful_webservice.myException;
    
    import java.time.LocalDate;
    
    import org.springframework.http.HttpHeaders;
    import org.springframework.http.HttpStatus;
    import org.springframework.http.HttpStatusCode;
    import org.springframework.http.ResponseEntity;
    import org.springframework.web.bind.MethodArgumentNotValidException;
    import org.springframework.web.bind.annotation.ControllerAdvice;
    import org.springframework.web.bind.annotation.ExceptionHandler;
    import org.springframework.web.context.request.WebRequest;
    import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;
    import com.tut.webservices.restful_webservice.user.UserNotFoundException;
    
    @ControllerAdvice
    public class CustomizedResponseEntityHandler extends ResponseEntityExceptionHandler {
    
    	@ExceptionHandler(Exception.class)
    	public final ResponseEntity<ErrorDetails> handleAllMyExceptions(Exception ex, WebRequest request) throws Exception {
    
    		ErrorDetails er = new ErrorDetails(ex.getMessage(), LocalDate.now(), request.getDescription(false));
    
    		return new ResponseEntity(er, HttpStatus.INTERNAL_SERVER_ERROR);
    	}
    
    	@ExceptionHandler(UserNotFoundException.class)
    	public final ResponseEntity<ErrorDetails> handleUserNotFound(Exception ex, WebRequest request) throws Exception {
    
    		ErrorDetails er = new ErrorDetails(ex.getMessage(), LocalDate.now(), request.getDescription(false));
    
    		return new ResponseEntity<ErrorDetails>(er, HttpStatus.NOT_FOUND);
    	}
      //-----------------------Argument not valid---------------------------------
    	@Override
    	protected ResponseEntity<Object> handleMethodArgumentNotValid(
    			MethodArgumentNotValidException ex,
    			HttpHeaders headers, 
    			HttpStatusCode status, 
    			WebRequest request) 
    	{	
    		ErrorDetails er = new ErrorDetails(ex.getFieldError().getDefaultMessage(), LocalDate.now(), request.getDescription(false));
    		return new ResponseEntity(er, HttpStatus.NOT_FOUND);
    	}
    }


  <hr>

  ![image](https://github.com/user-attachments/assets/ed5107ec-44bf-4983-a23b-47c836494569)

  ![image](https://github.com/user-attachments/assets/fe7b663c-6c81-467c-b216-bdb57bb6df5a)


    
    
