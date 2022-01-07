//https://www.geeksforgeeks.org/group-multiple-occurrence-of-array-elements-ordered-by-first-occurrence/
//HERE FIRST I MADE POSITION MAP IN WHICH INDEX IS ELEMENT AND  VALUE IS POSITION
//THEN I SORTED UNORDERED MAP ACCRODING TO POSITION SO THAT JISKA POS PEHLE HO VO PEHLE AAYE
//THEN I ALSO MADE COUNT MAP IN WHICH COUNT WAS STORED
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int asscend_pos(pair<int,int>a, pair<int,int>b)
{
    return a.second<b.second;
}
void multiple_occurrence(int arr[],int n)
{
    unordered_map<int,int> counts;
    unordered_map<int,int> posi;
    for(int i=0;i<n;i++)
    {
        if(posi.find(arr[i])==posi.end())
        {
            posi[arr[i]]=i;
        }
        counts[arr[i]]++;

    }
    int k=0;
    vector<pair<int,int>>map_pos(posi.begin(),posi.end());
    sort(map_pos.begin(),map_pos.end(),asscend_pos);

    for(int i=0;i<map_pos.size();i++)
    {
        k=counts[map_pos[i].first];
        while(k>0)
        {
            cout<<map_pos[i].first<<" ";
            k--;
        }
    }
}

int main()
{
    int arr[] = {5, 3, 5, 1, 3, 3};

    int n=sizeof(arr)/sizeof(arr[0]);

    multiple_occurrence(arr,n);

    return 0;
}
//OUTPUT : 5 5 3 3 3 1
