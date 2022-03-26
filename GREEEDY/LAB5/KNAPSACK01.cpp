// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class mobile
{
    public:
    string name;
    int count;
    int profit;
    
};
bool pro(mobile a,mobile b)
    {
        if(a.profit>b.profit)
        {
            return true;
        }
        return false;
    }
pair<int,int> max_profit(mobile a[],int n,int max_count)
{
    pair<int,int>ans;
    int dp[5];
    dp[0]=a[0].count;
    cout<<"dp[i] "<<dp[0]<<endl;
  for(int i=1;i<5;i++)
  {
      dp[i]=dp[i-1]+a[i].count;
      cout<<"dp[i] "<<dp[i]<<endl;
      
  }
  int p=0;
    int i;
    for( i=0;i<n;i++)
    {
        if(dp[i]<40)
        {
            p=p+a[i].profit;
        }
        else
        {
            break;
        }
        
        
      
    }
    ans.first=dp[i-1];
    ans.second=p;
    return ans;
}

int main() 
{
    
    mobile a[5];
    int max_count=40;
    a[0].name="Redme Note 9";
    a[0].count=10;
    a[0].profit=20000;
    a[1].name="Samsung Galaxy M12";
    a[1].count=5;
    a[1].profit=10500;
    a[2].name="OnePlus 5";
    a[2].count=26;
    a[2].profit=89000;
    a[3].name="Realme Narzo 20 Pro";
    a[3].count=8;
    a[3].profit=4000;
    a[4].name="Xiaomi Poco M3";
    a[4].count=12;
    a[4].profit=23000;
    cout<<"----------------------------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i].name<<" | "<<a[i].count<<" | "<<a[i].profit<<endl;
    }
    cout<<"----------------------------------------"<<endl;
    sort(a,a+5,pro);
    for(int i=0;i<5;i++)
    {
        cout<<a[i].name<<" | "<<a[i].count<<" | "<<a[i].profit<<endl;
    }
    cout<<"----------------------------------------"<<endl;
    pair<int,int>a1=max_profit(a,5,max_count);
    cout<<"Max Weight = "<<a1.first<<endl;
    cout<<"Max Profit = "<<a1.second<<endl;
    
}
