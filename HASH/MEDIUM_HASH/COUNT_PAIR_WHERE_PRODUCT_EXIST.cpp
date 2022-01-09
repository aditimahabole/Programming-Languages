//https://www.geeksforgeeks.org/count-pairs-whose-products-exist-in-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
// same Q but return subarray with max length

int product_pair(int a[],int n)
{
   unordered_set<int>s;
   int count=0;
  for(int i=0;i<n;i++)
  {
      s.insert(a[i]);
  }
  sort(a,a+n);
 
 for(int i=0;i<n;i++)
 {
     for(int j=i+1;j<n;j++)
     {
         int pro=a[i]*a[j];
         if(s.find(pro)!=s.end())
         {
             cout<<"( "<<a[i]<<" , "<<a[j]<<" )"<<endl;
             count++;
         }
     }
 }
 return count;
  
}
int main()
{
// int a[]={6, 2, 4, 12, 5, 3};
int a[]= {3, 5, 2, 4, 15, 8};
int n=sizeof(a)/sizeof(a[0]);
cout<<"-----------------------------------------"<<endl;
for(int i =0;i<n;i++)
{
    cout<<a[i]<<"  ";
}

cout<<endl;

cout<<"-----------------------------------------"<<endl;

cout<<product_pair(a,n)<<" total pairs "<<endl;
return 0;
}
/* OUTPUT 
-----------------------------------------
3  5  2  4  15  8  
-----------------------------------------
( 2 , 4 )
( 3 , 5 )
2 total pairs 
*/
