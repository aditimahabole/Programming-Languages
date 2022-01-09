
//https://www.geeksforgeeks.org/find-pairs-given-sum-elements-pair-different-rows/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
void print_pair(int a[][4],int r,int c,int sum)
{
   unordered_map<int,int> so;
   for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           int rem_sum=sum-a[i][j];//remaining sum 
           
           if(so.find(rem_sum)!=so.end())//if its present in map
           {
               int row=so[rem_sum];//storing the position 
               if(row<i)//obio agar sum 11 hai to agar pehal ele 1 aya to vo map me to hoga nhi 
               //par jese aage badega aur 10 mila to rem_cum 11-10 that is 1 jo ki pehle se map (so) me store hai 
               //and obvio uska posiiton that is reo chota hi hoga 10 wali se because 10 niche hoga 
               {
                cout<<"("<<a[i][j]<<" , "<<rem_sum<<"), ";
               }
           }
           so[a[i][j]]=i;
       }
   }
}

int main()
{
int c=4;
int sum=11;
int a[][4]=
{
    {1, 3, 2, 4},
    {5, 8, 7, 6},
    {9, 10, 13, 11},
    {12, 0, 14, 15}
};
int r=sizeof(a)/sizeof(a[0]);
print_pair(a,r,c,sum);
    return 0;
}
//OUTPUT: (8 , 3), (7 , 4), (9 , 2), (10 , 1), (0 , 11), 

