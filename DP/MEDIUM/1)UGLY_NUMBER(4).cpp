//https://www.geeksforgeeks.org/ugly-numbers/
//UGLY NUMBERS DIVISIBLE BY 2 3 5 
//USING BINARY SEARCH
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
int get_ugly(int n)
{
   int p[40]={1};
   for(int i=1;i<=30;i++)
   {
       p[i]=p[i-1]*2;
   }
   int l=1;
   int r=INT_MAX;
   int ans=-1;
   while(l<=r)
   {
       int mid=l+((r-l)/2);
       cout<<"mid = "<<mid<<endl;
       int count=0;
       for(int i=1;i<=mid;i*=5)
       {
           for(int j=1;j*i<=mid;j*=3)
           {
               count+=upper_bound(p,p + 31,mid/(i*j))-p;
           }
       }
       if(count<n)
       {
           l=mid+1;
       }
       else
       {
           r=mid-1;
           ans=mid;
       }
   }
   return ans;
   
}
int main() 
{
    int num=8;
    unsigned no=get_ugly(num);
    cout<<num<<"th ugly number is : "<<no;
    return 0;
}
