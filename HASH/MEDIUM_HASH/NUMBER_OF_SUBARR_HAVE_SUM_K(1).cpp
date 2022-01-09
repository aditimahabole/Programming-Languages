// https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
//SAME QUESTION BUT IF WE HAVE TO GIVE INDEX TO START AND END 

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
// same Q but return  index
void sum_subarray(int a[],int n,int sum)
{
   unordered_map<int,int>presum;
   int cursum=0;
   int start=0;
   int end=-1;
   for(int i=0;i<n;i++)
   {
       cursum+=a[i];
       if(cursum-sum==0)
       {
           start=0;end=i;
            cout<<"-----------------------"<<endl;
            cout<<start<<" to "<<end<<endl;
            cout<<"-----------------------"<<endl;
          
       }
       if(presum.find(cursum-sum)!=presum.end())
       {
           start=presum[cursum-sum]+1;
           end=i;
            cout<<"-----------------------"<<endl;
            cout<<start<<" to "<<end<<endl;
            cout<<"-----------------------"<<endl;
           
       }
       presum[cursum]=i;
   }
   if(end==-1)
   {
       cout<<"not found"<<endl;
   }
 
  
}
int main()
{
int a[]={ 10,-10,2, -2, -20, 10,-5,-5 };
int n=sizeof(a)/sizeof(a[0]);
cout<<"-----------------------------------------"<<endl;
for(int i =0;i<n;i++)
{
    cout<<a[i]<<"  ";
}
int sum=-10;
cout<<endl;
cout<<"sum = "<<sum<<endl;
cout<<"-----------------------------------------"<<endl;

sum_subarray(a,n,sum);
return 0;
}
/* 
OUTPUT : 
-----------------------------------------
10  -10  2  -2  -20  10  -5  -5  
0    1   2   3   4   5    6   7
sum = -10
-----------------------------------------
-----------------------
1 to 1
-----------------------
-----------------------
1 to 3
-----------------------
-----------------------
0 to 5
-----------------------
-----------------------
4 to 5
-----------------------
-----------------------
6 to 7
-----------------------
*/
