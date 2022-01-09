//https://www.geeksforgeeks.org/sort-elements-frequency-set-4-efficient-approach-using-hash/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
//  The cumulative frequency is calculated by adding each frequency from a frequency distribution table to the sum of its predecessors.
int pos(pair<int,int>a,pair<int,int>b)
{
    return a.second>b.second;
}
int fre(int a1[],int n1)
{
   unordered_map<int,int>count;
   unordered_map<int,int>posi;
   
  for(int i=0;i<n1;i++)
  {
      if(posi.find(a1[i])==posi.end())
      {
          posi[a1[i]]=i;
      }
      count[a1[i]]++;
  }
  vector<pair<int,int>>v(count.begin(),count.end());
  sort(v.begin(),v.end(),pos);
  int cf=0;
  for(int i=0;i<v.size();i++)
  {
      for(int j=i+1;j<v.size();j++)
      {
          if(v[i].second==v[j].second)
          {
              if(posi[v[i].first]>posi[v[j].first])
              {
                  swap(v[i].first,v[j].first);
              }
          }
      }
  }
  int m=0;
  for(int i=0;i<v.size();i++)
  {
      m=count[v[i].first];
      while(m>0)
      {
           cout<<v[i].first<<"  ";
           m--;
      }
     
  }
}
int main()
{
// int a[]={6, 2, 4, 12, 5, 3};
int a1[] = {2, 5, 2, 8, 5, 6, 8, 8};
int n1=sizeof(a1)/sizeof(a1[0]);
cout<<"-----------------ARRAY1------------------"<<endl;
for(int i =0;i<n1;i++)
{
    cout<<a1[i]<<"  ";
}
cout<<endl;
cout<<"-----------------------------------------"<<endl;
fre(a1,n1);

return 0;
}
/*
OUTPUT :
-----------------ARRAY1------------------
2  5  2  8  5  6  8  8  
-----------------------------------------
8  8  8  2  2  5  5  6  
*/
