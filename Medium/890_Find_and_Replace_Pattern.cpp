/*
Links:
https://leetcode.com/problems/find-and-replace-pattern/
https://practice.geeksforgeeks.org/problems/match-specific-pattern/1

We need to check for a pattern.
We can map each letter to the letter in the pattern
and if a letter is already mapped while we try to map it then we have a string that does not match the pattern
*/

class Solution {
public:
    vector<string> ans;
    bool isPattern(string a,string b)
    {
        unordered_map<char,char> m;
        int arr[26]={};
        for(int i=0;i<a.length();i++)
        {
            if(m[b[i]]==NULL && arr[a[i]-'a']==0)
            {
                m[b[i]]=a[i];
                arr[a[i]-'a']=1;
            }
            if(m[b[i]]!=a[i])
                return 0;
        }
        return 1;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        for(auto i:words)
        {
            if(isPattern(i,pattern))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
