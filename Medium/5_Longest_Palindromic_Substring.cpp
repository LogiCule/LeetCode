/*
Links : 
https://leetcode.com/problems/longest-palindromic-substring/
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/

Brute Force Approach
Find all substring and keep the track of the biggest palindromic substring
bit of a hassle isnt it

lets look at the characteristics of a palindrome
its a mirror from center
so we can go to each element at take it as center and see how far we can go till the palindromic properties keep intact.
we have to keep the even and odd palindromic case in mind as well
*/

class Solution {
public:
    string ret;
    int stringCheck(string s, int i,int j)
    {
        int ans=1;
        while(i>=0 && j<s.length())
        {
            if(s[i]!=s[j])
                break;
            ans=max(ans,j-i+1);
            if(ret.size()<ans)
            {
                ret = s.substr(i,j-i+1);
            }
            i--;j++;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int maxx=0;
        ret="";
        if(s.length()<=1)
        {
            return s;
        }
        for(int i=0;i<s.length()-1;i++)
        {
            maxx = max(maxx,max(stringCheck(s,i,i),stringCheck(s,i,i+1)));
        }
        return ret;
    }
};
