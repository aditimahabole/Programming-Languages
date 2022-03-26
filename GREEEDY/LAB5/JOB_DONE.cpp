// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void select_task(vector<int>s,vector<int>f)
{
    vector<pair<int,int>>yay;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
    for(int i=0;i<s.size();i++)
    {
        heap.push(make_pair(f[i],s[i]));
    }
    auto it=heap.top();
    int start=it.second;
    int end=it.first;
    heap.pop();
    yay.push_back(make_pair(start,end));
    while(!yay.empty())
    {
        auto i=heap.top();
        heap.pop();
        if(i.second>=end)
        {
            start=i.second;
            end=i.first;
            yay.push_back(make_pair(start,end));
        }
    }
    cout<<"FOLLOWING TASK CAN BE DONE!"<<endl;
    for(auto j=yay.begin();j!=yay.end();j++)
    {
        cout<<"TASK STARTS : " <<(*j).first<<" TASK ENDS  " <<(*j).second<<endl;
    }
    
}


int main() {
    vector<int>s = {1, 3, 0, 5, 8, 5};
    vector<int>f = {2, 4, 6, 7, 9, 9};
    select_task(s,f);

    return 0;
}
