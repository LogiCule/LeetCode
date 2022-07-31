/*
Links : 
https://leetcode.com/problems/range-sum-query-immutable/
https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1

Brute Force:
We will be given the start and end index
so just traverse the values between that range and return the sum

sounds a lit bit taxing calculating everysingle time.

Memomization Approach:
We store the sum till the current index at that index
and when we want a sum for any particular index we can just subtract the sum from the sum till end point with the sum before the start index
*/

class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        this->num.resize(nums.size());
        num[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            num[i]=nums[i]+ num[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return num[j] - (i==0?0:num[i-1]);
    }
};
