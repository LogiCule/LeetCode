/*
Links:
https://leetcode.com/problems/combination-sum/
https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

Backtracking Approach:
at eeach number we have choice to add it to the total num or not
and after adding we can add it again or move forward.
*/

vector<vector<int>> ans;
class Solution {
public:
    void dfs(vector<int>& candidates, int target,vector<int> nope,int index)
    {
        if(target==0)
        {
                ans.push_back(nope);
                return;
        }
        if(index==candidates.size())
        {
            return;
        }
        dfs(candidates,target,nope,index+1);
        if(target>=candidates[index])
        {
            int count = target/candidates[index];
            for(int  i=1;i<=count && target >= candidates[index];i++)
            {
                nope.push_back(candidates[index]);
                dfs(candidates,target-(candidates[index]),nope,index+1);
                target-=candidates[index];
            }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        ans.resize(0);
        vector<int> nope;
        dfs(candidates, target,nope,0);
        return ans;
    }
};
