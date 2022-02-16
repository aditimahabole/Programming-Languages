
///////////////////////IMPLEMENTATION OF MY LOGIC///////////////////////////////////
#include <bits/stdc++.h>

using namespace std;

int binary_search(int arr[],int s,int e,int x)

{

    int mid=(e+s)/2;

    cout<<"+++++++++++++++++"<<endl;

    cout<<"mid = "<<mid<<endl;

    cout<<"arr[mid] = "<<arr[mid]<<endl;

    cout<<"s = "<<s<<endl;

    cout<<"e = "<<e<<endl;

    cout<<"+++++++++++++++++"<<endl;

    

    if(arr[mid]==x)

    {

        return mid;

    }

    else if(arr[mid]>x)

    {

      return  binary_search(arr,s,mid - 1,x);

    }

    else if(arr[mid]==0)

    {

return        binary_search(arr,s,mid-1,x);

    }

    else if(arr[mid]<x)

    {
return
        binary_search(arr,mid +1,e,x);

    }

 

        return -1;

    

  

}


int main() {

 

 

 int n =10;

 int arr[n]={1,2,3,4,5,6,7,0,0,0};

 int x;

 cin>>x;

 int flag =binary_search(arr,0,n - 1,x);

 if(flag == -1)

 {

     cout<<"element not found"<<endl;

 }

 else 

 {

     cout<<flag;

 }


    return 0;

}
//////////////////////IMPLEMENTATION OF SHERRY MAM'S LOGIC ///////////////////////////

#include <iostream>
using namespace std;
int binary_search(int arr[],int s,int e,int x)
{
int mid=(e+s)/2;

cout<<"+++++++++++++++++"<<endl;

cout<<"mid = "<<mid<<endl;

cout<<"arr[mid] = "<<arr[mid]<<endl;

cout<<"s = "<<s<<endl;

cout<<"e = "<<e<<endl;

cout<<"+++++++++++++++++"<<endl;



if(arr[mid]==x)

{return mid;}

 else if(arr[mid]>x)
{return binary_search(arr,s,mid - 1,x);}

 else if(arr[mid]==0)
{return binary_search(arr,s,mid-1,x);}

else if(arr[mid]<x)
{return binary_search(arr,mid +1,e,x);}

return -1;
}


int main()
{
    int n=13;
    int arr[n]={1,2,3,4,5,6,7,8,9,0,0,0,0};
    int x;
    cout<<"enter x : "<<endl;
    cin>>x;
    for(int i=1;i<n;i*=2)
    {

        if(arr[i]==x)
        {
            cout<<i<<endl;
            break;
        }
        else if(arr[i]>x || arr[i]==0)
        {
            cout<<binary_search(arr,i/2,i,x);
            break;
        }

    }

    return 0;
}
