// Online C++ compiler to run C++ program online
#include <iostream>
// #include <bits/stdc++.h>
using namespace std ;
void display(int arr[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void merge_sort_compile(int *arr,int start,int mid,int end)
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
    cout<<"|";
    for(int i=0;i<im;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"|"<<endl;
    
    
}
void merge_sort_breakdown(int arr[],int start,int end)
{
        int mid=start + (end - start)/2;
    if (start >= end)
    {
        cout<<"***********************"<<endl;
    
    cout<<"start = "<<start<<endl;
    cout<<"mid = "<<mid<<endl;
    cout<<"end = "<<end<<endl;
        cout<<"returned"<<endl;
        cout<<"***********************"<<endl;
        return;
    }
        

    cout<<" ______________________________"<<endl;
    cout<<"| ";
    for(int i=start;i<=end;i++)
    {
        cout<<arr[i]<<" , ";
    }
    cout<<"| ";
    cout<<endl;
    cout<<"------------------------"<<endl;
    cout<<"start = "<<start<<endl;
    cout<<"mid = "<<mid<<endl;
    cout<<"end = "<<end<<endl;
    cout<<"------------------------"<<endl;
    
    
    
    cout<<"---merge_sort_breakdown(start,mid)---"<<endl;
    merge_sort_breakdown(arr,start,mid);
    cout<<"---merge_sort_breakdown(mid+1,end)---"<<endl;
    merge_sort_breakdown(arr,mid + 1,end);
    cout<<"---merge_sort_compile---"<<endl;
    merge_sort_compile(arr,start,mid,end);
 cout<<" ______________________________"<<endl;
    
}


int main()
{
    int arr[]={20,334,51,1,4999};
    // int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    cout<<endl;
    merge_sort_breakdown(arr,0,n - 1);
    cout<<"FINAL ANSWER =>"<<endl;
    display(arr,n);
    
    return 0;
}


/* OUTPUT 

CODE BY ADITI MAHABOLE 20103023
20 334 51 1 4999 
 ______________________________
| 20 , 334 , 51 , 1 , 4999 , | 
------------------------
start = 0
mid = 2
end = 4
------------------------
---merge_sort_breakdown(start,mid)---
 ______________________________
| 20 , 334 , 51 , | 
------------------------
start = 0
mid = 1
end = 2
------------------------
---merge_sort_breakdown(start,mid)---
 ______________________________
| 20 , 334 , | 
------------------------
start = 0
mid = 0
end = 1
------------------------
---merge_sort_breakdown(start,mid)---
***********************
start = 0
mid = 0
end = 0
returned
***********************
---merge_sort_breakdown(mid+1,end)---
***********************
start = 1
mid = 1
end = 1
returned
***********************
---merge_sort_compile---
|20 334 |
 ______________________________
---merge_sort_breakdown(mid+1,end)---
***********************
start = 2
mid = 2
end = 2
returned
***********************
---merge_sort_compile---
|20 51 334 |
 ______________________________
---merge_sort_breakdown(mid+1,end)---
______________________________
| 1 , 4999 , | 
------------------------
start = 3
mid = 3
end = 4
------------------------
---merge_sort_breakdown(start,mid)---
***********************
start = 3
mid = 3
end = 3
returned
***********************
---merge_sort_breakdown(mid+1,end)---
***********************
start = 4
mid = 4
end = 4
returned
***********************
---merge_sort_compile---
|20 51 334 1 4999 |
 ______________________________
---merge_sort_compile---
|1 20 51 334 4999 |
 ______________________________
FINAL ANSWER =>
1 20 51 334 4999 

*/
