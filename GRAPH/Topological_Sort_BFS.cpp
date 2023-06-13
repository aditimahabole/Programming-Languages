vector<int> topoSort(int V, vector<int> adj[]) 
	{ 
	   vector<int>indegree(V,0);
	   for(int i=0;i<V;i++)
	   {
	       for(auto j:adj[i]) indegree[j]++;
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   {
	       if(indegree[i] == 0) q.push(i);
	   }
	   vector<int> topo;
	   while(q.empty() == false)
	   {
	       int node = q.front();
	       q.pop();
	       topo.push_back(node);
	       for(auto i:adj[node])
	       {
	           indegree[i]--;
	           if(indegree[i] == 0) q.push(i);
	       }
	   }
	   return topo;
	    
	}
};
