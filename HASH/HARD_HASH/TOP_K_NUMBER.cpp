//PROLEM : 
//https://www.geeksforgeeks.org/find-top-k-or-most-frequent-numbers-in-a-stream/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void top_k_elements(int arr[],int n,int k)
{
    unordered_map<int,int> momo;
    vector<int>top(k+1);
    for(int i=0;i<n;i++)
    {
        momo[arr[i]]++;
        top[k]=arr[i];
        cout<<"------------------------------------"<<endl;
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
        cout<<"top["<<k<<"] = "<<top[k]<<endl;
        cout<<"momo["<<arr[i]<<"] = "<<momo[arr[i]]<<endl;
        cout<<"------------------------------------"<<endl;
        auto it=find(top.begin(),top.end() - 1,arr[i]);
        cout<<"it = "<<*it<<endl;
        //https://www.geeksforgeeks.org/stddistance-in-c/
        //If we have two iterators and we want to find the total no. of elements between the two iterators, then that is facilitated by std::distance(), defined inside the header file .
        for(int i=distance(top.begin(),it)-1;i>=0;i--)
        {   
            cout<<"i = "<<i<<endl;
            if(momo[top[i]]<momo[top[i+1]])
            {
                cout<<"******************************"<<endl;
                cout<<"top["<<i<<"] and "<<"top["<<i+1<<"] swapped"<<endl;
                cout<<top[i]<<" and "<<top[i+1]<<" swapped "<<endl;
                cout<<"******************************"<<endl;
                swap(top[i],top[i+1]);
            }
            else if(momo[top[i]]==momo[top[i+1]] && top[i]>top[i+1])
            {
                cout<<"==============================="<<endl;
                cout<<"top["<<i<<"] and "<<"top["<<i+1<<"] swapped"<<endl;
                cout<<top[i]<<" and "<<top[i+1]<<" swapped "<<endl;
                cout<<"==============================="<<endl;
                swap(top[i],top[i+1]);
            }
            else 
            {
                break;
            }
            
        }
        cout<<"answer : "<<endl;
        
        for(int j=0;j<k && top[j]!=0;j++)
        {
            cout<<top[j]<<" ";
        }
        cout<<endl;
    }
}

int main() 
{
  int n,k;
  int arr[]={5, 2, 1, 3, 2} ;
   n=sizeof(arr)/sizeof(arr[0]);
   cout<<"YOUR ARRAY : "<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<"Enter k = "<<endl;
   cin>>k;
   top_k_elements(arr,n,k);
   return 0;
}
/* OUTPUT :
/tmp/qwY1StILBv.o
YOUR ARRAY : 
5 2 1 3 2 
Enter k = 
4
------------------------------------
arr[0] = 5
top[4] = 5
momo[5] = 1
------------------------------------
it = 5
i = 3
******************************
top[3] and top[4] swapped
0 and 5 swapped 
******************************
i = 2
******************************
top[2] and top[3] swapped
0 and 5 swapped 
******************************
i = 1
******************************
top[1] and top[2] swapped
0 and 5 swapped 
******************************
i = 0
******************************
top[0] and top[1] swapped
0 and 5 swapped 
******************************
answer : 
5 
------------------------------------
arr[1] = 2
top[4] = 2
momo[2] = 1
------------------------------------
it = 2
i = 3
******************************
top[3] and top[4] swapped
0 and 2 swapped 
******************************
i = 2
******************************
top[2] and top[3] swapped
0 and 2 swapped 
******************************
i = 1
******************************
top[1] and top[2] swapped
0 and 2 swapped 
******************************
i = 0
===============================
top[0] and top[1] swapped
5 and 2 swapped 
===============================
answer : 
2 5 
------------------------------------
arr[2] = 1
top[4] = 1
momo[1] = 1
------------------------------------
it = 1
i = 3
******************************
top[3] and top[4] swapped
0 and 1 swapped 
******************************
i = 2
******************************
top[2] and top[3] swapped
0 and 1 swapped 
******************************
i = 1
===============================
top[1] and top[2] swapped
5 and 1 swapped 
===============================
i = 0
===============================
top[0] and top[1] swapped
2 and 1 swapped 
===============================
answer : 
1 2 5 
------------------------------------
arr[3] = 3
top[4] = 3
momo[3] = 1
------------------------------------
it = 3
i = 3
******************************
top[3] and top[4] swapped
0 and 3 swapped 
******************************
i = 2
===============================
top[2] and top[3] swapped
5 and 3 swapped 
===============================
i = 1
answer : 
1 2 3 5 
------------------------------------
arr[4] = 2
top[4] = 2
momo[2] = 2
------------------------------------
it = 2
i = 0
******************************
top[0] and top[1] swapped
1 and 2 swapped 
******************************
answer : 
2 1 3 5 
FINALLY : 
5  2 5  1 2 5  1 2 3 5  2 1 3 5
*/
