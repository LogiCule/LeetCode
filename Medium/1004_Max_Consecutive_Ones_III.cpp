/*
Links:
https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
https://leetcode.com/problems/max-consecutive-ones-iii/

Brute Force:
We can start the answer subarray from each index and go on till we get allones or atmost k 0's
and get the max of those

Two Pointer Approach:
We maintain a window and keep expanding till we get ones or get k 0's
if we get k 0's we decrease the low pointer and make it reach the left most 0
*/

class Solution {
public:
    int longestOnes(vector<int>& arr, int m) {
        
        int low = 0,high=0;
        int n=arr.size();
        int count = 0;
        int sum = 0;
        int maxx  = 0;
        while(high<n)
        {
            
            if(arr[high])
            {
                sum++;

            }
            else
            {
                if(count<m)
                {
                    sum++;
                    count++;
                }
                else
                {
                    while(arr[low])
                    {
                        sum--;
                        low++;
                    }
                    low++;
                }
            }
            high++;
            maxx = max(maxx,sum);
        }
        return maxx;
        
    }
};
