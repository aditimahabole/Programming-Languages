//CODE BY ADITI MAHABOLE 20103023
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void display(int arr[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int merge_sort_compile(int *arr,int start,int mid,int end,int count)
{
    int size_arr1=mid-start + 1;
    int size_arr2=end-mid;
    
    int arr1[size_arr1];
    int arr2[size_arr2];
    
    for(int i=0;i<size_arr1;i++)
    {
        arr1[i]=arr[start + i];
    }
    for(int j=0;j<size_arr2;j++)
    {
        arr2[j]=arr[mid + 1 + j];
    }
    int i1=0;
    int i2=0;
    int im=start;
    while(i1<size_arr1 && i2<size_arr2)
    {
        count++;
        if (arr1[i1]<=arr2[i2])
        {
            arr[im]=arr1[i1];
            i1++;
        }
        else
        {
            arr[im]=arr2[i2];
            i2++;
        }
        im++;
    }
    
    while (i1 < size_arr1) 
    {
        count++;
        arr[im] = arr1[i1];
        i1++;
        im++;
    }
    while (i2 < size_arr2) 
    {
        count++;
        arr[im] = arr2[i2];
        i2++;
        im++;
    }
    return count;
}
int main() 
{
    int arr[]={-4 , 6, 9 , -1 , 3 };
    // int arr[]={ 2 ,3 , 8 ,-1 ,7 ,10 };
    
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    cout<<endl;
    int e=0;
    int o=0;
    int o1=0;
    if(n%2==0)
    {
        o=(n/2)-1;
        o1=o;
    }
    else if(n%2==1)
    {
        o=(n/2);
    }
    int count =0;
    cout<<merge_sort_compile(arr,0,o,n - 1,count)<<" = are the comparisons"<<endl;
    display(arr,n);
cout<<"Code by Aditi Mahabole "<<endl;
    return 0;
}
/*
OUTPUT :
-4 6 9 -1 3 
5 = are the comparisons
-4 -1 3 6 9 
*/
