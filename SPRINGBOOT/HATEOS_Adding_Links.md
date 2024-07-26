# HATEOAS (Hypermedia as the Engine of Application State)

+ We are adding links to JSON data without changing User Schema
+ This can be dome using EntityModel
+ WebMvcLinkBuilder helps to add or make links

### UserResource.java

    package com.tut.webservices.restful_webservice.user;
    
    import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.linkTo;
    import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.methodOn;
    
    import java.net.URI;
    import java.util.List;
    
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
    
    import jakarta.validation.Valid;
    
    @RestController
    public class UserResource {
    
        @Autowired
        private UserDaoService service;
    
        public UserResource(UserDaoService service) {
            this.service = service;
        }
    
        // ADD A USER
        @PostMapping(path = "/users")
        public ResponseEntity<User> createUser(@Valid @RequestBody User user) {
            User savedUser = service.save(user);
    
            // returning user URI like user/4 or user/id
            URI location = ServletUriComponentsBuilder.fromCurrentRequest()
                                                      .path("/{id}")
                                                      .buildAndExpand(savedUser.getId())
                                                      .toUri();
    
            // to send response status 201
            return ResponseEntity.created(location).body(savedUser);
        }
    
        // GET ALL USERS
        @GetMapping(path = "/users")
        public List<User> getAllUsers() {
            return service.getAllUsers();
        }
    
        // GET USER BY ID
        @GetMapping(path = "/users/{id}")
        public User getUserById(@PathVariable Integer id) {
            User user = service.findOneUser(id);
            if (user == null) {
                throw new UserNotFoundException("id: " + id);
            }
            return user;
        }
    
        // DELETE USER
        @DeleteMapping(path = "/users/{id}")
        public void deleteUser(@PathVariable Integer id) {
            service.deleteUser(id);
        }
        //------------------------------------------------------------------------------------
        // HATEOAS: ADDING LINKS TO THE RESOURCES
        @GetMapping(path = "/users/{id}/details")
        public EntityModel<User> getUserDetails(@PathVariable Integer id) {
            User user = service.findOneUser(id);
            if (user == null) {
                throw new UserNotFoundException("id: " + id);
            }
    
            EntityModel<User> entityModel = EntityModel.of(user);
            // Adding link to all users
            WebMvcLinkBuilder link = linkTo(methodOn(this.getClass()).getAllUsers());
            entityModel.add(link.withRel("all-users"));
    
            return entityModel;
        }
    }

<hr>

![image](https://github.com/user-attachments/assets/de438082-4188-4576-ab44-e6660a20fd83)



