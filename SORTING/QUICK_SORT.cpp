
#include <iostream>
#include <stdlib.h> 
#include <bits/stdc++.h>
using namespace std ;
void display(int arr[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int partition(int *arr,int low,int high)
{
    
    int pivot = arr[high]; 
    cout<<"high = "<<high<<endl;
    cout<<"arr["<<high<<"] = "<<arr[high]<<endl;
    cout<<"pivot = "<<pivot<<endl;
    int i = (low - 1); 
    cout<<"i = "<<i<<endl;
 
    for (int j = low; j <= high - 1; j++)
    {
        cout<<"j = "<<j<<endl;
        cout<<"arr["<<j<<"] = "<<arr[j]<<endl;
        cout<<"pivot = "<<pivot<<endl;
        if (arr[j] < pivot)
        {
            cout<<"i = "<<i<<endl;
            i++; 
            cout<<"i++ = "<<i<<endl;
        cout<<arr[i]<<" and "<<arr[j]<<" swapped"<<endl;
            swap(arr[i],arr[j]);
        }
    }
    cout<<arr[i +1 ]<<" and "<<arr[high]<<" swapped"<<endl;
    swap(arr[i + 1], arr[high]);
    cout<<"i + 1 = "<<i + 1<<endl;
    
    return (i + 1);
}
 void quick_sort(int *arr,int low,int high)
 {
      if (low < high)
    {
        cout<<"----------------"<<endl;
        cout<<"low  = "<<low<<endl;
        cout<<"high = "<<high<<endl;
        cout<<"----------------"<<endl;
        cout<<"----------------"<<endl;
        int pi = partition(arr, low, high);
        cout<<"pi = "<<pi<<endl;
        cout<<"----------------"<<endl;
        cout<<"----------------"<<endl;
        cout<<"quick_sort(arr,low, pi-1) called-->"<<endl;
        quick_sort(arr, low, pi - 1);
        cout<<"----------------"<<endl;
        cout<<"----------------"<<endl;
        cout<<"quick_sort(arr, pi+1,high)called-->"<<endl;
        quick_sort(arr, pi + 1, high);
        cout<<"----------------"<<endl;
    }
 }
int main()
{
    int n=rand() % 10 + 1;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%1000 + 1;
    }
    display(arr,n);
    cout<<endl;
    quick_sort(arr,0,n - 1);
    cout<<"FINAL ANSWER =>"<<endl;
    display(arr,n);
    
    return 0;
}
/* OUTPUT

/tmp/bN69JIlnL0.o
887 778 916 794 
----------------
low  = 0
high = 3
----------------
----------------
high = 3
arr[3] = 794
pivot = 794
i = -1
j = 0
arr[0] = 887
pivot = 794
j = 1
arr[1] = 778
pivot = 794
i = -1
i++ = 0
887 and 778 swapped
j = 2
arr[2] = 916
pivot = 794
887 and 794 swapped
i + 1 = 1
pi = 1
----------------
----------------
quick_sort(arr,low, pi-1) called-->
----------------
----------------
quick_sort(arr, pi+1,high)called-->
----------------
low  = 2
high = 3
----------------
----------------
high = 3
arr[3] = 887
pivot = 887
i = 1
j = 2
arr[2] = 916
pivot = 887
916 and 887 swapped
i + 1 = 2
pi = 2
----------------
----------------
quick_sort(arr,low, pi-1) called-->
----------------
----------------
quick_sort(arr, pi+1,high)called-->
----------------
----------------
FINAL ANSWER =>
778 794 887 916 
CODE BY ADITI MAHABOLE 20103023
*/
