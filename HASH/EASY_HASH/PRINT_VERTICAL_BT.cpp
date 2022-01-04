#include <iostream>
#include <vector>
#include <map>
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
void get_vertical_order(node* root,int hd ,map<int,vector<int>> &m)
{
    if(root==NULL)
    {
        return;
    }
    m[hd].push_back(root->data);
    cout<<"node->left->data : "<<root->data<<" having horizontal distance : "<<hd<<endl;
    
    get_vertical_order(root->left,hd-1,m);
    cout<<"left part done"<<endl;
    cout<<"node->right->data : "<<root->data<<" having horizontal distance : "<<hd<<endl;
    get_vertical_order(root->right,hd+1,m);
    cout<<"right part done"<<endl;
}

void print_vertical_order(node* root)
{
    map<int,vector<int>> m;//map in which index is int and values are sotred in form of vector
    int hd=0;//horizontal distance
    
    get_vertical_order(root,hd,m);
    
    map<int,vector<int>> ::iterator i;
    for(i=m.begin();i!=m.end();i++)
    {
        cout<<"horzontal distance : "<<i->first<<"--->  ";
        for(int j=0;j<i->second.size();j++)
        {
            cout<<i->second[j]<<"  ";
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
   cout<<"VERTICAL ORDER TRAVERSAL : "<<endl;
   print_vertical_order(root);
    return 0;
}
