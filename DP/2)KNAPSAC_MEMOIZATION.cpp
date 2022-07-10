//https://youtu.be/fJbIuhs24zQ
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//memoisation = recursion + dp table ka use store karne ke liye

int knapSack(int W,int *wt,int *val,int n,int **t)
{
    if(n==0||W==0)
    {
        t[n][W]=0;
        return t[n][W];
    }
    if(t[n][W]!=-1)
    {
        return t[n][W];
        //agar -1 ki jagha ko value hai to seedha usse return karwa do
    }
    
    if(wt[n]<=W)
    {
    t[n][W]=max(val[n]+knapSack(W-wt[n],wt,val,n-1,t),knapSack(W,wt,val,n-1,t));
        return t[n][W];
        //agar -1 hai to recurssive call to karni padegi
        //aur uss jagha pe vo value store ho jaegi
    }
    else if(wt[n]>W)
    {
        t[n][W]=knapSack(W,wt,val,n-1,t);
        return t[n][W];
        //agar -1 hai to recurssive call to karni padegi
        //aur uss jagha pe vo value store ho jaegi
        
    }
    return -1;
}


int main() 
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
   // int t[4][52]={-1};
    int n = sizeof(val) / sizeof(val[0]);
    ////////////////////////////////////////
    //to declare table dynamically
    int **t;
    t= new int*[n];
    
    
     for (int i = 0; i < n; i++)
     {
         t[i] = new int[W + 1];
         //we are creating cols for each row 
     }
     for (int i = 0; i <n; i++)
       { 
           for (int j = 0; j < W + 1; j++)
           {
             t[i][j] = -1;
             //initializing to -1
           }
           
       }
    //////////////////////////////////////
    cout <<knapSack(W, wt, val, n-1,t);

    return 0;
}
