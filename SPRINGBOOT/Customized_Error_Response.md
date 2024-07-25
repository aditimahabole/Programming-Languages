# Building custom Error details
### ErrorDetails.java

    package com.tut.webservices.restful_webservice.myException;
    
    import java.time.LocalDate;
    
    public class ErrorDetails {
    	private String message;
    	private LocalDate date;
    	private String detials;
    	
    	public ErrorDetails(String message, LocalDate date, String detials) {
    		super();
    		this.message = message;
    		this.date = date;
    		this.detials = detials;
    	}
    
    	public String getMessage() {
    		return message;
    	}
    
    	public void setMessage(String message) {
    		this.message = message;
    	}
    
    	public LocalDate getDate() {
    		return date;
    	}
    
    	public void setDate(LocalDate date) {
    		this.date = date;
    	}
    
    	public String getDetials() {
    		return detials;
    	}
    
    	public void setDetials(String detials) {
    		this.detials = detials;
    	}
    }

### CustomizedResponseEntityHandler.java

    package com.tut.webservices.restful_webservice.myException;
    import java.time.LocalDate;
    import org.springframework.http.HttpStatus;
    import org.springframework.http.ResponseEntity;
    import org.springframework.web.bind.annotation.ControllerAdvice;
    import org.springframework.web.bind.annotation.ExceptionHandler;
    import org.springframework.web.context.request.WebRequest;
    import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;
    
    @ControllerAdvice
    public class CustomizedResponseEntityHandler extends ResponseEntityExceptionHandler {
    
    	@ExceptionHandler(Exception.class)
    	public final ResponseEntity<Object> handleAllMyExceptions(Exception ex, WebRequest request) throws Exception {
    
    		ErrorDetails er = new ErrorDetails(ex.getMessage(), LocalDate.now(), request.getDescription(false));
    		
    		return new ResponseEntity(er , HttpStatus.INTERNAL_SERVER_ERROR);
    	}
    }


<hr>

![image](https://github.com/user-attachments/assets/ae8ad5c2-033b-4b78-a283-2f903b14583c)

![image](https://github.com/user-attachments/assets/38256a7b-05e4-49f5-921d-48d36df79f69)

    
