/*
Link : https://leetcode.com/problems/candy/

Greedy Approach : 
This approach will be quite obvious if you take a few examples and try to come up with a solution.
First we need to create the answer array using just the conditions for right peak
and then we update the array accordingly checking the left peak
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                nums[i]=nums[i-1]+1;
        }
        int ans = nums[ratings.size()-1];
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1] && nums[i]<=nums[i+1])
                nums[i]=nums[i+1]+1;
            ans+=nums[i];
        }
        return ans;
    }
};
