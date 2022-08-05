/*
Link: https://leetcode.com/problems/combination-sum-ii/

Recursive + Hashing approach:
We create a hashmap of all the characters and their frequency
now we can recursively add each number till the frequency is reached or the sum is reached
*/

class Solution {
public:
    unordered_map<int,int> hash;
    vector<vector<int>> ans;
    void helper(vector<int>& candidates,vector<int> curr,int target,int sum,int i=0)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }
        if(i==candidates.size())
            return;
        helper(candidates,curr,target,sum,i+1);
        for(int j=0;j<hash[candidates[i]];j++)
        {
            sum+=candidates[i];
            curr.push_back(candidates[i]);
            helper(candidates,curr,target,sum,i+1);
        }         
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        for(int i:candidates)
        {
            if(hash[i]==0)
            {
                temp.push_back(i);
            }
            hash[i]++;
        }
        vector<int> curr;
        helper(temp,curr,target,0,0);
        return ans;
    }
};
