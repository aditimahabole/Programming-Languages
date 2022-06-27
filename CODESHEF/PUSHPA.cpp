//https://www.codechef.com/submit/PUSH7PA

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    if(n==1)
	    {
	       cout<<arr[0]<<endl;;
	    }
	    else
	    {
	        
	        unordered_map<int,int>u;
	        for(int i=0;i<n;i++)
	        {
	            u[arr[i]]++;
	        }
	        vector<int>ans;
	        for(auto j:u)
	        {
	            int p=j.first+ j.second - 1;
	          
	            ans.push_back(p);
	        }
	        int a=0;
	        for(int i=0;i<ans.size();i++)
	        {
	            if(ans[i]>a)
	            {
	                a=ans[i];
	            }
	        }
	        
	        cout<<a<<endl;
	    }
	}
	return 0;
}
