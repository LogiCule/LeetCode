/*
Link : https://leetcode.com/problems/count-good-meals/

The normal approach can be to iterate through all possible pairs and check if the sum is power of 2 or not.
Looks simple but believe me this is gonna give a tle
your welcome, saved you a wrong submission

Now what we can observe is we are looking for a particular set of numbers in our sum
If you have done Two sum then problem will get easier
depending on the range of our numbers we can call two on our array for each power of 2 
the two sum will return number of possible pair for that particullar sum
so call first for 1 then for 2 then for 4 and so on.

*/
class Solution {
public:
    int countPairs(vector<int>& arr) {
        long count = 0;
        int mod = 1000000007;
        unordered_map<int,int> hash;
        vector<int> vec;
        for(int i:arr)
        {
            if(hash[i]==0)
            {
                vec.push_back(i);
            }                
            hash[i]++;
        }
        sort(vec.begin(),vec.end());
        int shift = 0;
        for(;shift<32;shift++)
        {
            int target = 1<<shift;
            int low=0,high=vec.size()-1;
            while(low<=high)
            {
                if(low==high && vec[low]+vec[high]==target)
                {
                    count =  (count+ (1l*hash[vec[high]]*(hash[vec[high]]-1)/2)%mod)%mod;
                    low++;
                    high--;
                }
                else if(vec[low]+vec[high]==target)
                {
                    count =  (count+ (1*hash[vec[high]]*(hash[vec[low]]))%mod)%mod;
                    high--;
                    low++;
                }
                else if(vec[low]+vec[high]<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return count;
    }
};
