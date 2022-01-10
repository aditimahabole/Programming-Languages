
//https://www.geeksforgeeks.org/find-pairs-b-array-b-k/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> find_div(int n)
{
   vector<int>v;
   cout<<"===================="<<endl;
   cout<<"value of n = "<<n<<endl;
   cout<<"===================="<<endl;
   for(int i=1;i<=sqrt(n);i++)
   {
       if(n% i==0)
       {
           if(n/i==i)
           {
               cout<<"-----in if(n/i==i) condition----- "<<endl;
               cout<<" i = "<<i<<endl;
               v.push_back(i);
           }
           else
           {
               v.push_back(i);
               v.push_back(n/i);
               cout<<"---------in else condition--------"<<endl;
               cout<<"v.push_back(i); = "<<i<<endl;
               cout<<"v.push_back(n/i); = "<<n/i<<endl;
           }
       }
   }
   cout<<endl;
   cout<<"_________________________"<<endl;
   for(int i=0;i<v.size();i++)
   {
       cout<<v[i]<<" , ";
   }
   cout<<endl;
   cout<<"_________________________"<<endl;
   return v;
}
bool print_pair(int arr[],int n,int k )
{
    unordered_map<int,bool>occ;
    cout<<"----------------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        occ[arr[i]]=true;
        cout<<"arr["<<i<<"] = "<<arr[i]<<" -> "<<"occ[arr[i]] = "<< occ[arr[i]]<<endl;
    }
    cout<<"----------------------------------"<<endl;
    bool find_pair=false;
    for(int i=0;i<n;i++)
    {
        cout<<"________________________________"<<endl;
        cout<<"value of arr[i] = "<<arr[i]<<endl;
        cout<<"________________________________"<<endl;
        if(occ[k]&& k<arr[i])
        {
            cout<<"-------ans1--------"<<endl;
            cout<<"occ[k] = "<<occ[k]<<endl;
            cout<<"k = "<<k<<endl;
            cout<<"("<<k<<" , "<<arr[i]<<") ";
            cout<<endl;
            cout<<"------------------"<<endl;
            find_pair=true;
        }
        if(arr[i]>=k)
        {
            cout<<"________________________________"<<endl;
            cout<<"value of k      = "<<k<<endl;
            cout<<"value of arr[i] = "<<arr[i]<<endl;
            cout<<"________________________________"<<endl;
            vector<int>v=find_div(arr[i]- k);
            for(int j=0;j<v.size();j++)
            {
                if(arr[i]%v[j]==k && arr[i]!=v[j]&&occ[v[j]])
                {
                    cout<<"-------ans2--------"<<endl;
                    cout <<"("<<arr[i]<<" , "<<v[j]<<") ";
                    cout<<endl;
                    cout<<"------------------"<<endl;
                    find_pair=true;
                }
            }
            v.clear();
        }
    }
    return find_pair;
}
int main()
{
   int arr[] = { 3, 1, 2, 5, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    if(print_pair(arr,n,k)==false)
    {
        cout<<"no pair exist"<<endl;
        
    }

    return 0;
}
/* OUTPUT :
----------------------------------
arr[0] = 3 -> occ[arr[i]] = 1
arr[1] = 1 -> occ[arr[i]] = 1
arr[2] = 2 -> occ[arr[i]] = 1
arr[3] = 5 -> occ[arr[i]] = 1
arr[4] = 4 -> occ[arr[i]] = 1
----------------------------------
________________________________
value of arr[i] = 3
________________________________
-------ans1--------
occ[k] = 1
k = 2
(2 , 3) 
------------------
________________________________
value of k      = 2
value of arr[i] = 3
________________________________
====================
value of n = 1
====================
-----in if(n/i==i) condition----- 
 i = 1

_________________________
1 , 
_________________________
________________________________
value of arr[i] = 1
________________________________
________________________________
value of arr[i] = 2
________________________________
________________________________
value of k      = 2
value of arr[i] = 2
________________________________
====================
value of n = 0
====================

_________________________

_________________________
________________________________
value of arr[i] = 5
________________________________
-------ans1--------
occ[k] = 1
k = 2
(2 , 5) 
------------------
________________________________
value of k      = 2
value of arr[i] = 5
________________________________
====================
value of n = 3
====================
---------in else condition--------
v.push_back(i); = 1
v.push_back(n/i); = 3

_________________________
1 , 3 , 
_________________________
-------ans2--------
(5 , 3) 
------------------
________________________________
value of arr[i] = 4
________________________________
-------ans1--------
occ[k] = 1
k = 2
(2 , 4) 
------------------
________________________________
value of k      = 2
value of arr[i] = 4
________________________________
====================
value of n = 2
====================
---------in else condition--------
v.push_back(i); = 1
v.push_back(n/i); = 2

_________________________
1 , 2 , 
_________________________
*/
