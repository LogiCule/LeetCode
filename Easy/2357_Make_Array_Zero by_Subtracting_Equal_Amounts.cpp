/*
Links: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

Brute Force:
Stimulating the whole process till the minimum non zero element does not exist.
Find the min 
then reduce it from all values that are not 0 so far

Binary Search:

Starting from 0 will start finding number just greater than it and use it to search the next greater do it till no greater exists.
we can sort the array and then do binary search on it.

O(NlogN)
*/

class Solution {
public:
    int getIndex(vector<int>& nums,int target)
    {
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int val = 0;
        while(1)
        {
            val = getIndex(nums,val);
            if(val==-1)
                break;
            val = nums[val];
            count++;
        }
        return count;
    }
};
