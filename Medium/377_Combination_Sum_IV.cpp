/*
Link:https://leetcode.com/problems/combination-sum-iv/

TLE Approach:
recursively we choose to add the number to our total sum and decrease the sum by the current number 
and call the recursive function with the new updated sum

Memomized approach:
as we need to know how many combination are for each sum are there so we store it in an array 
if the sum is not calculated yet we call the sub sums which lead to this sum

*/
class Solution {
public:
    vector<int> dp;
    int dfs(vector<int>& nums, int target)
    {
        if(target<0)
            return 0;
        if(target==0)
        {
            return 1;
        }
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
        for(int i:nums)
        {
            ans+=dfs(nums,target-i);
        }
        dp[target] = ans;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        return dfs(nums,target);
    }
};
