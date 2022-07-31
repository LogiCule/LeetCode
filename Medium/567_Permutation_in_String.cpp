/*
Link : https://leetcode.com/problems/permutation-in-string/

Two Pointer + Hashing
First we can create a hash table of s1 and then create a hashkey for this string 
and keep a new rolling hash key for the curr window of s1 length for other string and move it by 1 each time 
and update the rolling hash and check the hash table if the hash key matches
*/
class Solution {
public:
    bool check(string s,int low,int high,vector<int> arr)
    {
        for(int i=low;i<=high;i++)
        {
            arr[s[i]-'a']--;
        }
        for(int i:arr)
            if(i!=0)
                return 0;
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        long long hash = 0;
        vector<int> arr(26);
        if(s1.length()>s2.length())
            return 0;
        for(char ch:s1)
        {
            hash+=ch*ch;
            arr[ch-'a']++;
        }
        long long curr=0;
        for(int i=0;i<s1.length();i++)
        {
            curr+=s2[i]*s2[i];
        }
        if(curr==hash && check(s2,0,s1.length()-1,arr))
            return 1;
        for(int i=s1.length();i<s2.length();i++)
        {
            curr+=(s2[i]*s2[i]-s2[i-s1.length()]*s2[i-s1.length()]);
            if(curr==hash && check(s2,i-s1.length()+1,i,arr))
                return true;
        }
        return false;
            
    }
};
