
//https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
// same Q but return subarray with max length

int sum_pair(int a1[],int a2[],int n1,int n2,int sum)
{
   unordered_set<int>s;
   int count=0;
  for(int i=0;i<n1;i++)
  {
      s.insert(a1[i]);
  }
  
 
 for(int i=0;i<n2;i++)
 {
     int x=sum-a2[i];
     if(s.find(x)!=s.end())
     {
         cout<<"( "<<a2[i]<<" , "<<x<<" )"<<endl;
         count++;
     }
 }
 return count;
  
}
int main()
{
// int a[]={6, 2, 4, 12, 5, 3};
int a1[] = {-1, -2, 4, -6, 5, 7};
int a2[] = {6, 3, 4, 0};
int sum=8;
int n1=sizeof(a1)/sizeof(a1[0]);
int n2=sizeof(a2)/sizeof(a2[0]);
cout<<"-----------------ARRAY1------------------"<<endl;
for(int i =0;i<n1;i++)
{
    cout<<a1[i]<<"  ";
}

cout<<endl;

cout<<"-----------------------------------------"<<endl;
cout<<"-----------------ARRAY2------------------"<<endl;
for(int i =0;i<n2;i++)
{
    cout<<a2[i]<<"  ";
}

cout<<endl;

cout<<"-----------------------------------------"<<endl;

cout<<sum_pair(a1,a2,n1,n2,sum)<<" total pairs "<<endl;
return 0;
}
/*-----------------ARRAY1------------------
-1  -2  4  -6  5  7  
-----------------------------------------
-----------------ARRAY2------------------
6  3  4  0  
-----------------------------------------
( 3 , 5 )
( 4 , 4 )
2 total pairs 
*/
