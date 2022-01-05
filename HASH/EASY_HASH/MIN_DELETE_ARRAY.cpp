//https://www.geeksforgeeks.org/minimum-delete-operations-make-elements-array/

#include <bits/stdc++.h>
using namespace std;
//logic is to count the frequency of each element 
//and find the max frequency matlab kiske jyada element present hai
//so baki jo element ke count honge matlab vo jarurat nhi so n-max frequncy kardenge

int min_deletion(int arr[],int n)
{
    unordered_map<int,int> count;
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    int max_count=INT_MIN;
    for(auto i=count.begin();i!=count.end();i++)
    {
        max_count=max(max_count,i->second);
    }
    return n-max_count;//this will be the min deleltion to make array same type
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
    cout<<"Minimum number of Deletions are = "<<min_deletion(arr,n)<<endl;
    
    
    return 0;
}
/*OUTPUT : 
/tmp/LEa6EeYBeM.o
ENTER SIZE : 
6
ENETER ELEMENTS : 
4
3
4
4
2
4
YOUR ARRAY : 
4  3  4  4  2  4  
Minimum number of Deletions are = 2
//HERE 3 AND 2 SHOULD BE DELETED
*/
