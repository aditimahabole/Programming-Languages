// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set<int>s;
void dp(vector<int>&sp,int k,int i,int n,int &tot)
{
    if(i>=n) return;
     if(s.find(sp[i])!=s.end())
    {
        tot=0;
        s.clear();
        return;
    }
    if(k==0)
    {
        s.clear();
        return;
    }

    else if(s.find(sp[i])==s.end())
    { 
        tot+=sp[i];
        s.insert(sp[i]);
        
    }
    cout<<"curr value : "<<sp[i]<<endl;
    dp(sp,k-1,i+1,n,tot);
}
int main() {
   vector<int>stockPrice = {1,2,7,7,4,3,6};
   int k=3;
   int n = stockPrice.size();
   int sum =0;
   int tot = 0;
   int j;
   for(int i=0;i<n-k+1;i++)
   {
       tot=0;
       j=k;
       cout<<stockPrice[i]<<endl;
       dp(stockPrice,j,i,n,tot);
       sum = max(tot,sum);
   }
   cout<<sum<<endl;
 return 0;
}
