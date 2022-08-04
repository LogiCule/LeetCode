/*
Link: https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> ans;
    void per(vector<int> nums,int i=0)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        per(nums,i+1);
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                swap(nums[i],nums[j]);
                per(nums,i+1);
                swap(nums[i],nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums);
        return ans;
    }
};
