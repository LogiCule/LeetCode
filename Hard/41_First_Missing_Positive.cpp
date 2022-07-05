/*

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len =  nums.size();
        int is_one = 0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==1)
            {
                is_one =1;
            }
            else if(nums[i]<=0 || nums[i]>len)
            {
                nums[i]=1;
            }
        }
        if(is_one!=1)
            return 1;
        for(int i=0;i<len;i++)
        {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]*=-1;
        }
        for(int i=0;i<len;i++)
            if(nums[i]>0)
                return i+1;
        return len+1;
    }
};
