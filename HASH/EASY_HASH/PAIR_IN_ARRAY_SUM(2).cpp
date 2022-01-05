//HASHING USED 
// Complexity Analysis:  
// Time Complexity: O(n). 
// As the whole array is needed to be traversed only once.
// Auxiliary Space: O(n). 
// A hash map has been used to store array elements.

//https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

#include <bits/stdc++.h>
using namespace std;
void print_pair(int arr[],int n,int sum)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        
        int temp=sum-arr[i];
        if(s.find(temp)!=s.end())//temp is found from start to end of hash map
        {
            cout<<"PAIR ("<<arr[i]<<" , "<<temp<<") exist"<<endl;
        }
        s.insert(arr[i]);
        // s={1} this is hashmap in which elements are stored like this according to loop
        // s={1,4}
        // s={1,4,45}
        // s={1,4,45,6}
        // s={1,4,45,6,10}
        // s={1,4,45,6,10,8}
    }
}

int main()
{
    int n,sum;
    cout<<"ENTER SIZE : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"ENETER ELEMENTS : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"YOUR ARRAY : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout<<"ENTER NUMBER : "<<endl;
    cin>>sum;
    cout<<endl;
    print_pair(arr,n,sum);
    
    return 0;
}
/*ENTER SIZE : 
6
ENETER ELEMENTS : 
1
4
45
6
10
8
YOUR ARRAY : 
1  4  45  6  10  8  
ENTER NUMBER : 
16
PAIR (10 , 6) exist
*/
