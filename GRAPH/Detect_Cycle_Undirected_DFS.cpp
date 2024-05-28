class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool find_cycle(vector<int> adj[],vector<bool>&visited,int node , int parent){
        
        // make node visited true
        visited[node] = true;
        
        // iterate over all nodes connected to the node
        for(int &friend_node : adj[node]){
            
            // 0-1
            // 0 -> True
            // 1 -> True
            // if we do not consider parent then it will see that from 1
            // 0 is visited so it will say that cycle is present
            // but that's not the case right!
            // so considering parent of a node is important
            
            // if friend_node is parent itself then don't consider that node
            if(friend_node == parent) continue;
            
            // if a friend_node is visited and is not a parent then retun true
            // means its a cycle
            
            if(visited[friend_node] == true){
                return true;
            }
            
            // if friend node not visited then move forward 
            // update the node to current friend node 
            // and update the parent to current node
            
            if(find_cycle(adj, visited,friend_node,node)){
                return true;
            }
            
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // adj->adjacency list
        
        // visited array
        vector<bool>visited(V,false);
        
        // iterate thru all nodes
        
        for(int node = 0; node<V ;node++){
            
            // if node is not vivited then move forward
            
           if(visited[node] == false && find_cycle(adj,visited,node,-1)){
               
            //-1 is parent of 0th node as it does not have any parent
            return true;
           }
        }
        return false;
    }
};
