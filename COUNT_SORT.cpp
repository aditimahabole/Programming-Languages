#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void count_sort(int arr[],int n)
{
    int k=arr[0];
    for(int i=0;i<n;i++)
    {
        k=max(k,arr[i]);
    }
    int count[10]={0};
    cout<<"COUNTING THE ELEMENTS:"<<endl;
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
        cout<<"count[arr[i]] =  "<<count[arr[i]]<<"  arr[i]=  "<<arr[i]<<endl;
    }
    cout<<endl;
    cout<<"DISPLAYING COUNT ARRAY:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<count[i]<<"  ";
    }
    cout<<endl;
    cout<<"ADDING ELEMENTS OF PREVIOUS TO THE ELEMET:"<<endl;
    for (int i=1;i<=k;i++)
    {
           cout<<"count[i]=count[i]+count[i-1] =  "<<count[i]<<" + "<<count[i-1];
           count[i]=count[i]+count[i-1];
           cout<<"  "<<count[i]<<endl;

    }
    int output[n];

    cout<<"STORING ELEMENST IN OUTPUT ARRAY:"<<endl;
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i];
        cout<<"output[--count[arr[i]]]=  "<<output[count[arr[i]]]<<"  count[arr[i]]=  "<<count[arr[i]]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
    cout<<"AFTER COUNT SORT:"<<endl;
    cout<<"[";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<"]"<<endl;
}

int main()
{
    int n;
   cout<<"ENTER NUMBER OF ELEMENTS:"<<endl;
   cin>>n;
   int arr[n];
   cout<<"ENTER EMENETS:"<<endl;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   cout<<"[";
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<",";
   }
     cout<<"]";
   cout<<endl;
   count_sort(arr,n);
    return 0;
}


