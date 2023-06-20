// Problem Statement
// https://unstop.com/code/practice/250272
// Ram has found himself a new place for his thievery again. There is only one entrance to this area, called root.
// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized 
// that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money Ram can rob without alerting the police.
// Input Format
// Each line contains a level order traversals of tree:
// “1 2 3 4 null 5”
// Null node in level order traversal is represented by ‘null’
// Output Format
// Print the maximum amount of money the thief can rob without alerting the police.
// Constraints
// The number of nodes in the tree is in the range [1, 5000].
// 0 <= Node.val <= 104
// Sample Testcase 0
// Testcase Input
// QWD
// Testcase Output
// QWD
// Sample Testcase 1
// Testcase Input
// 3 2 3 null 3 null 1
// Testcase Output
// 7
// Explanation
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 
// Sample Testcase 2
// Testcase Input
// 3 4 5 1 3 null 1

// Testcase Output
// 9
// Explanation
// Maximum amount of money the thief can rob = 4 + 5 = 9.
// ###################################################################################################
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x)
  {
    val = x;
    left = NULL;
    right = NULL;
  }
};

vector<string> split(string s,char c)
{
  vector<string> store;
  string temp ="";
  for(auto i:s)
  {
    if(i!=' ') temp+=i;
    else if(i == ' ')
    {
      store.push_back(temp);
      temp = "";
    }
  }
  if(temp!=" ") store.push_back(temp);
  return store;
}

TreeNode* build_tree(vector<string> nodes, int index)
{
  if(index>=nodes.size() || nodes[index] == "null") {
    // cout<<nodes[index]<<"   "<<index<<endl;
    return NULL;
    }
  int data = stoi(nodes[index]);
  TreeNode* root = new TreeNode(data);
  root->left = build_tree(nodes,2*index+1);
  root->right = build_tree(nodes,2*index+2);
  return root;
}
int rob(TreeNode* root,unordered_map<TreeNode*,int> &dp)
{
  if (root == NULL) return 0;
  if(dp.find(root)!=dp.end()) return dp[root];
  int rob_current = root->val;
  if(root->left) rob_current+= rob(root->left->left,dp)+rob(root->left->right,dp);
  if(root->right) rob_current+= rob(root->right->left,dp)+rob(root->right->right,dp);
  int skip_current = rob(root->left,dp)+rob(root->right,dp);
  int max_amount = max(rob_current,skip_current);
  dp[root] = max_amount;
  return max_amount;
}

int main() {
    string input;
    vector<string> nodes;
    while(cin>>input)
    {
      nodes.push_back(input);
    }
    // getline(cin,input);
    // vector<string> nodes = split(input,' ');
    // cout<<"---------------"<<endl;
    // for(auto i:nodes) cout<<i<<endl;
    // cout<<"---------------"<<endl;
    TreeNode* root = build_tree(nodes,0);
    // cout<<"---------------"<<endl;
    // cout<<root->val<<endl;
    // cout<<root->left->val<<endl;
    // cout<<root->right->val<<endl;
    // cout<<"---------------"<<endl;
    unordered_map<TreeNode*,int>dp;
    int max_amount = rob(root,dp);
    cout<<max_amount;
    return 0;
}
