/*
Links :
https://leetcode.com/problems/binary-tree-paths/
https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1

recursive problem with no overlapping subproblems
so we can simply use recursion to find each path and calculate the path whilst traversing the tree.
when we arrive at a node we will have the path we follwoed to get here 
if the node we reached is leaf node we add it to the ans vector else we add it to the path 
and call the function for its children
*/

class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root,string res="") {
        if(!root)
            return ans;
        res+= to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(res);
            return ans;
        }
        binaryTreePaths(root->left,res+"->");
        binaryTreePaths(root->right,res+"->");
        return ans;
    }
};
