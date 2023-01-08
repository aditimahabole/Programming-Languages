// https://leetcode.ca/2016-05-04-156-Binary-Tree-Upside-Down/
//------------------------------------------------------------
// Example:
//  Input: [1,2,3,4,5]

//     1
//    / \
//   2   3
//  / \
// 4   5

//  Output: return the root of the binary tree [4,5,2,#,#,3,1]
//     4
//    / \
//   5   2
//  / \
// 3   1

// explanation : suppsose only 
//     1
//    / \
//   2   3

// output should be
//     2
//    / \
//   3   1

// we see that 
// left node should become root 
// right node 3 becomes left to left node 2
// root 1 becomes right of left node
//------------------------------------------------------------
// CODE:
TreeNode* upsideDownBinaryTree(TreeNode* root)
{
    if(root ==NULL || root->left ==NULL) return root; 
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    TreeNode* new_root = NULL;
    while(left)
    {
        TreeNode* next_left = left->left;
        TreeNode* next_right = left->right;
        if(!new_root) root->left = NULL; root->right =NULL;
        //real root ke bacche nhi honge obvio 
        //kyuki vo ab right most leaf node ban gya hai
        new_root = left;
        new_root->left = right;
        new_root->right = root;
        root = left; // from node 1 and after fliping we move to node 4 because that should be now flipped
        left = next_left;
        right = next_right;
    }
    return new_root;
}
//explaining this example by code
//     1
//    / \
//   2   3
//  / \
// 4   5
//root = 1
//left = 2
//right = 3
// new_root = NULL
// next_left = left->left that is 2->left that is 4
// next_right = left->right that is 2->right that is 5
//as new_root == NULL so root->left = root->left = NULL that is 1->left =NULL 1->right =NULL (1 becomes right most leaf node according to output)
//now new root = left that is new_root = 2
// new_root->left should be root->left (TreeNode*left = root->left)| 2->left = 1->right = 3 so | 2->left = 3
//new_root ->right should be root itself to we wrote new_root->right = root | new_root->right = 1| 2->right = 1
// now we traverse by making root as left that is node 2 from original tree will be root and it will be flipped 
// so again we go
//root = 2
//left = 4
//right = 5
//next_left = left->left = 4->left = NULL
//next_right = left = right = 4->right =  NULL
//new_root = left = 4
//new_root ->left = root->right| 2->right = 5 | 4->left = 5 |
//new_root->right = root | 4->right = 2 |
//root = left = 4
//left = NULL
//right =NULL
//while loop ends here as left ==NULL
// so now new_root = 4 we return this 
