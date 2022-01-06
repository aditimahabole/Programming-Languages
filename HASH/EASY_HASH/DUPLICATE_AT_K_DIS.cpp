//PROBLEM:
//https://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void duplicate_at_distance_k(int arr[],int n, int k)
{
    int dis;
    unordered_map<int,int> momo;
    unordered_map <int,int> count;
    // unordered_map <int,int> dist;
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
        if(momo.find(arr[i])==momo.end())
        {
            momo[arr[i]]=i;
            
        }
        else 
        {
            
            dis=i-momo[arr[i]];
            if(dis==k)
            {
                if(count[arr[i]]>=2)
                {
                    cout<<arr[i]<<" has duplicates = "<<count[arr[i]]<<" and is at distance "<<k<<endl;
                }
                
            }
            else if(dis!=k)
            {
                if(count[arr[i]]>=2)
                {
                    cout<<arr[i]<<" has duplicates = "<<count[arr[i]]<<" but is Not at  distance "<<k<<endl;
                }
                else
                {
                    cout<<arr[i]<<" has No duplicates = "<<" Also  Not at  distance "<<k<<endl;
                }
            }
        }
    }
}

int main() {
   int n,k;
  int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
//   int arr[] = {1, 2, 3, 1, 4, 5,1};
//   int arr[] = {1, 2, 3, 4, 5};
//   int arr[] = {1, 2, 3, 4, 4};
   n=sizeof(arr)/sizeof(arr[0]);
   cout<<"ENTER K : "<<endl;
   cin>>k;
   duplicate_at_distance_k(arr,n,k);
   return 0;
}
/* OUTPUT: 
ENTER K : 
3
1 has duplicates = 2 but is Not at  distance 3
2 has duplicates = 2 but is Not at  distance 3
3 has duplicates = 2 but is Not at  distance 3
4 has duplicates = 2 but is Not at  distance 3
*/
// OTHER CODE

/*
#include<bits/stdc++.h>
using namespace std;
bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    // Creates an empty hashset
    unordered_set<int> myset;

    // Traverse the input array
    for (int i = 0; i < n; i++)
    {
        // If already present n hash, then we found
        // a duplicate within k distance
        if (myset.find(arr[i]) != myset.end())
            return true;

        // Add this item to hashset
        myset.insert(arr[i]);

        // Remove the k+1 distant item
        if (i >= k)
            myset.erase(arr[i-k]);
    }
    return false;
}

// Driver method to test above method
int main ()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkDuplicatesWithinK(arr, n, 3))
        cout << "Yes";
    else
        cout << "No";
}*/
