/*
Links:
https://leetcode.com/problems/binary-tree-right-side-view/
https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/

What is right view?
THe nodes you see when tree is viewed only from the right side
or in other words the last node of each level will give you right view

We can perform level order traversal and put the last node we see in the answer array at the index of its level
What i did was i performed a dfs on the tree and pssed an extra parameter to the function that denotes the index in the answer array for the current node
if the array size is less than or equal to that index we increase the size and put the current node at that index.
*/
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root,int i=0) {
        if(!root)
            return ans;
        if(ans.size()<=i)
        {
            ans.resize(i+1);
        }
        ans[i]=root->val;
        rightSideView(root->left,i+1);
        rightSideView(root->right,i+1);
        return ans;
    }
};
