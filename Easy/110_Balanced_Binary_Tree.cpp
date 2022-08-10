/*
Links:
https://leetcode.com/problems/balanced-binary-tree/
https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

Double Traversal:
We can go to each node and calculate the height for its left and right subtree 
by a helper function which gets the height of a given tree

Single Traversal:
This time we will assume that our tree is balanced at the start and now as we calculate the height 
we will check if any of the state is causing disbalance and change our assumption to false
*/

class Solution {
public:
    bool state;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right)>1)
            state=0;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        state=1;
        height(root);
        return state;
    }
};
