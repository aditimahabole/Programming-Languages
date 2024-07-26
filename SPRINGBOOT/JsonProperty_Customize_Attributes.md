# @JsonProperty
+ Used for customizing json attributes names
### User.java

    package com.tut.webservices.restful_webservice.user;
    import java.time.LocalDate;
    
    import com.fasterxml.jackson.annotation.JsonProperty;
    
    import jakarta.validation.constraints.Past;
    import jakarta.validation.constraints.Size;
    public class User {
    
    	private Integer id;
     
    	@Size(min = 3, message = "Name should have atleast 2 characters")

    	//---------For Serialization JSON Property-----------
    	// for naming json field
    	// customize attribute / element names
     
    	@JsonProperty("user_name")
    	private String name;
    
    	@Past // the date should be in past only not future
    	@JsonProperty("birth_date")
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

<hr>


![image](https://github.com/user-attachments/assets/fca93be7-3c07-407c-9ef2-95286a32c36b)

