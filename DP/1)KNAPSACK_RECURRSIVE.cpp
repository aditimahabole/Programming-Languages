// Online C++ compiler to run C++ program online
//https://youtu.be/kvyShbFVaY8 :REFER
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapSack(int W,int *wt,int *val,int n)
{
    if(n==0||W==0)
    {
        return 0;
    }
    if(wt[n]<=W)
    {
        return max(val[n]+knapSack(W-wt[n],wt,val,n-1),knapSack(W,wt,val,n-1));
        //(jab le liya uss wt ko, jab nhi liya  uss wt ko)
        //(liya to uska price + baki bacha hua ka price, nhi liya to baki bacha hua ka price)
        //dono ka max nikalo(...,....)
    }
    else if(wt[n]>W)
    {
        return knapSack(W,wt,val,n-1);
        //jab W bada hai to bag me aega hi nhi to baki bacha hua part pe call karenge function
    }
}



int main() {
   int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n-1);

    return 0;
}
