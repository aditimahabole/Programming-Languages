
//https://unstop.com/code/practice/250151
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> adj,int depth,int node,int parent,int target)
{
    if(node==target)
    {
        return depth;
    }
    int ans=0;
    for(auto child:adj[node])
    {
        // cout<<"node = "<<node<<" , child = "<<child<<endl;
        if(child!=parent)
        {
            // cout<<"child!=parrent check"<<endl;
            ans+=dfs(adj,depth+1,child,node,target);
        }
    }
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,a,b;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int val=dfs(adj,0,1,-1,i);
        ans+=val;
    }
    cout<<ans<<endl;
    return 0;
}
