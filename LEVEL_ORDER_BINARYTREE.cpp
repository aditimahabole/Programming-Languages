#include <iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
class node
{

public:
    int data;
    node* left;
    node*right;
};
///////////MAKING NEW NODE/////////
node* make_node(int value)
{
    node*new_node=new node;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
////////////LEVELORDER NON-RECURSSIVE/////
void levelorder_nonrecurrsive(node* root)
{

   if(root==NULL)
   {
       return;
   }
    queue<node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
       node*temp=q.front();
       q.pop();
       if(temp!=NULL)
       {
           cout<<temp->data<<"   ";

           if(temp->left)
           {
               q.push(temp->left);
           }
           if(temp->right)
           {
               q.push(temp->right);
           }
       }
       else if(!q.empty())
       {
           q.push(NULL);
       }
   }


}
///////////////////INT MAIN/////////////////
int main()
{
    node* root=NULL;
    /*         1
             /    \
          2           3
        /  \        /   \
    4        5     6     7
   / \      /
8     9   10
*/
    root=make_node(1);
    root->left=make_node(2);
    root->right=make_node(3);
    root->left->left=make_node(4);
    root->left->right=make_node(5);
    root->right->left=make_node(6);
    root->right->right=make_node(7);
    root->left->left->left=make_node(8);
    root->left->left->right=make_node(9);
    root->left->right->left=make_node(10);
    cout<<"LEVEL ORDER NON-RECURRSIVE BINARY TREE:"<<endl;
    levelorder_nonrecurrsive(root);
    cout<<endl;
    return 0;
}
