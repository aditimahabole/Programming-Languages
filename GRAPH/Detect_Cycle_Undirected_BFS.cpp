class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool find_cycle_BFS(vector<int> adj[],vector<bool>&visited,int start){
        
        // using BFS ->queue DS
        // we will insert {node , parent}
        
        queue<pair<int,int>>q;
        
        // at start push 0th node with parent as -1 as it does not have parent
        
        q.push({0,-1});
        
        // make 0th node visited true
        visited[start] = true;
        
        while(!q.empty()){
            
            // pop the front element from queue
            int cur_node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            // iterate thru all neighbours of cur_node
            
            for(int &friend_node : adj[cur_node]){
                
               if(visited[friend_node] == false){
                   
                   q.push({friend_node,cur_node});
                   visited[friend_node] = true;
               }
               else if(friend_node != parent)  return true;
            }
            
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // adj->adjacency list
        
        // visited array
        vector<bool>visited(V,false);
        
        // iterate thru all nodes
        
        for(int node = 0; node<V ; node++){
            
            // if node is not vivited then move forward
            
           if(visited[node] == false){
               if(find_cycle_BFS(adj,visited,node)) return true;
           }
        }
        return false;
    }
};
