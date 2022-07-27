/*
Links
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

The Auxilary data structure approach:
We can create an array for the pre order of the tree and 
then linearly traverse it and update the links as specified by the question

it feels kinda redudant and stupid using array to solve a question of trees.


The Tree Approach:
lets try to bring recursion into this.
the given linked list formed with root + left linked list + right linked list.
now this can be our recurrence relation.
we can ask the recursoin call to make the linked list of the left node first and right node and then combine them.

*/

class Solution
{
    public:
    Node* combine(Node* h1,Node* h2)
    {
        if(!h1)
            return h2;
        if(!h2)
            return h1;
        Node* temp = h1;
        while(temp->right)
        {
            temp=temp->right;
        }
        temp->right = h2;
        return h1;
    }
    
    void flatten(Node *root)
    {
        //code here
        if(!root)
            return ;
        Node* l = root->left;
        Node* r = root->right;;
        root->left=NULL;
        root->right=NULL;
        flatten(l);
        flatten(r);
        combine(combine(root,l),r);
    }
};
