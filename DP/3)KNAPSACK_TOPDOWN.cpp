//https://youtu.be/ntCGbPMeqgg
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//top-down approach me sabse pehli baat matrix banate
//matrix bananne se pehle recursion wala code likho
//usme jo variable change hore honge na uski table banegi
//table ka size n+1 w+1 karne ka rehta hai
//recurssion me jo base condition hoti hai usko hum top down me initialize ke roop me use karte 
//that is jab T[0][0] to value 0 kar diya isme matlab (recurssion me jab n==0||w==0 then return 0 kiya tha.)
//table me ek point like 2,3 hume kya represent karta hai
//2 hume bataega ki bhai humne pehle 2 item liya hai
//aur 3 hume bataega uska weight matlab 3 wt  ka bag hai 
//aur item 1 item 2 diya rakha hai to ab muje max profit itna tak ka batao
//jab hum ye store kar diye to ye stored value humko aage wale i(items n),j(W) ke liye kaam aega
//so sabse pehle recursion fir ya to memoizaition ya top down
//top down me stack overflow hone ka chance nhi rehta to usse best mana jata haiii!

int knapSack(int W,int *wt,int *val,int n,int **t)
{
    //yaha i denotes n (num of item) and j denotes W (weight)
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(wt[i]<=W)
            {
                t[i][j]=max(val[i]+t[i-1][j-wt[i]],t[i-1][j]);
                //max(jab include kiya,include nhi kiya)
            }
            else if(wt[i]>W)
            {
                t[i][j]=t[i-1][j];
            }
            
        }
        
    }
 return t[n][W];
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
    
    //////////////////////////////////////
    cout <<knapSack(W, wt, val, n-1,t);

    return 0;
}
