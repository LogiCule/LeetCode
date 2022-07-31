/*
Links:

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

Heap Approach:
Keep pushing into the heap till heap size is less than k 
and when heap size is greater than k
we push only if the value is smaller than the top 
if its greater than the top we skip the ccurent row and move to the next
in the end return the top of heap
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto i:matrix)
        {
            for(int j:i)
            {
                if(pq.size()<k)
                {
                    pq.push(j);
                }
                else
                {
                    if(pq.top()<=j)
                        break;
                    pq.pop();
                    pq.push(j);
                }
            }
        }
        return pq.top();
    }
};
