
#include <iostream>
using namespace std;
int binary_search(int arr[],int s,int n,int k)
{
   
    int mid = s+(n-s)/2;
    if(arr[mid]==k)
    {
        int i=mid;
        int j=mid;
        while(arr[i]==k )
        {
            i--;
        }
        while(arr[j]==k )
        {
            j++;
        }i++;j--;
       
       
        cout<<"First occurrence = "<<i<<endl;
        cout<<"Last occurrence = "<<j<<endl;
        return 0;
        
       
        
    }
    else if(arr[mid]>k)
    {
         return binary_search(arr,0,mid - 1,k);
    }
    else if(arr[mid]<k)
    {
        return binary_search(arr,mid + 1,n,k);
    }
    
}


int main() {
    int arr[]={2,5,5,5,6,6,8,9,9,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target =5;
    binary_search(arr,0,n - 1,target);

    return 0;
}
//CODE BYE ADITI MAHABOLE
