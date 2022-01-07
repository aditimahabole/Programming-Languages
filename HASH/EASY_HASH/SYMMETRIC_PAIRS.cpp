//https://www.geeksforgeeks.org/given-an-array-of-pairs-find-all-symmetric-pairs-in-it/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int find_pair(int arr[][2],int n)
{
    unordered_map<int,int>mapy;
    int i1,i2;
    for(int i=0;i<n;i++)
    {
        i1=arr[i][0];
        i2=arr[i][1];
 //mapy.find(i2)!=mapy.end() THIS ENSURES THAT ELEMENT arr[i][1] IS PRESENT in mapy
        if(mapy.find(i2)!=mapy.end() && mapy[i2]==i1)
        {
            cout<<"( "<<i2<<" , "<<i1<<" )"<<endl;
        }
        else
        {
          // if not present then simply insert
            mapy[i1]=i2;
        }
    }
   
   
    
}
int main() 
{
  int arr[][2] = {{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}};
  int n=sizeof(arr)/sizeof(arr[0]);
  find_pair(arr,n);
  
  
  return 0;
}
/*
OUTPUT : 
( 30 , 40 )
( 5 , 10 )
*/
