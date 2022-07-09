/*
Links:
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/

Here comes a question where the choices make their return
this time they are back for vengence.

we are given a sequence of inputs on a keypad and each button can have few options
so we can use recursion to produce all possible strings
think of it as a tree
from root to each leaf node will give u a possible word from the given input
*/

class Solution {
public:
    unordered_map<char,string> hash;
    Solution()
    {
        hash['2']="abc";
        hash['3']="def";
        hash['4']="ghi";
        hash['5']="jkl";
        hash['6']="mno";
        hash['7']="pqrs";
        hash['8']="tuv";
        hash['9']="wxyz";
        hash['0']=" ";
        
    }
    vector<string> res;
    void helper(string s,string ans,int i=0)
    {
        if(i==s.length())
        {
            res.push_back(ans);
            return;
        }
        for(int j=0;j<hash[s[i]].size();j++)
        {
            ans[i]=hash[s[i]][j];
            helper(s,ans,i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        string ans(digits.size(),'#');
        if(digits.size()==0)
            return res;
        helper(digits,ans);
        return res;
    }
};
