//https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
//SAME Q BUT THIS TIME WE ARE TU RETURN INDEX WITH LARGEST LENGTH

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
// same Q but return subarray with max length

void sum_subarray(int a[],int n,int sum)
{
   unordered_map<int,int>presum;
   int max_len=0;
   int s=0;
   int e=0;
   int cursum=0;
   int start=0;
   int end=-1;
   for(int i=0;i<n;i++)
   {
       cursum+=a[i];
       int sub=end-start;
       if(cursum-sum==0)
       {
           start=0;end=i;
           
            cout<<"-----------------------"<<endl;
            cout<<start<<" to "<<end<<endl;
            cout<<"-----------------------"<<endl;
            if(sub>max_len)
       {
           max_len=sub;
           s=start;
           e=end;
       }
      
       }
       if(presum.find(cursum-sum)!=presum.end())
       {
           start=presum[cursum-sum]+1;
           end=i;
            cout<<"-----------------------"<<endl;
            cout<<start<<" to "<<end<<endl;
            cout<<"-----------------------"<<endl;
            if(sub>max_len)
       {
           max_len=sub;
           s=start;
           e=end;
       }
           
             
       }
       
       presum[cursum]=i;
     
   }
   if(end==-1)
   {
       cout<<"not found"<<endl;
   }
   else
   {
       cout<<"final ans = "<<s<<" to "<<e<<endl;
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
OUTPUT:
-----------------------------------------
10  -10  2  -2  -20  10  -5  -5  
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
final ans = 0 to 5
*/
