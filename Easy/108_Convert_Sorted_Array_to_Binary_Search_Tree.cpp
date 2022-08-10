/*
Links  :
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
https://practice.geeksforgeeks.org/problems/array-to-bst4443/1

Dfs approach:
as the array is sorted we know to make the tree a balaned we need to put almost same number of elements in left subtree and the right subtree
so we can always root the tree at the middle index and do it recursively for the left subtree and right subtree
*/

class Solution {
public:
    TreeNode* helper(vector<int>& nums,int left,int right)
    {
        if(left>right)
            return NULL;
        int mid = (right+left)/2 + (right-left)%2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = helper(nums,left,mid-1);
        temp->right = helper(nums,mid+1,right);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
