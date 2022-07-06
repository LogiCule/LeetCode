/*
Link: https://leetcode.com/problems/rotate-function/

the brute approach could be to rotate the array for each possible value of k 
k being the number of rotations.

it will be n^2

so how do we boil it down to an acceptable time complexity
cause believe me the above one give us TLE.
had to find it the hard way.

when we analyse further we can see every element is having the value 0 when it is chosen as pivot
and this will divide the ans into a left and right segment.
now here we can formulate to construct left and right sum after each pivot is moved to the right.
After few formulations I got to one which included prefix sum to get the current rotated array sum without actually rotating the array.
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int> left(nums.size()+1);
        for(int i=1;i<left.size();i++)
        {
            left[i] =left[i-1]+nums[i-1];
        }
        int maxx = 0;
        for(int i =1;i<nums.size();i++)
        {
            maxx += nums[i]*i; 
        }
        int sum=maxx;
        for(int i=1;i<=nums.size();i++)
        {
            sum-= (left[nums.size()]-left[i]);
            sum+= (nums[i-1]*(nums.size()-1))-left[i-1];
            maxx = max(sum,maxx);
        }
        return maxx;
    }
};
