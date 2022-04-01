// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 4
void print_sol(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
int is_safe(int board[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return 0;
        }
    }
    
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return 0;
        }
    }
    
    for(i=row,j=col;i<N &&j>=0;i++,j--)
    {
        if(board[i][j])
        {
            return 0;
        }
    }
    return 1;
}
int solve_queen(int board[N][N],int col)
{
    if(col>=N)
    {
        return 1;
    }
    for(int i=0;i<N;i++)
    {
        if(is_safe(board,i,col))
        {
            board[i][col]=1;
            if(solve_queen(board,col+1))
            {
                return 1;
            }
            board[i][col]=0;
        }
    }
    return 0;
}

int main()
{
    int board[N][N]=
    {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    if(solve_queen(board,0)==0)
    {
        cout<<"sol does not exist"<<endl;
        
    }
    else
    {
        print_sol(board);
    }
   

    return 0;
}
