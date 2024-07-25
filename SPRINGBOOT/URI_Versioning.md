## Different Version of URI
### VersionPersonController.java
    
    package com.tut.webservices.restful_webservice.myVersion;
    
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.RestController;
    
    @RestController
    public class VersionPersonController {
    	
    	@GetMapping("/v1/person")
    	public PersonV1 getFirstVersionOfPerson() {
    		return new PersonV1("Bob Charlie");
    		
    	}
    	
    	@GetMapping("/v2/person")
    	public PersonV2 getSecondVersionOfPerson() {
    		return new PersonV2(new Name("Aditi","Mahabole"));
    		
    	}
    
    }


### PersonV1.java

    package com.tut.webservices.restful_webservice.myVersion;
    public class PersonV1 {
    	private String name;
    	public PersonV1(String name) {
    		super();
    		this.name = name;
    	}
    	public String getName() {
    		return name;
    	}
    
    	public void setName(String name) {
    		this.name = name;
    	}
    	@Override
    	public String toString() {
    		return "PersonV1 [name=" + name + "]";
    	}
    }

### PersonV2.java

    package com.tut.webservices.restful_webservice.myVersion;
    
    public class PersonV2 {
    	private Name name;
    
    	public PersonV2(Name name2) {
    		super();
    		this.name = name2;
    		// TODO Auto-generated constructor stub
    	}
    
    	@Override
    	public String toString() {
    		return "PersonV2 [name=" + name + "]";
    	}
    
    	public Name getName() {
    		return name;
    	}
    
    	public void setName(Name name) {
    		this.name = name;
    	}
    
    }

### Name.java
        
    package com.tut.webservices.restful_webservice.myVersion;
    public class Name {
        
        private String firstName;
        private String lastName;
        public Name(String firstName, String lastName) {
            this.firstName = firstName;
            this.lastName = lastName;
            // TODO Auto-generated constructor stub
        }
        @Override
        public String toString() {
            return "Name [firstName=" + firstName + ", lastName=" + lastName + "]";
        }
        public String getFirstName() {
            return firstName;
        }
        public void setFirstName(String firstName) {
            this.firstName = firstName;
        }
        public String getLastName() {
            return lastName;
        }
    
        public void setLastName(String lastName) {
            this.lastName = lastName;
        }
    }

    
<hr>

![image](https://github.com/user-attachments/assets/d7d55ae2-9e9d-45cd-a19d-b9b59520ca42)

    
        
