/*
Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

Brute Force:
we can caluclate sum of each sumarray of size k and count the correct sums

Two pointer:
Calculating the sum of each subarray of k using two pointer gives it a linear complexity
instead of quadratic
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int summ=0;
        int count=0;
        for(int i=0;i<k;i++)
        {
            summ+=arr[i];
        }
        count=(summ/k)>=threshold;
        for(int i=k;i<arr.size();i++)
        {
            summ=summ-arr[i-k]+arr[i];
            //cout<<summ<<" ";
            count+=((summ/k)>=threshold);
        }
        return count;
    }
};
