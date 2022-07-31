/*
Link: https://leetcode.com/problems/range-sum-query-mutable/

Brute Force:
For this we have too choice either make the update function expensive or the getSum function expensive.

Expensive getSum function can be made calculating the sum by travsersing the range in the array 
and updating in constant time by changing the value at the given index

Expensive update function can be done by first keeping a prefix sum array for the given array.
when we update a value we can update the chnge in the sum from that index onwards till the last index 
and getting the sum for a range in constant time.

Now the worse case for this scenario is O(number of queries * size of array)

Segment Tree Approach:

Segment Tree is a datastructure that has two operations update and get sum 
update : changes the value at given index
get sum : gets the sum till that index

First we can create the segment tree for the given array
and use update and getsum functions accordingly.

This method decreaes the complexity from O(number of queries * size of array) to O(number of queries * log(size of array))

*/
struct STree{
    int sum;
    int i;
    int j;
    STree* left;
    STree* right;
};
STree* createStree(vector<int>& nums,int i,int j)
{
    if(i>j)
        return NULL;
    STree* curr = new STree();
    curr->i=i;
    curr->j=j;
    if(i==j)
    {
        curr->sum = nums[i];
        return curr;
    }
    curr->left = createStree(nums,i,(i+j)/2);
    curr->right = createStree(nums,(i+j)/2+1,j);
    curr->sum = (curr->right?curr->right->sum:0)+(curr->left?curr->left->sum:0);
    return curr;
}
void updateS(STree* root,int index,int val)
{
    if(!root)
        return;
    if(root->i==root->j )
    {
        if(root->i==index)
            root->sum=val;
        return;
    }
    int mid = (root->i+root->j)/2;
    if(root->i<=index && mid>=index)
        updateS(root->left,index,val);
    else
        updateS(root->right,index,val);
    root->sum = (root->right?root->right->sum:0)+(root->left?root->left->sum:0);
}
int getSum(STree* root,int index)
{
    if(index==-1)
        return 0;
    if(!root)
        return 0;
    if(root->j==index)
        return root->sum;
    int mid = (root->i+root->j)/2;
    if(root->i<=index && mid>=index)
        return getSum(root->left,index);
    else
        return (root->left?root->left->sum:0)+getSum(root->right,index);
     
}
class NumArray {
public:
    STree* root;
    NumArray(vector<int>& nums) {
        root = createStree(nums,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        updateS(root,index,val);
    }
    
    int sumRange(int left, int right) {
        return getSum(root,right)-getSum(root,left-1);
    }
};

