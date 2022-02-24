
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int sort_distance(pair<pair<int,int>,float>a,pair<pair<int,int>,float>b)
{
    return  a.second<b.second;
}
int main() 
{
vector<pair<pair<int,int>,float>>v;
int n = 3;
int k=2;
for(int i=0;i<n;i++)
{
    int x,y;
    cout<<"Enter x and y"<<endl;
    cin>>x>>y;
    float d=sqrt(x*x +y*y);
    v.push_back(make_pair(make_pair(x,y),d));
}
cout<<"___________________________________________"<<endl;
for(int i=0;i<v.size();i++)
{
    cout<<v[i].first.first<<" , "<<v[i].first.second<<endl;
    cout<<"  distance = "<<v[i].second<<endl;
}
cout<<"___________________________________________"<<endl;
sort(v.begin(),v.end(),sort_distance);
cout<<"___________________________________________"<<endl;
for (int i=0;i<k;i++)
{
    cout<<v[i].first.first<<" , "<<v[i].first.second<<endl;
    cout<<"  distance = "<<v[i].second<<endl;
}
cout<<"___________________________________________"<<endl;

    return 0;
}
/*
/tmp/2RBRuZHBa4.o
Enter x and y
3 3
Enter x and y
5 -1
Enter x and y
2 4
___________________________________________
3 , 3
  distance = 4.24264
5 , -1
  distance = 5.09902
2 , 4
  distance = 4.47214
___________________________________________
___________________________________________
3 , 3
  distance = 4.24264
2 , 4
  distance = 4.47214
___________________________________________
*/
