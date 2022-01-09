//https://www.geeksforgeeks.org/find-distinct-elements-common-rows-matrix/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
void common_ele_in_all_row(int a[][5],int r,int c)
{
    //jo element 1st row me present hoga sirf wahi baki me prsent hona chhiaye
    //kyuki jo secon 3 ya 4th row me present hoga uski garuntee thodi ki vo 1st me ho
    //iisliye 1st roww ko lekar chaalenge
   unordered_map<int,int> so;
   unordered_map<int,int> count;
   
   for(int i=0;i<c;i++)
   {
       so[a[0][i]]=1;
   }
   for(int i=1;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           
           if(so[a[i][j]] == i)
           {
               so[a[i][j]]=i+1;
               
               if(i==r-1 && so[a[i][j]]==r)
               {
                   count[a[i][j]]++;
               }
           }
       }
   }
   cout<<"----------------------"<<endl;
   for(auto i :count)
   {
       cout<<i.first<<" ";
   }
   cout<<endl;
   cout<<"----------------------"<<endl;
}

int main()
{
// int c=4;
// int a[][4]=
// {
//     {2, 1, 4, 3},
//     {1, 2, 3, 2},  
//     {3, 6, 2, 3},  
//     {5, 2, 5, 3}
// };
int c=5;
int a[][5]=
{
    {12, 1, 14, 3, 16},
    {14, 2, 1, 3, 35},  
    {14, 1, 14, 3, 11},  
    {14, 25, 3, 2, 1},
    {1, 18, 3, 21, 14}
};
int r=sizeof(a)/sizeof(a[0]);
common_ele_in_all_row(a,r,c);
    return 0;
}
/* OUTPUT:
----------------------
3 14 1 
----------------------
*/
