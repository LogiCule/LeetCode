/*
Links:
https://leetcode.com/problems/sliding-window-maximum/
https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1

Brute Force:
calculate max for each subrray of and append it to the ans array

Deque Approach:
we need to keep sequence of elements who could be potential answers 
we make a queue for first k elements following this logic
while inserting the element we empty the queue from back till the last element is greater than the current element
now we have our answer for the first k sized subarray.
from now on we iterate through the array starting from the kth index
as it will be the last element in the next k sized subarray
and we remove the first element if its index is not included in the current k sized subarray
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1)
            return nums;
        deque<int> d;
        for(int i=0;i<min(k,(int)nums.size());i++)
        {
            while(d.size() && nums[d.back()]<nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[d.front()]);
        
        for(int i=k;i<nums.size();i++)
        {
            if(!d.empty() && nums[d.front()]==nums[i-k])
            {
                d.pop_front();
            }
            while(!d.empty() && nums[d.back()]<nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        return ans;
        
    }
};
