#include<bits/stdc++.h>
using namespace std;

int CalcMedian(int Arr[],int left,int right,int k)
{
    int val=right-left+1;
    int index=rand()%val;

    int small[10], num[1], big[10],l=0,v=0,b=0,i;

    for(i=0;i<=right;i++)
    {
        if(Arr[i]<Arr[index])
        {
            small[l]=Arr[i];
            l++;
        }
        else if(Arr[i]==Arr[index])
        {
            num[v]=Arr[i];
            v++;
        }
        else
        {
            big[b]=Arr[i];
            b++;
        }

    }
    cout<<"\nSplit Array Elements are:\nSmall: ";
    for(int j=0;j<l;j++)
    {
        cout<<small[j]<<" ";
    }
    cout<<"\n Equal: "<<num[0]<<" ";
    cout<<"\nBig: ";
    for(int j=0;j<b;j++)
    {
        cout<<big[j]<<" ";
    }
    cout<<endl;

    if(l>=k)
    {
        CalcMedian(small,0,l-1,k);
    }
    else if((l+v)>=k)
    {
        return Arr[index];
    }
    else
    {
        CalcMedian(big,0,b-1,k-(l+v));
    }

}
int main()
{
    int n,k;

    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];

    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter value of k for kth median: ";
    cin>>k;
    cout<<"\n K th median and kth smallest element is: "<<CalcMedian(arr,0,n,k);

}
