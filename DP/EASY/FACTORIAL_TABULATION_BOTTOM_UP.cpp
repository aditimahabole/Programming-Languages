////////////////////TABULATION METHOD//////////////////
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fact_tabulation(int n)
{
    int f[n+1];
    f[0]=1;
    f[1]=1;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]*i;
    }
    return f[n];
    
}
int main() 
{
    int n=6; 
    cout<<fact_tabulation(n);
  
    return 0;
}
