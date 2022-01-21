//https://www.geeksforgeeks.org/program-nth-catalan-number/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int catalan_num(int n)
{
    int ans=0;
    if(n<=1)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        ans+=catalan_num(i)*catalan_num(n - i - 1);
    }
    return ans;
}
/* 
FORMULA 
SIGMA Ci * Cn-i
*/

int main() 
{
    int n=4;
    cout<<catalan_num(n);

    return 0;
}
