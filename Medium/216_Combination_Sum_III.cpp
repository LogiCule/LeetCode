/*
Link: https://leetcode.com/problems/combination-sum-iii/

this is a knapsack based problem
we have been given how many items we can have in our knapsack and the weight value it should contain
We can keep add elements into our knapsack till it reaches the limit and if the sum matches we add it to the overall answer
*/

class Solution {
public:
    vector<vector<int>> ans;
    void helper(int k,int n,vector<int> curr,int sum=0,int i=1)
    {
        
        if(k==curr.size() && n==sum)
        {
            ans.push_back(curr);
            return;
        }
        if(sum>n || curr.size()>k)
            return;
        if(i>9)
            return;
        helper(k,n,curr,sum,i+1);
        if(sum+i<=n)
        {
            curr.push_back(i),sum+=i;
            helper(k,n,curr,sum,i+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        helper(k,n,arr);
        
        return ans;
    }
};
