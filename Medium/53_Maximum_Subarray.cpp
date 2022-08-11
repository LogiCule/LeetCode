/*
Links:
https://leetcode.com/problems/maximum-subarray/
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

Brute Force:
Calculate sum for each subarray and get the max of them

Kadanes Algo:
We maintain a running sum and a max sum
and each element we check if adding the current element to the curr sum is greater than the curr val
if yes we add it and update the max sum if the curr sum exceeds the max sum
if no we make the curr sum as curr val and check max sum
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =nums[0];
        for(int i=1;i<nums.size();i++)
        {
            nums[i] = max(nums[i],nums[i-1]+nums[i]);
            sum = max(sum,nums[i]);
        }
        return sum;
    }
};
