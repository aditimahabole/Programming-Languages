//LEVEL ORDER CONCEPT  USED
//UNORDERED MAP USED 
//QUEUE USED
//VECTOR USED
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
/////////MAKING OF NEW NODE/////////
node* new_node(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void print_vertical_order(node* root)
{
    if(root==NULL)
    {
        return;
    }
    unordered_map<int,vector<int>> m;
    int hd=0;
    queue<pair<node*,int>> q;//queue is used for level order traversal
    q.push({root,hd});
    cout<<"root : "<<root->data<<" hd : "<<hd<<endl;
    
    int min=0 ,max=0;//min max are distance from root
    while(q.size()>0)
    {
        pair<node*,int> temp=q.front();
        q.pop();
        hd=temp.second;
        cout<<"value of hd : "<<hd<<endl;
        node* n=temp.first;
        cout<<"value of node* n : "<<n->data<<endl;
        m[hd].push_back(n->data);
        if(n->left)
        {
            q.push({n->left,hd-1});
            cout<<"q.push({n->left,hd-1}); "<<n->left->data<<" , "<<hd-1<<endl;
        }
        if(n->right)
        {
            q.push({n->right,hd+1});
            cout<<"q.push({n->right,hd+1}); "<<n->right->data<<" , "<<hd+1<<endl;
        }
        if(min>hd)
        {
            min=hd;
            cout<<"min = "<<min<<endl;
        }
        else if(max<hd)
        {
            max=hd;
            cout<<"max = "<<max<<endl;
            
        }
        
    }
    
    for(int i= min;i<=max;i++)
    {
        vector<int>temp=m[i];
        // cout<<m[i]<<"--->  ";
        for(int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<"  ";
        }
        cout<<endl;
    }
}

int main() 
{
    node* root=new_node(1);
    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->left->right=new_node(5);
    root->right->left=new_node(6);
    root->right->right=new_node(7);
    root->right->left->right=new_node(8);
    root->right->right->right=new_node(9);
    root->right->right->left = new_node(10);
    root->right->right->left->right = new_node(11);
    root->right->right->left->right->right = new_node(12);
   cout<<"VERTICAL ORDER TRAVERSAL : "<<endl;
   print_vertical_order(root);
    return 0;
}
/*OUTPUT :
VERTICAL ORDER TRAVERSAL : 
root : 1 hd : 0
value of hd : 0
value of node* n : 1
q.push({n->left,hd-1}); 2 , -1
q.push({n->right,hd+1}); 3 , 1
value of hd : -1
value of node* n : 2
q.push({n->left,hd-1}); 4 , -2
q.push({n->right,hd+1}); 5 , 0
min = -1
value of hd : 1
value of node* n : 3
q.push({n->left,hd-1}); 6 , 0
q.push({n->right,hd+1}); 7 , 2
max = 1
value of hd : -2
value of node* n : 4
min = -2
value of hd : 0
value of node* n : 5
value of hd : 0
value of node* n : 6
q.push({n->right,hd+1}); 8 , 1
value of hd : 2
value of node* n : 7
q.push({n->left,hd-1}); 10 , 1
q.push({n->right,hd+1}); 9 , 3
max = 2
value of hd : 1
value of node* n : 8
value of hd : 1
value of node* n : 10
q.push({n->right,hd+1}); 11 , 2
value of hd : 3
value of node* n : 9
max = 3
value of hd : 2
value of node* n : 11
q.push({n->right,hd+1}); 12 , 3
value of hd : 3
value of node* n : 12
4  
2  
1  5  6  
3  8  10  
7  11  
9  12
*/
