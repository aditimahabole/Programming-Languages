// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool fun(int *arr,int sum,int n)
{
    if(n==0 && sum==0)
    {
        return true;
    }
    else if(n>0 && sum==0)
    {
        return true;
    }
    else if(n==0 && sum>0)
    {
        return false;
    }
    if(arr[n]<=sum)
    {
        return (fun(arr,sum-arr[n], n-1) || fun(arr,sum,n-1));
      // INSEAD OF MAX WE USE OR || TO GET CORRECT VALUE 
      //(jab humne vo element include kiya, include nhi kiya) to kya ye value true degi ya false vo humne || operation ka use karke nikala
    }
    else if(arr[n]>sum)
    {
        return fun(arr,sum,n-1);
    }

}

int main() {
 int n = 6;
int arr[] = {3, 34, 4, 12, 5, 2};
int sum = 30;
cout<<fun(arr,sum,n-1);

    return 0;
}
