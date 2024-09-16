//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       // set : in set we can remove element
       // optimised ds for dijkstra algo
       // it stores elements in sorted order
       
       set<pair<int,int>> sets;
       // initially infinity
       vector<int>res(V,INT_MAX);
       
       // distance from source to source is 0 only
       res[S] = 0;
       // distance , node
       sets.insert({0,S});
       
       
       while(!sets.empty()){
           // iterator , * gives exact value
           auto &it = *sets.begin();
           
           int dist = it.first;
           int node = it.second;
           
           sets.erase(it);
           
           // travserse the neighbours
           
           for(auto &vec:adj[node]){
               
               int adjNode = vec[0];
               int wt      = vec[1];
               
               if(dist + wt < res[adjNode]){
                   
                   
                   if(res[adjNode]!=INT_MAX){
                       sets.erase({res[adjNode] , adjNode});
                   }
                   
                   res[adjNode] = dist+wt;
                   // push the node with distance 
                   sets.insert({dist+wt , adjNode});
                   
               }
           }
       }
       return res;

    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
