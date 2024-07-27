# @ManyToOne , @OneToMany

### Post.java

    package com.tut.webservices.restful_webservice.user;
    
    import jakarta.persistence.Entity;
    import jakarta.persistence.FetchType;
    import jakarta.persistence.GeneratedValue;
    import jakarta.persistence.Id;
    import jakarta.persistence.ManyToOne;
    
    @Entity
    public class Post {
        @Id
        @GeneratedValue
        private Integer Id;
    
    
        private String description;
    
        @ManyToOne(fetch=FetchType.LAZY)
        private User user;
    
        
        public Integer getId() {
            return Id;
        }
        public void setId(Integer id) {
            this.Id = id;
        }
        public String getDescription() {
            return description;
        }
        public void setDescription(String description) {
            this.description = description;
        }
    
        @Override
        public String toString() {
            return "id = " + Id +
                    " , description = " + description;
        }
    }


### User.java

    package com.tut.webservices.restful_webservice.user;
    import java.time.LocalDate;
    import java.util.List;
    
    import com.fasterxml.jackson.annotation.JsonIgnore;
    import com.fasterxml.jackson.annotation.JsonProperty;
    
    import jakarta.persistence.Entity;
    import jakarta.persistence.GeneratedValue;
    import jakarta.persistence.Id;
    import jakarta.persistence.OneToMany;
    import jakarta.validation.constraints.Past;
    import jakarta.validation.constraints.Size;
    
    @Entity(name = "user_details")
    public class User {
    
    	@Id
    	@GeneratedValue
    	private Integer id;
    	@Size(min = 3, message = "Name should have atleast 2 characters")
    	//---------For Serialization-----------
    	// for naming json field
    	// customize attribute / element names
    	@JsonProperty("user_name")
    	private String name;
    
    	@Past // the date should be in past only not future
    	@JsonProperty("birth_date")
    	
    	private LocalDate birthDate;
    
    	@OneToMany(mappedBy="user")
    	@JsonIgnore
    	private List<Post> posts;
    
    	protected User(){}
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

![image](https://github.com/user-attachments/assets/d6c74520-bb58-4056-a503-a55f7be6dbe0)

