// https://www.geeksforgeeks.org/count-pairs-with-given-sum/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
int sum_pair(int a[],int n,int sum)
{
   unordered_set<int>s;
  int c=0;
   for(int i=0;i<n;i++)
   {
       int sum1=sum-a[i];
       if(s.find(sum1)!=s.end())
       {
           cout<<"( "<<a[i]<<" , "<<sum1<<" )"<<endl;
           c++;
       }
       s.insert(a[i]);
   }
   cout<<endl;
   return c;
}
int main()
{
int a[]={1, 5, 7, -1};
int n=sizeof(a)/sizeof(a[0]);
int sum=6;
cout<<sum_pair(a,n,sum);
return 0;
}
/*
OUTPUT: 
( 5 , 1 )
( -1 , 7 )

2
*/

