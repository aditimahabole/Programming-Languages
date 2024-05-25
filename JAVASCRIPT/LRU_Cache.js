function LRU(capacity = 1){
    /*
    Node (object) will look like this ->
    
    {
        key    : ' some key',
        value  : ' some value',
        prev   : 'prev pointer poiting to some node or null',
        next_pt: 'next pointer poiting to some node or null'
    }
    
    */

   // will contain nodes (basically objects only)
    cache = {}; // max size = capacity
    let head = null; // head pointer
    let tail = null; // tail pointer
    let size = 0;
    
    function make_node(key , value){
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next_pt = null; 
    }
    
    function make_it_recent_node(node){
      
        // head points to node itself so it is at front only , no need to do anything
        if(node=== head){
            return; // already at front
        }
        
        // if tail is pointing to this node
        // then just remove the last node 
        // and tail will point to prev node 
        else if(node === tail){
            tail = tail.prev;
            tail.next_pt = null;
        }
          
        //  node is in the middle 
        // delete the node and change the pointers
        //  suppose we have to select 3 from 1->2->3->4
        // so just do 1->2->4 and change prev pointer 
        // now as 3 is recently used so we have to do this
        //  3->1->2->4
        else {
            node.prev.next_pt = node.next_pt;
            node.next_pt.prev = node.prev;
        }
        
        //  now making node as head as it is recently most used
        node.next_pt = head;
        node.prev = null;
        head.prev = node;
        head = node;
    }
    
    function delete_least_recent(){
        if(!tail ){
            return;
        }
        else if(head === tail){
            head = null;
            tail = null;
        }
        else{
            tail = tail.prev;
            tail.next_pt = null;
            
        }
        // now as we deleted the node , size decreases
        size--;
        
    }
    
    // put key value
    function put_key_value(key,value){
      
        // key already exists
        if(cache[key]){
            // after changing value move to first 
            cache[key].value = value;
            make_it_recent_node(cache[key]);
        }
          
        else{
            //  if key not present so make it
            const new_node = new make_node(key,value);
            cache[key] = new_node;
          
            // now mark head and tail pointer
            if(!head){
                head = new_node;
                tail = new_node;
            }
              
            else{
                // make new_node join to head
                new_node.next_pt = head;
                head.prev = new_node;
                head = new_node;
            }
          
            size++;
          // if size >capacity then remove the least recently used node
            
            if(size>capacity){
                const remove_key = tail.key;
                delete_least_recent();
                delete cache[remove_key];
            }
        }
        
    }
    
    // get key value
    function get_key(key){
      
        if(!cache[key]){
            return -1;
        }
        // before returning the value 
        // make it most recent 
        const value = cache[key].value;
        // cache[key] -> node 
        make_it_recent_node(cache[key]);
        return value;
        
    }
    
    // show cache 
    function show_cache(){
      console.log('showing you cache...')
        let temp = head;
        while(temp){
        console.log(`Key: ${temp.key}, Value: ${temp.value}`);
        temp = temp.next_pt;
        }
    }
    
    return{
        put_key_value,
        get_key,
        show_cache
    }
}

const myLRU = LRU(4);
myLRU.put_key_value(1,'1 value');
myLRU.put_key_value(2,'2 value');
myLRU.put_key_value(3,'3 value');

myLRU.show_cache();
console.log("---------------------")

myLRU.put_key_value(1,'1 new value');
myLRU.put_key_value(3,'3 new value');

myLRU.show_cache();
myLRU.put_key_value(4,'4 value');
myLRU.put_key_value(5,'5 value');
console.log("---------------------")
myLRU.show_cache();

// output
/*
showing you cache...
Key: 3, Value: 3 value
Key: 2, Value: 2 value
Key: 1, Value: 1 value
---------------------
showing you cache...
Key: 3, Value: 3 new value
Key: 1, Value: 1 new value
Key: 2, Value: 2 value
---------------------
showing you cache...
Key: 5, Value: 5 value
Key: 4, Value: 4 value
Key: 3, Value: 3 new value
Key: 1, Value: 1 new value
*/



