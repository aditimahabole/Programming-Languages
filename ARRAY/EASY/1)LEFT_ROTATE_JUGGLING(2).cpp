//https://www.geeksforgeeks.org/array-rotation/
//JUGGLING ALORITHM
// This is an extension of method 2. Instead of moving one by one, divide the array in different sets 
// where number of sets is equal to GCD of n and d and move the elements within sets. 
// If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int k,int n)
{
    cout<<"-------INSIDE GCD---------"<<endl;
    if(n==0)
    {
        cout<<"_________"<<endl;
        cout<<"k returned = "<<k<<endl;
        cout<<"_________"<<endl;
        return k;
    }
    else 
    {
        cout<<"n = "<<n<<" k = "<<k<<" k (%) n = "<<k%n<<endl;
        return gcd(n,k%n);
    }
    
}
void left_rotate(int arr[],int n,int k )
{
    k=k % n;
    int g_c_d=gcd(k,n);
    for(int i=0;i<g_c_d;i++)
    {
        cout<<"____________________________"<<endl;
        int temp=arr[i];
        cout<<"temp = "<<temp<<endl;
        int j=i;
        cout<<"j = "<<j<<endl;
        cout<<"____________________________"<<endl;
        while(1)
        {
            int m=j+k;
            cout<<"____________________________"<<endl;
            cout<<"j = "<<j<<endl;
            cout<<"k = "<<k<<endl;
            cout<<"m = "<<m<<endl;
            cout<<"n = "<<n<<endl;
            cout<<"____________________________"<<endl;
            if(m>=n)
            {
                m=m - n;
                cout<<"____________________________"<<endl;
                cout<<"m = m-n => "<<m<<endl;
                cout<<"____________________________"<<endl;
            }
            if(m == i)
            {
                cout<<"____________________________"<<endl;
                cout<<"break"<<endl;
                cout<<"____________________________"<<endl;
                break;
            }
            arr[j]=arr[m];
            cout<<"---------------------------"<<endl;
            cout<<"j = "<<j<<endl;
            cout<<"arr[j] = "<<arr[j]<<endl;
            cout<<"m = "<<m<<endl;
            cout<<"arr[m] = "<<arr[m]<<endl;
            cout<<"---------------------------"<<endl;
            j=m;
            cout<<"j = m : "<<j<<endl;
            
        }
        arr[j] = temp;
        cout<<"---------------------------"<<endl;
            cout<<"j = "<<j<<endl;
            cout<<"arr[j] = temp =>  "<<arr[j]<<endl;
        cout<<"---------------------------"<<endl;
    }
}
void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main() {
  
  int arr[]={1,2,3,4,5,6,7,8};
  int n=sizeof(arr)/sizeof(arr[0]);
  left_rotate(arr,n,2);
  display(arr,n);

    return 0;
}
/*
/tmp/Kq9JWNiFCT.o
-------INSIDE GCD---------
n = 8 k = 2 k (%) n = 2
-------INSIDE GCD---------
n = 2 k = 8 k (%) n = 0
-------INSIDE GCD---------
_________
k returned = 2
_________
____________________________
temp = 1
j = 0
____________________________
____________________________
j = 0
k = 2
m = 2
n = 8
____________________________
---------------------------
j = 0
arr[j] = 3
m = 2
arr[m] = 3
---------------------------
j = m : 2
____________________________
j = 2
k = 2
m = 4
n = 8
____________________________
---------------------------
j = 2
arr[j] = 5
m = 4
arr[m] = 5
---------------------------
j = m : 4
____________________________
j = 4
k = 2
m = 6
n = 8
____________________________
---------------------------
j = 4
arr[j] = 7
m = 6
arr[m] = 7
---------------------------
j = m : 6
____________________________
j = 6
k = 2
m = 8
n = 8
____________________________
____________________________
m = m-n => 0
____________________________
____________________________
break
____________________________
---------------------------
j = 6
arr[j] = temp =>  1
---------------------------
____________________________
temp = 2
j = 1
____________________________
____________________________
j = 1
k = 2
m = 3
n = 8
____________________________
---------------------------
j = 1
arr[j] = 4
m = 3
arr[m] = 4
---------------------------
j = m : 3
____________________________
j = 3
k = 2
m = 5
n = 8
____________________________
---------------------------
j = 3
arr[j] = 6
m = 5
arr[m] = 6
---------------------------
j = m : 5
____________________________
j = 5
k = 2
m = 7
n = 8
____________________________
---------------------------
j = 5
arr[j] = 8
m = 7
arr[m] = 8
---------------------------
j = m : 7
____________________________
j = 7
k = 2
m = 9
n = 8
____________________________
____________________________
m = m-n => 1
____________________________
____________________________
break
____________________________
---------------------------
j = 7
arr[j] = temp =>  2
---------------------------
3 4 5 6 7 8 1 2 
*/
