# @JsonIgnore


### FilteringController.java

    package com.tut.webservices.restful_webservice.myFiltering;
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.RestController;
    
    @RestController
    public class FilteringController {
    	
    	@GetMapping("/filtering")
    	public SomeBean filtering(){
    		return new SomeBean("val1","val2","val3");
    	}
    }

### SomeBean.java

    package com.tut.webservices.restful_webservice.myFiltering;
    import com.fasterxml.jackson.annotation.JsonIgnore;
    public class SomeBean {
    	private String field1;
    	
    	//------------STATIC FILTERING------------
    	// suppose I want to ignore this field in response
    	@JsonIgnore
    	private String field2;
    	//-----------------------------------------
    	
    	private String field3;
    	
    	public SomeBean(String field1, String field2, String field3) {
    		super();
    		this.field1 = field1;
    		this.field2 = field2;
    		this.field3 = field3;
    	}
    	public String getField1() {
    		return field1;
    	}
    	public void setField1(String field1) {
    		this.field1 = field1;
    	}
    	public String getField2() {
    		return field2;
    	}
    	public void setField2(String field2) {
    		this.field2 = field2;
    	}
    	public String getField3() {
    		return field3;
    	}
    	public void setField3(String field3) {
    		this.field3 = field3;
    	}
    	
<hr>

![image](https://github.com/user-attachments/assets/1c81500b-8bdb-491e-ab50-247ad31c1e5c)

    }
