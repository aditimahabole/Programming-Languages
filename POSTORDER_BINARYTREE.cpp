#include <iostream>
#include<stack>

using namespace std;
class node
{
public:
    int data;
    node*left;
    node* right;
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
////////////////POSTORDER NON RECURRSIVE//////
void nonrecurssive_postorder(node* &root)
{

    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        node*temp=s1.top();
        node*temp1;
        cout<<"top value and value that is pushed into s2    :    "<<temp->data<<endl;
        s1.pop();
        s2.push(temp);
        if(temp->left)
        {
            s1.push(temp->left);
            cout<<"left node    :   "<<temp->left->data<<endl;
        }
        if(temp->right)
        {
            s1.push(temp->right);
            cout<<"right node   :   "<<temp->right->data<<endl;
        }
    }
    while(!s2.empty())
    {
        node* temp=s2.top();
        s2.pop();
        cout<<temp->data<<"    ";
    }

}
////////////POSTORDER RECURRSIVE//////////////
void postorder_recurrsive(node* & root)
{

    node*temp=root;
    if(temp==NULL)
    {
        return;
    }
     postorder_recurrsive(temp->left);
      postorder_recurrsive(temp->right);
      cout<<temp->data<<"    ";
}
///////INT MAIN/////////////
int main()
{
     node* root=NULL;
    /*           1
             /        \
          2             3
        /  \            / \
       4    5          6    7
      / \   / \       /\     /\
     8   9 10  11    12 13  14 15
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
    root->left->right->right=make_node(11);
    root->right->left->left=make_node(12);
    root->right->left->right=make_node(13);
    root->right->right->left=make_node(14);
    root->right->right->right=make_node(15);
    cout<<endl;
    cout<<"POST ORDER WITHOUT RECURSSION"<<endl;
    nonrecurssive_postorder(root);
    cout<<endl;
    cout<<"POST ORDER WITH RECURSSION"<<endl;
    postorder_recurrsive(root);
    cout<<endl;
    return 0;
}
