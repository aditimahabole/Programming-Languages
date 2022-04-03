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
                cout<<"color[i] = "<<color[i]<<" and i = "<<i<<endl;
                cout<<"color[j] = "<<color[j]<<" and j = "<<j<<endl;
                
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
        cout<<"i==v ho gya"<<endl;
        if(is_safe(graph,color))
        {
            cout<<"print_sol called"<<endl;
            print_sol(color);
            return 1;
        }
        return 0;
    }
    for(int j=1;j<=c;j++)
    {
        color[i]=j;
        cout<<"in loop and graph_coloring called"<<endl;
        cout<<i<<"th vertex ko diya"<<color[j]<<endl;
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
in loop and graph_coloring called
0th vertex ko diya0
in loop and graph_coloring called
1th vertex ko diya1
in loop and graph_coloring called
2th vertex ko diya1
in loop and graph_coloring called
3th vertex ko diya1
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
in loop and graph_coloring called
3th vertex ko diya1
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
galat color
in loop and graph_coloring called
2th vertex ko diya2
in loop and graph_coloring called
3th vertex ko diya1
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
in loop and graph_coloring called
3th vertex ko diya2
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
galat color
in loop and graph_coloring called
2th vertex ko diya0
in loop and graph_coloring called
3th vertex ko diya1
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 1
galat color
galat color
galat color
in loop and graph_coloring called
1th vertex ko diya0
in loop and graph_coloring called
2th vertex ko diya2
in loop and graph_coloring called
3th vertex ko diya2
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 2
galat color
in loop and graph_coloring called
3th vertex ko diya1
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 2
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 2
galat color
galat color
in loop and graph_coloring called
2th vertex ko diya2
in loop and graph_coloring called
3th vertex ko diya2
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 3
galat color
in loop and graph_coloring called
3th vertex ko diya2
i==v ho gya
color[i] = 2 and i = 1
color[j] = 2 and j = 2
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
color[i] = 2 and i = 1
color[j] = 2 and j = 2
galat color
galat color
in loop and graph_coloring called
2th vertex ko diya0
in loop and graph_coloring called
3th vertex ko diya2
i==v ho gya
color[i] = 1 and i = 0
color[j] = 1 and j = 3
galat color
in loop and graph_coloring called
3th vertex ko diya3
i==v ho gya
print_sol called
Solution Exists: Following are the assigned colors 
  1  2  3  2
3 ko 2 color mila badhia
2 ko 3 color mila badhia
1 ko 2 color mila badhia
0 ko 1 color mila badhia
*/
