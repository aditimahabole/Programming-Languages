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
 //////////////////DESCEND///////////////////////
void merge_sort_compile_descend(int *arr,int start,int mid,int end)
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
       
        if (arr1[i1]>=arr2[i2])
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
    while (i2 < size_arr2) 
    {
        
        arr[im] = arr2[i2];
        i2++;
        im++;
    }
    while (i1 < size_arr1) 
    {
        arr[im] = arr1[i1];
        i1++;
        im++;
    }
}
void merge_sort_breakdown_descend(int arr[],int start,int end)
{
    int mid=start + (end - start)/2;
    if (start >= end)
    {
        return ;
    }
    else 
    {
    merge_sort_breakdown_descend(arr,start,mid);
    
    merge_sort_breakdown_descend(arr,mid + 1,end);
    
    merge_sort_compile_descend(arr,start,mid,end);
    }
   
 }
 //////////////////ASCEND///////////////////////
 void merge_sort_compile_ascend(int *arr,int start,int mid,int end)
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
        arr[im] = arr1[i1];
        i1++;
        im++;
    }
     while (i2 < size_arr2) 
    {
        
        arr[im] = arr2[i2];
        i2++;
        im++;
    }
}
void merge_sort_breakdown_ascend(int arr[],int start,int end)
{
    int mid=start + (end - start)/2;
    if (start >= end)
    {
        return ;
    }
    else 
    {
    merge_sort_breakdown_ascend(arr,start,mid);
    
    merge_sort_breakdown_ascend(arr,mid + 1,end);
    
    merge_sort_compile_ascend(arr,start,mid,end);
    }
   
 }

int main() 
{
    int arr[]={3, 1, 2, 4, 5, 9, 13, 14, 12};
    // int arr[]={0,1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    int e=0;
    int o=0;
    int o1=0;
    if(n%2==0)
    {
        o=n/2;
        o1=o;
    }
    else if(n%2==1)
    {
        o=(n/2)+1;
        o1=o;
    }
    int arr1[n];
    for(int i=0;i<n ;i++)
    {
        if(i%2==0)
        {
            e=i/2;
            arr1[e]=arr[i];
            e++;
        }
        else
        {
            arr1[o]=arr[i];
            o++;
        }
    }
    cout<<endl;
    display(arr1,n);
    cout<<endl;
    merge_sort_breakdown_ascend(arr1,0,e - 1);
    merge_sort_breakdown_descend(arr1,o1,n - 1);
    display(arr1,n);
    cout<<"code by ADITI MAHABOLE"<<endl;
    return 0;
}
/* OUTPUT
3 1 2 4 5 9 13 14 12 
3 2 5 13 12 1 4 9 14 
2 3 5 12 13 14 9 4 1 

-------------------

0 1 2 3 4 5 6 7 
0 2 4 6 1 3 5 7 
0 2 4 6 7 5 3 1 
*/
