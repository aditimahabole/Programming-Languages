// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#define V 4
using namespace std;
void print_sol(int color[])
{
    cout << "Solution Exists:" " Following are the assigned colors "<<endl;
    for (int i = 0; i < V; i++)
    {
        cout<<"  "<<color[i];
    }
      
    cout <<endl;
}
int is_safe(int graph[V][V],int color[])
{
    for(int i=0;i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            if(graph[i][j]&&color[j]==color[i])
            {
                cout<<"color[j] = "<<color[j]<<" and j = "<<j<<endl;
                cout<<"color[i] = "<<color[i]<<" and i = "<<i<<endl;
                return 0;
            }
        }
    }
    return 1;
}

int graph_coloring(int graph[V][V],int c,int i,int color[V])
{
    if(i==V)
    {
        //that is reached to last end
        if(is_safe(graph,color))
        {
            print_sol(color);
            return 1;
        }
        return 0;
    }
    for(int j=1;j<=c;j++)
    {
        color[i]=j;
        if(graph_coloring(graph,c,i+1,color))
        {
            cout<<i<<" ko "<<j<<" color mila badhia"<<endl;
            return 1;
        }
        cout<<"galat color"<<endl;
        color[i]=0;
    }
    return 0;
}
int main() 
{
    int graph[V][V]=
    {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int c=3;
    int color[V];
    for(int i=0;i<V;i++)
    {
        color[i]=0;
    }
    if(!graph_coloring(graph,c,0,color))
    {
        cout<<"Solution does not exist"<<endl;
    }
   
    return 0;
}
/*
/tmp/Skw7El1S0k.o
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0galat color
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 1
color[i] = 1 and i = 0
galat color
galat color
galat color
color[j] = 1 and j = 2
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 2
color[i] = 1 and i = 0
galat color
color[j] = 1 and j = 2
color[i] = 1 and i = 0
galat color
galat color
color[j] = 1 and j = 3
color[i] = 1 and i = 0
galat color
color[j] = 2 and j = 2
color[i] = 2 and i = 1
galat color
color[j] = 2 and j = 2
color[i] = 2 and i = 1
galat color
galat color
color[j] = 1 and j = 3
color[i] = 1 and i = 0
galat color
Solution Exists: Following are the assigned colors 
  1  2  3  2
3 ko 2 color mila badhia
2 ko 3 color mila badhia
1 ko 2 color mila badhia
0 ko 1 color mila badhia
*/
