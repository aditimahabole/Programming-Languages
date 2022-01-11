//https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sor(pair<int,int>a,pair<int,int>b)
{

       if(a.first>b.first && a.second<b.second)
    {
        return a.first<b.first;
    }

    if(a.first>b.first && a.second==b.second)
    {
        return a.first>b.first;
    }
}
void most_occ_k(int arr[],int n,int k)
{
    unordered_map<int,int>count;
    for(int i=0;i<n;i++)
    {
       count[arr[i]]++;
    }
    vector<pair<int,int>>v(count.begin(),count.end());
    sort(v.begin(),v.end(),sor);

   for (int i = 0; i < k; i++)
   {

       cout << v[i].first << " ";
   }


}
int main()
{
    int arr[]={3, 1, 4, 4, 5, 2, 6, 1};
   // int arr[]={7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
   int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    most_occ_k(arr,n,k);
    return 0;
}
//4 1
