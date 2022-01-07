//https://www.geeksforgeeks.org/find-top-three-repeated-array/
//TO LEARN HOW TO SORT UNORDERED_MAP THEN LINK IS: 
//https://youtu.be/viOV5NMbLxE
//ITERATORS IN VECTORS :https://www.geeksforgeeks.org/iterators-c-stl/

#include <bits/stdc++.h>
using namespace std;

int cmp1(pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}

vector<int> max_three(const int arr[], int n)
{
    unordered_map<int,int> counts;
    unordered_map<int,int> posi;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(posi.find(arr[i])==posi.end())
        {
            posi[arr[i]]=i;
        }
        counts[arr[i]]++;
    }
    int max=0;
    int k=0;
    for(auto i: counts)
    {
        if(i.second>max)
        {
            max=i.second;
        }
    }
    //to sort unsorted_map first sotre it in vector
    //i named that vector as sort_map
    vector<pair<int,int>> sort_map(counts.begin(),counts.end());
    sort(sort_map.begin(),sort_map.end(),cmp1);

    for(int i=0;i<sort_map.size();i++)
    {
        if(sort_map[i].second<=max)
        {
            v.push_back(sort_map[i].first);
        }
        k++;
        if(k==3)
        {
            break;
        }
    }
    vector<int>::iterator i;
    for( i=v.begin();i!=v.end();i++)
    {
        if(counts[*i] == counts[*(i+1)])
        {
            if(posi[*i]>posi[*(i+1)])
            {
                swap(*i,*(i+1));
            }
        }
    }
    return v;

}
int main()
{
//int arr[] ={3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3} ;
int arr[]={2, 4, 3, 2, 3, 4, 5, 5, 3, 2, 2, 5};
	int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v1=max_three(arr,n);
    vector<int>::iterator it;
    cout<<"Final Ans : "<<endl;
    for(it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}
/*OUTPUT:
int arr[] ={3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3} ;
3 15 16
int arr[]={2, 4, 3, 2, 3, 4, 5, 5, 3, 2, 2, 5};
2 3 5
*/



