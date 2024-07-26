# MappingJacksonValue

### FilteringController.java

    package com.tut.webservices.restful_webservice.myFiltering;
    
    import java.util.Arrays;
    import java.util.List;
    
    import org.springframework.http.converter.json.MappingJacksonValue;
    import org.springframework.web.bind.annotation.GetMapping;
    import org.springframework.web.bind.annotation.RestController;
    
    import com.fasterxml.jackson.databind.ser.FilterProvider;
    import com.fasterxml.jackson.databind.ser.impl.SimpleBeanPropertyFilter;
    import com.fasterxml.jackson.databind.ser.impl.SimpleFilterProvider;
    
    @RestController
    public class FilteringController {
    
    //	@GetMapping("/filtering")
    //	public SomeBean filtering() {
    //		return new SomeBean("val1", "val2", "val3");
    //	}
    	// --------------------DYNAMIC FILTERING--------------------
    	@GetMapping("/filtering")
    	public MappingJacksonValue dynamicFiltering() {
    		SomeBean someBean = 
    				new SomeBean("val1", "val2", "val3");
    		
    		MappingJacksonValue mjv = 
    				new MappingJacksonValue(someBean);
    		
    
    		// Correct the creation of SimpleBeanPropertyFilter
    		SimpleBeanPropertyFilter filter = 
    				SimpleBeanPropertyFilter.filterOutAllExcept("field1", "field3");
    		
    		FilterProvider filters = 
    				new SimpleFilterProvider().addFilter("SomeBeanFilter", filter);
    		// SomeBeanFilter -> this should be included in SomeBean.java
    		mjv.setFilters(filters);
    		return mjv;
    	}
    
    //	@GetMapping("/filtering-list")
    //	public List<SomeBean> filteringList() {
    //		return Arrays.asList(new SomeBean("val1", "val2", "val3"), new SomeBean("val4", "val5", "val6"));
    //	}
    	
    	
    	@GetMapping("/filtering-list")
    	public MappingJacksonValue filteringList() {
    		List<SomeBean> list = Arrays.asList(new SomeBean("val1", "val2", "val3"), new SomeBean("val4", "val5", "val6"));
    		
    		MappingJacksonValue mjv = 
    				new MappingJacksonValue(list);
    		
    		SimpleBeanPropertyFilter filter = 
    				SimpleBeanPropertyFilter.filterOutAllExcept("field2", "field3");
    		
    		FilterProvider filters = 
    				new SimpleFilterProvider().addFilter("SomeBeanFilter", filter);
    		// SomeBeanFilter -> this should be included in SomeBean.java
    		mjv.setFilters(filters);
    		return mjv;
    	}
    }


### SomeBean.java

    package com.tut.webservices.restful_webservice.myFiltering;
    
    import com.fasterxml.jackson.annotation.JsonFilter;
    
    @JsonFilter("SomeBeanFilter")
    public class SomeBean {
    
    	private String field1;
    	private String field2;
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
    
    }


<hr>
+ Field2 not shown

![image](https://github.com/user-attachments/assets/86661b48-cf03-4486-8fb2-07605a6cc34f)


<hr>

+ Field1 not shown

![image](https://github.com/user-attachments/assets/625908dd-37fa-4555-9d08-1c1bc423c79c)

