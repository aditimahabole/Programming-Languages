//https://www.geeksforgeeks.org/change-array-permutation-numbers-1-n/


#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
void make_permutation(int *a,int n)
{
    unordered_map<int,int>count;
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    int k=1;
    for(int i=0;i<n;i++)
    {
        cout<<"-----------"<<endl;
        cout<<"a[i] = "<<a[i]<<endl;
        cout<<"-----------"<<endl;
        if(count[a[i]]!=1|| a[i]>n|| a[i]<1)
        {
            cout<<"-----------"<<endl;
            cout<<" Before count[a[i]]-- = "<<count[a[i]]<<endl;
            count[a[i]]--;
            cout<<" After count[a[i]]-- = "<<count[a[i]]<<endl;
            cout<<"-----------"<<endl;
            while(count.find(k)!=count.end())
            {
                k++;//agar element count map me hai to usko badhate jao jab pehle se hai to koi problem thodi
                
            }
             cout<<"-----------"<<endl;
            cout<<" Before a[i] = "<<a[i]<<endl;
            a[i]=k;
            cout<<" After a[i] = "<<a[i]<<endl;
            cout<<"-----------"<<endl;
            cout<<"k = "<<k<<endl;
            cout<<"Before count[k] = "<<count[k]<<endl;
            count[k]=1;
            cout<<"After  count[k] = "<<count[k]<<endl;
            cout<<"-----------"<<endl;
            
            
        }
    }
}
void print_arr(int a[],int n)
{
    cout<<"--------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
}

int main()
{
// int a[]={2, 2, 3, 3};
int a[]={1, 8, 7, 3};
// int a[]={10, 1, 2};
// int a[]={1, 3, 2};
int n=sizeof(a)/sizeof(a[0]);
make_permutation(a,n);
print_arr(a,n);
return 0;
}
/*-----------
a[i] = 1
-----------
-----------
a[i] = 8
-----------
-----------
 Before count[a[i]]-- = 1
 After count[a[i]]-- = 0
-----------
-----------
 Before a[i] = 8
 After a[i] = 2
-----------
k = 2
Before count[k] = 0
After  count[k] = 1
-----------
-----------
a[i] = 7
-----------
-----------
 Before count[a[i]]-- = 1
 After count[a[i]]-- = 0
-----------
-----------
 Before a[i] = 7
 After a[i] = 4
-----------
k = 4
Before count[k] = 0
After  count[k] = 1
-----------
-----------
a[i] = 3
-----------
--------------------------
1  2  4  3  
--------------------------
*/
