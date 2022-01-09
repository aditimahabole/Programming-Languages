//QUESTION CREATED BY ME
// FIND ELEMENT WHIHC ARE NOT COMMON TO ALL ROWS

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
void common_ele_in_all_row(int a[][5],int r,int c)
{
   unordered_map<int,int> so;
   unordered_map<int,int> let;
   
   for(int i=0;i<c;i++)
   {
       so[a[0][i]]=1;
       let[a[0][i]]=-1;
   }
   for(int i=1;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           let[a[i][j]]=-1;
           if(so[a[i][j]] == i)
           {
               so[a[i][j]]=i+1;
               
               if(i==r-1 && so[a[i][j]]==r)
               {
                   let[a[i][j]]=0;
               }
           }
       }
   }
   for(auto i :let)
   {
       if(i.second==-1)
       {
           cout<<i.first<<" ";
       }
   }
}

int main()
{
int c=5;

int a[][5]=
{
    {1, 2, 1, 4, 8},
    {3, 7, 8, 5, 1},
    {8, 7, 7, 3, 1},
    {8, 1, 2, 7, 9},
};
int r=sizeof(a)/sizeof(a[0]);
common_ele_in_all_row(a,r,c);
    return 0;
}
//OUTPUT: 9 5 7 3 4 2 
