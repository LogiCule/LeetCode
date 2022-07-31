/*
Links:
https://leetcode.com/problems/find-k-closest-elements/
https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

Sliding Window and Binary Search Approach:
Using binary search we find the insertion index of that element and from their we slide the window till it is k length wide

Binary search Approach:
this time we will find the begin of our window using binary search approach
we move towards the window which has less abs value

Heap Approach:
We use max heap to keep track of the highest abs value inserted and if the heap size is equal to k
we will pop the current top if its greater than the current value and insert the current value

*/

//Binary Search

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,high=arr.size()-k;
        while(low<high)
        {
            int mid = (low+high)/2;
            if(x-arr[mid]>arr[mid+k]-x)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        vector<int> ans(k);
        int j=0;
        for(int i=low;i<low+k;i++)
        {
            ans[j++] = arr[i];
        }
        return ans;
        
        
    }
};

// Heap Approach
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i:arr)
        {
            if(pq.size()<k)
            {
                pq.push({abs(x-i),i});
            }
            else 
            {
                if(pq.top().first>abs(i-x))
                {
                    pq.pop();
                    pq.push({abs(i-x),i});
                }
            }
        }
        vector<int> ans(k);
        for(int i=0;i<k;i++)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
