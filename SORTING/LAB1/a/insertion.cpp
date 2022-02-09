
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
 void insertion_sort(int *arr,int n)
 {
     int i,j,key;
     for(int i=1;i<n;i++)
     {
         key=arr[i];
         cout<<"key = "<<key<<endl;
         j=i-1;
         cout<<"i = "<<i<<endl;
         cout<<"j = "<<j<<endl;
         
         
         while(j>=0 && arr[j]>key)
         {
             cout<<"____________________________"<<endl;
             cout<<"--BEFORE--"<<endl;
             cout<<"j = "<<j<<endl;
             cout<<"arr["<<j<<"] = "<<arr[j]<<endl;
             cout<<"j+1 = "<<j+1<<endl;
             cout<<"arr["<<j+1<<"] = "<<arr[j+1]<<endl;
             cout<<"____________________________"<<endl;
             arr[j+1]=arr[j];
             cout<<"____________________________"<<endl;
             cout<<"--AFTER--"<<endl;
             cout<<"j = "<<j<<endl;
             cout<<"arr["<<j<<"] = "<<arr[j]<<endl;
             cout<<"j+1 = "<<j+1<<endl;
             cout<<"arr["<<j+1<<"] = "<<arr[j+1]<<endl;
             cout<<"____________________________"<<endl;
             
             j--;
         }
         arr[j+1]=key;
         cout<<"------------------------"<<endl;
         cout<<"j+1 = "<<j+1<<endl;
         cout<<"arr["<<j+1<<"] = "<<arr[j+1]<<endl;
         cout<<"------------------------"<<endl;
         
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
   insertion_sort(arr,n);
    cout<<"FINAL ANSWER =>"<<endl;
    display(arr,n);
    
    return 0;
}
/* OUTPUT
CODE BY ADITI MAHABOLE 20103023
887 778 916 794 
key = 778
i = 1
j = 0
____________________________
--BEFORE--
j = 0
arr[0] = 887
j+1 = 1
arr[1] = 778
____________________________
____________________________
--AFTER--
j = 0
arr[0] = 887
j+1 = 1
arr[1] = 887
____________________________
------------------------
j+1 = 0
arr[0] = 778
------------------------
key = 916
i = 2
j = 1
------------------------
j+1 = 2
arr[2] = 916
------------------------
key = 794
i = 3
j = 2
____________________________
--BEFORE--
j = 2
arr[2] = 916
j+1 = 3
arr[3] = 794
____________________________
____________________________
--AFTER--
j = 2
arr[2] = 916
j+1 = 3
arr[3] = 916
____________________________
____________________________
--BEFORE--
j = 1
arr[1] = 887
j+1 = 2
arr[2] = 916
____________________________
____________________________
--AFTER--
j = 1
arr[1] = 887
j+1 = 2
arr[2] = 887
____________________________
------------------------
j+1 = 1
arr[1] = 794
------------------------
FINAL ANSWER =>
778 794 887 916 
*/
