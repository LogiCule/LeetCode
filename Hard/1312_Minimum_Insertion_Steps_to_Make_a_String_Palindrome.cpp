/*
Links: 
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1/

Lets look at the  problem statement closely

we need to check palindrome
so it is better form from the edges.
our choice at each instance will go like this
we have to indicies marking the current edge of the string we are checking
let them be i,j
so when ith element and jth element are same we can say that this will conribute to our subsequnce which is a palindrome 
move the two pointers inwards to check the potential palindromic subsequence.
if the ith  and jth element do not match we have two choice either we move the ith pointer or the jth.

Now how do we implement this
we can implement this via recursion.
It will take a lot of timesince there are lot of cases for whom the recursion will be called multiple times.

what if we store those answers to reduce the number of calls (coughs** yep memomization)

this memoization can be done without recursion if we use dp approach of longest common sequence for string and reverse of the given string
*/

class Solution {
public:
    string  rev(string s)
    {
        int low=0,high=s.length()-1;
        while(low<high)
        {
            char ch = s[low];
            s[low++] = s[high];
            s[high--]=ch;
        }
        return s;
    }
    int  LCS(string s,string t)
    {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1));
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[i].size();j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = (1+ dp[i-1][j-1]);
                }
                dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return s.length() - dp[s.length()][t.length()];
    }
    int minInsertions(string s) {
        return LCS(s,rev(s));
    }
};
