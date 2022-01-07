//FOR HELP: 
//https://www.youtube.com/watch?v=viOV5NMbLxE
//SORTING A VECTOR PAIR
//https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/
#include <bits/stdc++.h>
using namespace std;

int descend_value(pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}
int assend_value(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
// int assend_key(pair<int,int>a,pair<int,int>b)
// {
//     return a.first<b.first;
// }
// int descend_key(pair<int,int>a,pair<int,int>b)
// {
//     return a.first>b.first;
// }

void make_map(int arr[],int n)
{
    unordered_map<int,int>count_map;
    for(int i=0;i<n;i++)
    {
        count_map[arr[i]]++;
    }
    cout<<" KEYS"<<"  "<<"VALUES"<<endl;
    for(auto i: count_map)
    {
        cout<<i.first<<"     "<<i.second<<endl;
    }
    //FOR SORTING UNORDERED_MAP FIRST STORE IN VECTOR
    vector<pair<int,int>> sort_map(count_map.begin(),count_map.end());
  //IF YOU WANT TO SORT ACCRODING TO VALUE THEN CHOOSE AMONG BELOW:
       sort(sort_map.begin(),sort_map.end(),assend_value);
    // sort(sort_map.begin(),sort_map.end(),descend_value);
  
    //IF YOU WANT TO SORT ACCRODING TO KEY THEN CHOOSE AMONG BELOW:
  
    // sort(sort_map.begin(),sort_map.end(),assend_key);
    // sort(sort_map.begin(),sort_map.end(),descend_key);
    cout<<"KEYS"<<"    "<<"VALUES"<<endl;
    for(int i=0;i<sort_map.size();i++)
    {
        cout<<sort_map[i].first<<"       "<<sort_map[i].second<<endl;
    }
    
}
int main()
{
    int arr[] ={3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3} ;
	int n=sizeof(arr)/sizeof(arr[0]);
	make_map(arr,n);
  	
}
/* OUTPUT : 
KEYS  VALUES
15     3
2     2
4     1
16     3
3     4
KEYS    VALUES
4       1
2       2
15       3
16       3
3       4
*/
