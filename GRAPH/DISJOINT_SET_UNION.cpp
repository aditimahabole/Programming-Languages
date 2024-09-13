   vector<int>parent;
    vector<int>rank; // based on rank make parent
    
    
    int find_parent(int x){
        if(x == parent[x]) return x;
        // doing path compression : means decreasing tree length
        return parent[x] = find_parent(parent[x]);
    }
    
    
    void union_func(int x , int y){
        
        int x_parent = find_parent(x);
        int y_parent = find_parent(y);
        
        if(x_parent == y_parent) return;
        
        if(rank[x_parent]>rank[y_parent])
            parent[y_parent] = x_parent;
            
        
        else if(rank[x_parent]<rank[y_parent])
            parent[x_parent] = y_parent;
            
        else{
             parent[x_parent] = y_parent;
             rank[y_parent]++;
            
        }
        
    }
