

![image](https://github.com/user-attachments/assets/54f8944b-16b9-4c26-9ed4-591de8c6dfed)

### PostRepository.java

    package com.tut.webservices.restful_webservice.jpa;
    import org.springframework.data.jpa.repository.JpaRepository;
    import com.tut.webservices.restful_webservice.user.Post;
    public interface PostRepository extends  JpaRepository<Post, Integer>{
    
    }

### UserRepository.java


    package com.tut.webservices.restful_webservice.jpa;
    import org.springframework.data.jpa.repository.JpaRepository;
    import com.tut.webservices.restful_webservice.user.User;
    public interface UserRepository extends  JpaRepository<User, Integer> {
    }


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
    
        @ManyToOne(fetch = FetchType.LAZY)
        private User user;
    
        public User getUser() {
            return user;
        }
    
        public void setUser(User user) {
            this.user = user;
        }
    
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
    	// ---------For Serialization-----------
    	// for naming json field
    	// customize attribute / element names
    	@JsonProperty("user_name")
    	private String name;
    
    	@Past // the date should be in past only not future
    	@JsonProperty("birth_date")
    
    	private LocalDate birthDate;
    
    	@OneToMany(mappedBy = "user")
    	@JsonIgnore
    	private List<Post> posts;
    
    	protected User() {
    	}
    
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
    
    	public void setPosts(List<Post> posts) {
    		this.posts = posts;
    
    	}
    
    	public List<Post> getPosts() {
    		return this.posts;
    
    	}
    
    }

### UserJpaResource.java
    
    package com.tut.webservices.restful_webservice.user;
    
    import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.*;
    
    import java.net.URI;
    import java.util.List;
    import java.util.Optional;
    
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.hateoas.EntityModel;
    import org.springframework.hateoas.server.mvc.WebMvcLinkBuilder;
    import org.springframework.http.ResponseEntity;
    import org.springframework.web.bind.annotation.DeleteMapping;
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.PathVariable;
    import org.springframework.web.bind.annotation.PostMapping;
    import org.springframework.web.bind.annotation.RequestBody;
    import org.springframework.web.bind.annotation.RestController;
    import org.springframework.web.servlet.support.ServletUriComponentsBuilder;
    
    import com.tut.webservices.restful_webservice.jpa.PostRepository;
    import com.tut.webservices.restful_webservice.jpa.UserRepository;
    
    import jakarta.validation.Valid;
    
    @RestController
    public class UserJpaResource {
    
        @Autowired
        private UserRepository userRepo;
        private PostRepository postRepository;
    
        public UserJpaResource(UserRepository userRepo,PostRepository postRepository) {
    
            this.userRepo = userRepo;
            this.postRepository = postRepository;
        }
    
        // ADD A USER
        @PostMapping(path = "/jpa/users")
        public ResponseEntity<User> createUser(@Valid @RequestBody User user) {
            User savedUser = userRepo.save(user);
    
            // returning user URI like user/4 or user/id
            URI location = ServletUriComponentsBuilder.fromCurrentRequest()
                    .path("/{id}")
                    .buildAndExpand(savedUser.getId())
                    .toUri();
    
            // to send response status 201
            return ResponseEntity.created(location).body(savedUser);
        }
        //--------------------------------CREATE POST FOR USER--------------------------------------------
        @PostMapping("/jpa/users/{id}/posts")
        public ResponseEntity<Object> createPostForUser(@PathVariable int id, @Valid @RequestBody Post post) {
            // find user 
            Optional<User> user  = userRepo.findById(id);
            if(user.isEmpty()){
                throw new UserNotFoundException("Not Found id : "+id);
            }
    
            post.setUser(user.get());
            Post savedPost = postRepository.save(post);
    
            URI location = ServletUriComponentsBuilder.fromCurrentRequest()
            .path("/{id}").buildAndExpand(savedPost.getId()).toUri();
    
            System.out.println("Location : -> "+location);
            
            return ResponseEntity.created(location).build();
        }
        //---------------------------------------------------------------------------------------------
    
        // GET ALL USERS
        @GetMapping(path = "/jpa/users")
        public List<User> getAllUsers() {
            return userRepo.findAll();
        }
    
        @GetMapping("/jpa/users/{id}/posts")
        public List<Post> getPostForUser(@PathVariable Integer id) {
            
    
            Optional<User> optionalUser = userRepo.findById(id);
            if (optionalUser.isEmpty()) {
                throw new UserNotFoundException("User not Found id: " + id);
            }
            User user = optionalUser.get();
            return user.getPosts();
        }
     
     
    
        // DELETE USER
        @DeleteMapping(path = "/jpa/users/{id}")
        public void deleteUser(@PathVariable Integer id) {
            userRepo.deleteById(id);
        }
    
        // HATEOAS: ADDING LINKS TO THE RESOURCES
        @GetMapping(path = "/jpa/users/{id}/details")
        public EntityModel<User> getUserDetails(@PathVariable Integer id) {
    
            Optional<User> optionalUser = userRepo.findById(id);
            if (optionalUser.isEmpty()) {
                throw new UserNotFoundException("id: " + id);
            }
    
            User user = optionalUser.get();
    
            // Create the EntityModel with the user
            EntityModel<User> entityModel = EntityModel.of(user);
    
            // Adding a link to all users
            WebMvcLinkBuilder linkToAllUsers = linkTo(methodOn(UserJpaResource.class).getAllUsers());
            entityModel.add(linkToAllUsers.withRel("all-users"));
    
            return entityModel;
        }
    }


<hr>

![image](https://github.com/user-attachments/assets/39b9b907-6c0f-4462-b022-1ec4817fbef4)

![image](https://github.com/user-attachments/assets/51f96787-bda1-4e3e-b1f9-eff6dcf40084)


![image](https://github.com/user-attachments/assets/42e4e29a-7c8d-41b3-bdf9-be9e65bc27e3)


    
        
            
            
