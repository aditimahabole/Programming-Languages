//https://www.geeksforgeeks.org/find-pair-with-greatest-product-in-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int pair_great_product(int a[],int n)
{
    unordered_map<int,int> op;
    for(int i=0;i<n;i++)
    {
        op[a[i]]++;
    }
    cout<<"-----------------------------"<<endl;
    cout<<"key"<<"  "<<"value"<<endl;
    cout<<"-----------------------------"<<endl;
    for(auto i:op)
    {
        cout<<i.first<<" | "<<i.second<<endl;
    }
    cout<<"-----------------------------"<<endl;
    sort(a,a+n);
    for(int i=n-1;i>1;i--)
    {
        for(int j=0;j<i&& a[j]<=sqrt(a[i]);j++)
        {
            if(a[i]%a[j]==0)
            {
                int result=a[i]/a[j];
                if(result!=a[j]&&result!=a[i] && op[result]>0)
                {
                    return a[i];
                }
                else if(result==a[j] && op[result]>1)
                {
                    return a[i];
                }
            }
        }
    }
    return -1;
}
int main() 
{
    // int a[] = { 17, 2, 5, 10 };
    int a[] = {30, 10, 9, 3, 35};
    int n = sizeof(a) / sizeof(int);
    sort(a,a+n);
    
    cout<<"max product present in array : "<<endl;
    cout<<pair_great_product(a,n);
    return 0;
}
/* OUTPUT : 
max product present in array : 
-----------------------------
key  value
-----------------------------
30 | 1
10 | 1
35 | 1
9  | 1
3  | 1
-----------------------------
30
*/

