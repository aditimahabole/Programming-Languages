// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void  add_edge_fun(vector<int> ad_list[],int u,int v)
{
    ad_list[u].push_back(v);
    ad_list[v].push_back(u);
    
}
void print(vector<int> ad_list[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" --> ";
        // for(int j=0;j<ad_list[i].size();i++)
        // {
        //     cout<<ad_list[i][j]<<" , ";
        // }
        for(auto j :ad_list[i])
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    int n=5;
    vector<int> ad_list[n];//adjency list
    //0-> ------
    //1->---
    //2->---------
    //iss type ka hoga
    add_edge_fun(ad_list,0,1);
    add_edge_fun(ad_list,0,4);
    add_edge_fun(ad_list,1,2);
    add_edge_fun(ad_list,1,3);
    add_edge_fun(ad_list,1,4);
    add_edge_fun(ad_list,2,3);
    print(ad_list,n);
    
    return 0;
}
