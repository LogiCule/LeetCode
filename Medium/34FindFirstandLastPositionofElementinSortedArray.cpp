/*
Links : 
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x2041/1

Brute Force :-
As we know that the array is sorted the first index of the element will be neareset from the 0th index element 
and the last index will be closer to the final element of the array. 
So we can linearly search for the first index of the element and if we find the element then we can search for the last index linearly as well.

Optimized Approach:
In the previous approach we did not take advantage of the sorted property of our array
so this time we will search for the element using binary search.
We will make 2 bst functions
BSTLeft wll check for the first occurence of the given element
BSTright will check for the last occurence of the given element
*/

class Solution {
public:
    int firstIndex(vector<int> nums,int low,int high,int target)
    {
        if(low>high)
        {
            return -1;
        }
        int mid  = (low+high)/2;
        if(nums[mid]==target)
        {
            if(mid==0 ||nums[mid-1]!=target)
                return mid;
            else 
                return firstIndex(nums,low,mid-1,target);
        }
        else if(nums[mid]>target)
            return firstIndex(nums,low,mid-1,target);
        return firstIndex(nums,mid+1,high,target);
        
    }
    int lastIndex(vector<int> nums,int low,int high,int target)
    {
        if(low>high)
        {
            return -1;
        }
        int mid  = (low+high)/2;
        if(nums[mid]==target)
        {
            if(mid==nums.size()-1 ||nums[mid+1]!=target)
                return mid;
            else 
                return lastIndex(nums,mid+1,high,target);
        }
        else if(nums[mid]>target)
            return lastIndex(nums,low,mid-1,target);
        return lastIndex(nums,mid+1,high,target);
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0]=firstIndex(nums,0,nums.size()-1,target);
        ans[1]=lastIndex(nums,0,nums.size()-1,target);
        return ans;
    }
};
