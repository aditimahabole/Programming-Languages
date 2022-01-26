
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
int main()
{
    int k;
    cout<<"Enter k : "<<endl;
    cin>>k;
    // eg we have k arrays and we wanna merge them. A={1,3,5}, B={4,6,7},C={2,7} ans={1,2,3,4,5,6,7,7}

    vector<vector<int> >a(k);
    cout<<"Enter Elements : "<<endl;

    for(int i=0;i<k;i++)
    {
        cout<<"Enter inner vector size : "<<endl;
        int size;
        cin>>size;

        a[i]=vector<int>(size);
        cout<<" start entering elements : "<<endl;
        for(int j=0;j<size;j++)
        {
            cin>>a[i][j];
        }
    }

    vector<int>index(k,0);

    priority_queue<pp,vector<pp>,greater<pp> >MinHeap;

    for(int i=0;i<k;i++)
    {
        MinHeap.push({a[i][0],i});
        cout<<"______________________________"<<endl;
        cout<<"i : "<<i<<endl;
        cout<<"a["<<i<<"] : "<<endl;
        cout<<"Push In MinHeap: "<<a[i][0]<<endl;
        cout<<"______________________________"<<endl;
    }

    vector<int>ans;

    cout<<"\n\nNow pop: \n\n";

    while(!MinHeap.empty())
    {

        pair<int,int> x=MinHeap.top();
        MinHeap.pop();
        ans.push_back(x.first);
        cout<<"______________________________"<<endl;
        cout<<"x.first is pushed in ans : "<<x.first<<endl;
        cout<<"x.second  :   "<<x.second<<endl;
        cout<<"index[x.second] : "<<index[x.second]<<endl;
        cout<<"index[x.second]  + 1 : "<<index[x.second]+1<<endl;
        cout<<"a[x.second].size() : "<<a[x.second].size()<<endl;
       cout<<"______________________________"<<endl;

        if(index[x.second] +1  < a[x.second].size())
        {
            cout<<"----------------INSIDE IF--------------------"<<endl;
            cout<<"x.second  :   "<<x.second<<endl;
            cout<<"index[x.second]  :   "<<index[x.second]<<endl;
            cout<<"index[x.second] + 1  :   "<<index[x.second] + 1<<endl;
            cout<<"a [x.second] [index[x.second]+1]  :   "<<a[x.second][index[x.second]+1]<<endl;
            cout<<"MinHeap.push({a[x.second][index[x.second]+1],x.second}) : "<<a[x.second][index[x.second]+1]<<" and "<<x.second<<endl;
           MinHeap.push({a[x.second][index[x.second]+1],x.second});
           cout<<"---------------IF ENDS--------------------"<<endl;
        }
        cout<<"----------------AFTER IF--------------------"<<endl;
        cout<<"Before  index[x.second]=+1 : "<<index[x.second]<<endl;
        index[x.second]+=1;
        cout<<"After  index[x.second]+=1 : "<<index[x.second]<<endl;
        cout<<"------------------------------------------------"<<endl;

    }

    cout<<"\n\nans:";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
/*
Enter k :
2
Enter Elements :
Enter inner vector size :
3
 start entering elements :
1
2
3
Enter inner vector size :
3
 start entering elements :
4
5
6
______________________________
i : 0
a[0] :
Push In MinHeap: 1
______________________________
______________________________
i : 1
a[1] :
Push In MinHeap: 4
______________________________


Now pop:

______________________________
x.first is pushed in ans : 1
x.second  :   0
index[x.second] : 0
index[x.second]  + 1 : 1
a[x.second].size() : 3
______________________________
----------------INSIDE IF--------------------
x.second  :   0
index[x.second]  :   0
index[x.second] + 1  :   1
a [x.second] [index[x.second]+1]  :   2
MinHeap.push({a[x.second][index[x.second]+1],x.second}) : 2 and 0
---------------IF ENDS--------------------
----------------AFTER IF--------------------
Before  index[x.second]=+1 : 0
After  index[x.second]+=1 : 1
------------------------------------------------
______________________________
x.first is pushed in ans : 2
x.second  :   0
index[x.second] : 1
index[x.second]  + 1 : 2
a[x.second].size() : 3
______________________________
----------------INSIDE IF--------------------
x.second  :   0
index[x.second]  :   1
index[x.second] + 1  :   2
a [x.second] [index[x.second]+1]  :   3
MinHeap.push({a[x.second][index[x.second]+1],x.second}) : 3 and 0
---------------IF ENDS--------------------
----------------AFTER IF--------------------
Before  index[x.second]=+1 : 1
After  index[x.second]+=1 : 2
------------------------------------------------
______________________________
x.first is pushed in ans : 3
x.second  :   0
index[x.second] : 2
index[x.second]  + 1 : 3
a[x.second].size() : 3
______________________________
----------------AFTER IF--------------------
Before  index[x.second]=+1 : 2
After  index[x.second]+=1 : 3
------------------------------------------------
______________________________
x.first is pushed in ans : 4
x.second  :   1
index[x.second] : 0
index[x.second]  + 1 : 1
a[x.second].size() : 3
______________________________
----------------INSIDE IF--------------------
x.second  :   1
index[x.second]  :   0
index[x.second] + 1  :   1
a [x.second] [index[x.second]+1]  :   5
MinHeap.push({a[x.second][index[x.second]+1],x.second}) : 5 and 1
---------------IF ENDS--------------------
----------------AFTER IF--------------------
Before  index[x.second]=+1 : 0
After  index[x.second]+=1 : 1
------------------------------------------------
______________________________
x.first is pushed in ans : 5
x.second  :   1
index[x.second] : 1
index[x.second]  + 1 : 2
a[x.second].size() : 3
______________________________
----------------INSIDE IF--------------------
x.second  :   1
index[x.second]  :   1
index[x.second] + 1  :   2
a [x.second] [index[x.second]+1]  :   6
MinHeap.push({a[x.second][index[x.second]+1],x.second}) : 6 and 1
---------------IF ENDS--------------------
----------------AFTER IF--------------------
Before  index[x.second]=+1 : 1
After  index[x.second]+=1 : 2
------------------------------------------------
______________________________
x.first is pushed in ans : 6
x.second  :   1
index[x.second] : 2
index[x.second]  + 1 : 3
a[x.second].size() : 3
______________________________
----------------AFTER IF--------------------
Before  index[x.second]=+1 : 2
After  index[x.second]+=1 : 3
------------------------------------------------


ans:1 2 3 4 5 6
*/
