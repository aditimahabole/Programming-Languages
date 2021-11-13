#include <iostream>
#include<stack>
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
////////////PREORDER NON RECURSSIVE USING STACK/////
void preorder_BTusing_stack(node* &root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        stack<node*>s;//created  stack in which we will store elements of binary tree
        s.push(root);//pusing root node here as it will be the first to enter and last to exist

        while(!s.empty())
        {

            node* temp_node=s.top() ;// making a pointer temp_node which will point to the top value at first it will be root then it will change according to left right
            cout<<temp_node->data<<"  "; // printing the node value
            s.pop();
            // Push right and left children of the popped node to stack

            if(temp_node->right)// here we are checking if right node exist or not .....in case it does not then value is NULL so if(NULL) won't work
            {
                s.push(temp_node->right);//push the temp_node ka right
            }

                if(temp_node->left)// here we are checking if left node exist or not .....in case it does not then value is NULL so if(NULL) won't work
            {
                s.push(temp_node->left);
            }
            //here we are pushing right first beacuse we want to print left node first so after pushing right we will push left and top node will be the left one

        }
        //while loop ends

    } //else part ends
}
//////////PREORDER RECURRSIVE//////////
void preorder_reccursive(node* root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->data << "  ";
        preorder_reccursive(root->left);
        preorder_reccursive(root->right);
    }
}
/////////////INTORDER NON RECURSSIVE//////
void inorder_nonrecurrsive(node* &root)
{
     if(root==NULL)
    {
        return;
    }
    else
    {
        stack<node*>s;
        node* temp_node=root;
        while(!s.empty() || temp_node!=NULL)
        {
             while (temp_node!=  NULL)
        {
            s.push(temp_node);
            temp_node = temp_node->left;
            // here we are traversing until we get left most end and also storing in stack
        }
        /* temp_node must be NULL at this point */
        temp_node = s.top();
        s.pop();// this pop pops the left part and now top becomes the parent of left part and now we see wether parent wala part has right node or not
        cout <<temp_node->data << "  ";
        temp_node= temp_node->right;
       // ab yaha current temp node right wala hai to ab firse bahr wala loop chalega and then ander wal while loop jab tak last left nhi milta uss parent ka
       }/* end of while */
     }
}
/////////////INORDER RECURSSIVE/////////
void Inorder(node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->data << "  ";
        Inorder(root->right);
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
   / \    /
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
    cout<<"PREORDER NON RECURRSIVE FUNTION  :"<<endl;
    preorder_BTusing_stack(root);
    cout<<endl;
     cout<<"PREORDER RECURRSIVE FUNTION  :"<<endl;
     preorder_reccursive( root);
    /*
    IN PREORDER RROT PRINTED THEN ALL THE LEFT ARE PRINTED TILL WE GET NULL
    THEN RIGHT ARE PRINTED
    SO OUTPUT IS
    1 2 4 8 9 5 10 3 6 7
    HERE PREORDER FUNTION IS NON RECURSSIVE
    */
    cout<<endl;
    cout<<"INORDER NON RECURRSIVE FUNTION  :"<<endl;
    inorder_nonrecurrsive(root);
    cout<<endl;
    cout<<"INORDER RECURRSIVE FUNTION  :"<<endl;
    Inorder(root);
    /*
    IN INORDER PRINTING STARTS FROM THE LEFT MOST NODE THAT IS THE
    SO HERE IT IS 8 THEN IT PRINT ITS PARENT THEN IT PRINTS RIGHT NODE
    AND IT WILL TRAVERSE TO LEFT PART UNTIL WE GET A NULL
    SO OUTPUT WILL BE
    8 4 9 2 10 5 1 3 6 7
   */
    cout<<endl;
    return 0;
}
