// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int median(int arr[],int l,int r,int k)
{
    int num=r-l+1;
    cout<<"____________________________"<<endl;
    cout<<"num = "<<num<<endl;
    int index=rand()%num;
    cout<<"index = "<<index<<endl;
    cout<<"____________________________"<<endl;
    
    int i,i1=0,i2=0,i3=0;
    int s1[10],s2[1],s3[10];
    for(i=0;i<=r;i++)
    {
        if(arr[i]<arr[index])
        {
            s1[i1]=arr[i];
            i1++;
        }
        else if(arr[i]==arr[index])
        {
            s2[i2]=arr[i];
            i2++;
        }
        else 
        {
            s3[i3]=arr[i];
            i3++;
        }
    }
    cout<<"____________________________"<<endl;
    cout<<"k  = "<<k<<endl;
    cout<<"i1 = "<<i1<<endl;
    cout<<"i2 = "<<i2<<endl;
    cout<<"i3 = "<<i3<<endl;
    cout<<"____________________________"<<endl;
    if(i1>=k)
    {
        median(s1,0,i1 - 1,k);
    }
    else if(i1+i2>=k)
    {
        cout<<"i1+i2>=k"<<endl;
        return arr[index];
    }
    else 
    {
        cout<<"k-(i1+i2) = "<<k - (i1+i2)<<endl;
        median(s3,0,i3 - 1,k-(i1+i2));
    }
}


int main() 
{
    int arr[]={7,10,4,3,20,15,8,12,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=6;
    int ele=median(arr,0,n-1,k);
    cout<<"ele = "<<ele;
    

    return 0;
}
/*
____________________________
num = 9
index = 1
____________________________
____________________________
k  = 6
i1 = 5
i2 = 1
i3 = 3
____________________________
i1+i2>=k
ele = 10
*/
