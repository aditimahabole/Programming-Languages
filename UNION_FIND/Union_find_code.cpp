#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Find(int node,vector<int>&parent)
{
    
    cout<<"node = "<<node<<endl;
    int temp = node;
    while(temp != parent[temp])
    {
        cout<<"temp not equal to parent -->"<<endl;
        cout<<"------------------"<<endl;
        cout<<"temp = "<<temp<<endl;
        cout<<"parent of temp = "<<parent[temp]<<endl;
        temp = parent[temp];
        cout<<"------------------"<<endl;
    }
    //path commpression
    while(node!=temp)
    {
        cout<<"Path commpression -->"<<endl;
        int next = parent[node];
        parent[node] = temp;
        node = next;
    }
    cout<<node<<" is returned."<<endl;
    return node;
}
void Union(int node1, int node2,vector<int>&parent)
{
    //parent of node1
    cout<<"----------------------------"<<endl;
    int po_node1 = Find(node1,parent);
    cout<<"node1 = "<<node1<<endl;
    cout<<"parent of node1 = "<<po_node1<<endl;
    //parent of node2
    int po_node2 = Find(node2,parent);
    cout<<"node2 = "<<node2<<endl;
    cout<<"parent of node2 = "<<po_node2<<endl;
    if(po_node1 != po_node2)
    {
        parent[po_node1] = po_node2;
    }
    cout<<"parent = node1 = "<<po_node1<<endl;
    cout<<"child = node2 = "<<po_node2<<endl;
    cout<<"----------------------------"<<endl;
}
int main()
{
   cout<<"Number of nodes : "<<endl;
   int n;
   cin>>n;
   vector<int>parent(n);
   for(int i =0;i<n;i++)
   {
       parent[i] = i;
   }
   vector<int>rank(n,0);
   Union(1,2,parent);
   Union(2,3,parent);
   Union(4,5,parent);
   Union(6,7,parent);
   return 0;
}
