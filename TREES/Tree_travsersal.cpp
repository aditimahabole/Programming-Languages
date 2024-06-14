// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insert_node(vector<int>&arr,int i){
    TreeNode* root = NULL;
    if(i<arr.size()){
        root = new TreeNode(arr[i]);
        root->left = insert_node(arr,2*i + 1);
        root->right = insert_node(arr,2*i + 2);
    }
    return root;
}

void inorder_traversal(TreeNode* root){
    if(root == NULL) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

void preorder_traversal(TreeNode* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(TreeNode* root){
    if(root == NULL) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}

void levelorder_traversal(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* front = q.front();
        cout<<q.front()->data<<" ";
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
    return;
    
}
int main() {
   vector<int>arr= {1,2,3,4,5,6};
   TreeNode*root = insert_node(arr,0);
   cout<<"In order : "<<endl;
   inorder_traversal(root);
   cout<<endl;
   cout<<"Pre  order : "<<endl
   preorder_traversal(root);
   cout<<endl;
   cout<<"Post  order : "<<endl;
   postorder_traversal(root);
   cout<<endl;
   cout<<"Level order : "<<endl;
   levelorder_traversal(root);
    return 0;
}
