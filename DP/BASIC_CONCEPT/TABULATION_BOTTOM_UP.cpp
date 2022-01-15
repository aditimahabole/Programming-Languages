//https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/

// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#define NIL -1// here NIL = -1
#define MAX 100//MAX =100
using namespace std;


int nth_fibonaci(int n)
{
   int f[n+1];
   int i;
   f[0]=0;
   f[1]=1;
   for(i=2;i<=n;i++)
   {
       f[i]=f[i-1]+f[i-2];
   }
   return f[n];
}
int main() 
{
    int n=4; 
    cout<<nth_fibonaci(n);
    return 0;
}
