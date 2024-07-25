
### UserResource.java

    @DeleteMapping(path = "/users/{id}")
    	public void deleteUser(@PathVariable Integer id) {
    		 service.deleteUser(id);
    	}

### UserDaoService.java

	public void deleteUser(Integer id) {
		
		Predicate<User> predicate = user -> user.getId().equals(id);
		users.removeIf(predicate);
		System.out.println("Deleted");
	}
