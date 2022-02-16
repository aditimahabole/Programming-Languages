
#include <bits/stdc++.h>
using namespace std;
int color_sort(pair<int,string>a,pair<int,string>b)
{
    return a.second.length()<b.second.length();
}
int main()
{
    vector<pair<int,string>>v;
    int n=5;
    int index;
    string color;
     for(int i=0;i<n;i++)
    {
        cout<<"enter index and color"<<endl;
        cin>>index>>color;
        v.push_back(make_pair(index,color));
    }
    sort(v.begin(),v.end(),color_sort);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<"   "<<v[i].second<<endl;
    }
    
    return 0;
}
