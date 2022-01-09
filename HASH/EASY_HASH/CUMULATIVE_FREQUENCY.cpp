//https://www.geeksforgeeks.org/cumulative-frequency-of-count-of-each-element-in-an-unsorted-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
//  The cumulative frequency is calculated by adding each frequency from a frequency distribution table to the sum of its predecessors.
int pos(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
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
  vector<pair<int,int>>v(posi.begin(),posi.end());
  sort(v.begin(),v.end(),pos);
  int cf=0;
  for(int i=0;i<v.size();i++)
  {
      cout<<v[i].first<<"->"<<count[v[i].first]+cf<<endl;
      cf+=count[v[i].first];
  }
}
int main()
{
// int a[]={6, 2, 4, 12, 5, 3};
int a1[] = { 1, 3, 2, 4, 2, 1 };
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
/* OUTPUT 
-----------------ARRAY1------------------
1  3  2  4  2  1  
-----------------------------------------
1->2
3->3
2->5
4->6
*/
