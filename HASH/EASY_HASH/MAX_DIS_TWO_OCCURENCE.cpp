//HASING CONCEPT : UNORDERED MAPS USED 
//https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/
#include <bits/stdc++.h>
using namespace std;
int max_distance(int arr[],int n)
{
    unordered_map<int,int> momo;
    int max_dis=0;
    for(int i=0;i<n;i++)
    {
         // if data is not present at that index then map.find(arr[i]) returns map.end() so if condition becomes true
        //if some data is present then it returns position which is not equal to map.end()
       //{here name momo is used instead of map so dont be confused}
        
        if(momo.find(arr[i])==momo.end())
        {
            momo[arr[i]]=i;
            cout<<"---------------------------------------"<<endl;
            cout<<"in if condition"<<endl;
            cout<<"value of arr[i] = "<<arr[i]<<endl;
            cout<<"value of i = "<<i<<endl;
            cout<<"value of momo[arr[i]] = "<<momo[arr[i]]<<endl; 
            
            cout<<"---------------------------------------"<<endl;
        }
        //else will work when uss index pe pehle se koi data present ho
        else
        {
            cout<<"---------------------------------------"<<endl;
            cout<<"in else condition"<<endl;
            cout<<"max d before change = "<<max_dis<<endl;
            cout<<"value of arr[i] = "<<arr[i]<<endl;
            cout<<"value of i = "<<i<<endl;
            cout<<"value of momo[arr[i]] = "<<momo[arr[i]]<<endl; 
            
            cout<<"---------------------------------------"<<endl;
           max_dis=max(max_dis,i-momo[arr[i]]);
           cout<<"---------------------------------------"<<endl;
           cout<<"max d after change = "<<max_dis<<endl;
           cout<<"i-momo[arr[i]] = "<<i-momo[arr[i]]<<endl;
           cout<<"---------------------------------------"<<endl;
           
           
        }
        
    }
    return max_dis;
}

int main()
{
    // int n,sum;
    // cout<<"ENTER SIZE : "<<endl;
    // cin>>n;
    // int arr[n];
    // cout<<"ENETER ELEMENTS : "<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    // cout<<endl;
    // cout<<"YOUR ARRAY : "<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<"  ";
    // }
    // cout<<endl;
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max distance  = \n"<<max_distance(arr,n)<<endl;
    
    
    return 0;
}
/* OUTPUT : 
Max distance  = 
---------------------------------------
in if condition
value of arr[i] = 3
value of i = 0
value of momo[arr[i]] = 0
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 2
value of i = 1
value of momo[arr[i]] = 1
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 1
value of i = 2
value of momo[arr[i]] = 2
---------------------------------------
---------------------------------------
in else condition
max d before change = 0
value of arr[i] = 2
value of i = 3
value of momo[arr[i]] = 1
---------------------------------------
---------------------------------------
max d after change = 2
i-momo[arr[i]] = 2
---------------------------------------
---------------------------------------
in else condition
max d before change = 2
value of arr[i] = 1
value of i = 4
value of momo[arr[i]] = 2
---------------------------------------
---------------------------------------
max d after change = 2
i-momo[arr[i]] = 2
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 4
value of i = 5
value of momo[arr[i]] = 5
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 5
value of i = 6
value of momo[arr[i]] = 6
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 8
value of i = 7
value of momo[arr[i]] = 7
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 6
value of i = 8
value of momo[arr[i]] = 8
---------------------------------------
---------------------------------------
in if condition
value of arr[i] = 7
value of i = 9
value of momo[arr[i]] = 9
---------------------------------------
---------------------------------------
in else condition
max d before change = 2
value of arr[i] = 4
value of i = 10
value of momo[arr[i]] = 5
---------------------------------------
---------------------------------------
max d after change = 5
i-momo[arr[i]] = 5
---------------------------------------
---------------------------------------
in else condition
max d before change = 5
value of arr[i] = 2
value of i = 11
value of momo[arr[i]] = 1
---------------------------------------
---------------------------------------
max d after change = 10
i-momo[arr[i]] = 10
---------------------------------------
10
*/
