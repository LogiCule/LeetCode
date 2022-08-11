/*
Links: 
https://leetcode.com/problems/validate-binary-search-tree/
https://practice.geeksforgeeks.org/problems/check-for-bst/1

Brute Force: We can go to each node and check if all the nodes in the right subtree are greater than its value 
and all the nodes in the left subtree are smaller than this. 

Inorder Traversal Approach: We can store the inorder traversal of the tree and traverse the array to check for any inversions

Checking while travsering:
We can go to each node, starting from root and we will assume that root can have value from -inf to inf and 
then check if the left subtree has all the values are from the range of -inf to root->val and 
for the right subtree the values are from root->val to inf.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root, long left  = LONG_MIN,long right = LONG_MAX) {
        if(!root)
            return 1;
        if(root->val>left && root->val<right)
        {
            return isValidBST(root->left,left,root->val) && isValidBST(root->right,root->val,right); 
        }
        return 0;
    }
};
