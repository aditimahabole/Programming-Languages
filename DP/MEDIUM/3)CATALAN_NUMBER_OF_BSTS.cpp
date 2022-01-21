// NUMBER OF BSTS USING CATALAN NUMBER
//https://youtu.be/1ZAotQGnbi4
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* l;
    node* r;
    node(int val)
    {
        data=val;
        l=NULL;
        r=NULL;
    }
    
};

vector<node*>construct_tree(int start,int end)
{
    vector<node*>trees;
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++)
    {
        vector<node*>left_subtree=construct_tree(start,i - 1);
        vector<node*>right_subtree=construct_tree(i + 1,end);
        
        for(int j=0;j<left_subtree.size();j++)
        {
            node* left=left_subtree[j];
            for(int k=0;k<right_subtree.size();k++)
            {
                node* right=right_subtree[k];
                node* new_node=new node(i);
                new_node->l=left;
                new_node->r=right;
                trees.push_back(new_node);
            }
        }
    }
    return trees;
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->l);
    preorder(root->r);
}
int main() 
{
    vector<node*>total_trees=construct_tree(1,3);
    for(int i=0;i<total_trees.size();i++)
    {
        cout<<i+1<<" : ";
        preorder(total_trees[i]);
        cout<<endl;
    }
    return 0;
}
/*
OUTPUT : 
1 : 1 2 3 LEAF
2 : 1 3 2 LEAF
3 : 2 1 3 MIDDLE
4 : 3 1 2 ROOT
5 : 3 2 1 ROOT
*/
