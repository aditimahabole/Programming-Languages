//https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
int sum_subarray(int a[],int n,int sum)
{
   unordered_map<int,int>presum;
   int k=0;
   int cursum=0;
   for(int i=0;i<n;i++)
   {
       cout<<"-----------------------------------------"<<endl;
       cursum+=a[i];
       cout<<"a[i]       = "<<a[i]<<endl;
       cout<<"cursum     = "<<cursum<<endl;
       cout<<"sum        = "<<sum<<endl;
       cout<<"cursum-sum = "<<cursum-sum<<endl;
       cout<<"-----------------------------------------"<<endl;
       if(cursum==sum)
       {
           cout<<"-----------------------------------------"<<endl;
           cout<<"when cursum==sum BEFORE k = "<<k<<endl;
           k++;
           cout<<"when cursum==sum AFTER  k = "<<k<<endl;
           cout<<"-----------------------------------------"<<endl;
       }
       if(presum.find(cursum-sum)!=presum.end())
       {
           cout<<"-----------------------------------------"<<endl;
           cout<<"presum[cursum-sum] = "<<presum[cursum-sum]<<endl;
           cout<<"cursum-sum         = "<<cursum-sum<<endl;
           cout<<"before k           = "<<k<<endl;
           
           k=k+presum[cursum-sum];
           cout<<"after k            = "<<k<<endl;
           cout<<"-----------------------------------------"<<endl;
           
       }
       cout<<"-----------------------------------------"<<endl;
       cout<<"Before presum[cursum] = "<<presum[cursum]<<endl;
       presum[cursum]++;
       cout<<"cursum                = "<<cursum<<endl;
       cout<<"After presum[cursum]  = "<<presum[cursum]<<endl;
       cout<<"-----------------------------------------"<<endl;
   }
  return k;
}
int main()
{
int a[]={ 10, 2, -2, -20, 10 };
int n=sizeof(a)/sizeof(a[0]);
int sum=-10;
cout<<sum_subarray(a,n,sum);
return 0;
}
/*OUTPUT :
-----------------------------------------
a[i]       = 10
cursum     = 10
sum        = -10
cursum-sum = 20
-----------------------------------------
-----------------------------------------
Before presum[cursum] = 0
cursum                = 10
After presum[cursum]  = 1
-----------------------------------------
-----------------------------------------
a[i]       = 2
cursum     = 12
sum        = -10
cursum-sum = 22
-----------------------------------------
-----------------------------------------
Before presum[cursum] = 0
cursum                = 12
After presum[cursum]  = 1
-----------------------------------------
-----------------------------------------
a[i]       = -2
cursum     = 10
sum        = -10
cursum-sum = 20
-----------------------------------------
-----------------------------------------
Before presum[cursum] = 1
cursum                = 10
After presum[cursum]  = 2
-----------------------------------------
-----------------------------------------
a[i]       = -20
cursum     = -10
sum        = -10
cursum-sum = 0
-----------------------------------------
-----------------------------------------
when cursum==sum BEFORE k = 0
when cursum==sum AFTER  k = 1
-----------------------------------------
-----------------------------------------
Before presum[cursum] = 0
cursum                = -10
After presum[cursum]  = 1
-----------------------------------------
-----------------------------------------
a[i]       = 10
cursum     = 0
sum        = -10
cursum-sum = 10
-----------------------------------------
-----------------------------------------
presum[cursum-sum] = 2
cursum-sum         = 10
before k           = 1
after k            = 3
-----------------------------------------
-----------------------------------------
Before presum[cursum] = 0
cursum                = 0
After presum[cursum]  = 1
-----------------------------------------
3
*/
