// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 4
//setw(2) = set width of 2
int is_safe(int maze[N][N],int x,int y)
{
     if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
     {
         return 1;
     }
     return 0;
}
void print_sol(int sol[N][N])
{
    cout<<"-------------------"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<" "<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------"<<endl;
}
int solve_maze_until(int maze[N][N],int x,int y,int sol[N][N])
{
    if(x==N-1 && y==N-1 && maze[x][y]==1)
    {
        cout<<"reached to last"<<endl;
        sol[x][y]==1;
        return 1;
    }
    if(is_safe(maze,x,y)==1)
    {cout<<"yes safe aya!"<<endl;
        if(sol[x][y]==1)
        {
            cout<<"yes safe!"<<endl;
            return 0;
        }
        sol[x][y]=1;
        cout<<"before x direc"<<endl;
        if(solve_maze_until(maze,x+1,y,sol)==1)
        {
            cout<<"sol["<<x<<"]["<<y<<"]"<<endl;
            cout<<"in x dire"<<endl;
            return 1;
        }
        cout<<"before y direc"<<endl;
        if(solve_maze_until(maze,x,y+1,sol)==1)
        {
             cout<<"sol["<<x<<"]["<<y<<"]"<<endl;
            cout<<"in y dire"<<endl;
            return 1;
        }
        cout<<"sol["<<x<<"]["<<y<<"]"<<endl;
        cout<<"none case valid"<<endl;
        sol[x][y]=0;
        return 0;
    }
    cout<<"all failed"<<endl;
    return 0;
}
int lesgo_rat(int maze[N][N])
{
    int sol[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            sol[i][j]=0;
        }
    }
    

    if(solve_maze_until(maze,0,0,sol)==0)
    {
        cout<<"Sol does not exist"<<endl;
        return 0;
        
    }
    else
    {
        print_sol(sol);
    }
    return 1;
}

int main() 
{
    int maze[N][N]=
    {{1,0,0,0},
     {1,1,0,1},
     {0,1,0,0},
     {1,1,1,1}
    };
    lesgo_rat(maze);
   
}
/*
/tmp/KDr2uY05su.o
yes safe aya!
before x direc
yes safe aya!
before x direc
all failed
before y direc
yes safe aya!
before x direc
yes safe aya!
before x direc
yes safe aya!
before x direc
all failed
before y direc
yes safe aya!
before x direc
all failed
before y direc
reached to last
sol[3][2]
in y dire
sol[3][1]
in y dire
sol[2][1]
in x dire
sol[1][1]
in x dire
sol[1][0]
in y dire
sol[0][0]
in x dire
-------------------
 1  0  0  0 
 1  1  0  0 
0  1  0  0 
 0  1  1  0 
-------------------
*/
