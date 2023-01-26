#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int parent[100000];
int rank[100000];
void make_set()
{
    for(int i =1;i<=100000;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find_parent(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find_parent(parent[node]); 
    //path compression 
}
void union(int u,int v)
{
    u = find_parent(u);
    v = find_parent(v);
    if(rank[u]<rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v] = u;
    }
    else 
    {
        parent [v] = u;
        rank[u]++;
    }
}
int main()
{
    make_set();
    int m;
    cin>>m;
    while(m--)
    {
        cout<<"Enter u , v : ";
        int u,v;
        cin>>u>>v;
        uninon(u,v);
    }
    //if two node belong to same component or not 
    //then find parent of both if same parent then yes 
    if(find_parent(2) != find_parent(3){
        cout<<"Belong to same compoenent"<<endl;
    }
    else
    {
        cout<<"Belong to different compoenent"<<endl;
    }
    return 0;
}
