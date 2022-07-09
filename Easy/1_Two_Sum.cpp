/*
Links:
https://leetcode.com/problems/two-sum/
https://practice.geeksforgeeks.org/problems/key-pair5616/1/

normally the problems look difficult as we have to look for two numbers to get the value
we can change the problem to.
we assume that we have one of the two numbers,lets call it x and then we have to find target-x in the array.

Brute force approach
Starting from first element we take each element as candidate element
and for each element we can find its pair to the right of it.

we have to take every element as a candidate thats for sure.
so we need to optimise the search for the pair.
what if we sort the array?

lets take a look 
we keep the approach similar to the previous one
only chnge the search for pair by alying binary search to the right of it

but after sorting we have a property given by the sum of edge elements
if the sum of edge element is greater than target we move the right edge inwards
else we move the left edge till we find the target sum.

We have boiled down our solution to nlogn
lets see if we can take it to linear or not
is there any way to search in constant time?
yep hashing now instead of binary search we look in our hash table if we have seeen the pair or not.
this approach ofcourse takes up extra space but reduces the time.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            if(freq.find(target-nums[i])!=freq.end())
            {
                vector<int> ans;
                ans.push_back(freq[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            freq[nums[i]]=i;
        }
        vector<int> ans;
        return ans;
    }
};
