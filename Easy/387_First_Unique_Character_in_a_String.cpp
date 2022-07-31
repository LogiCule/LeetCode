/*
Links:
https://leetcode.com/problems/first-unique-character-in-a-string/
https://practice.geeksforgeeks.org/problems/repeated-character2058/1

Brute force:
go to each index and count the freq of that character and then return if the freq matches the condition

Hashing Approach:
store the freqeucy of each alphabet in a hash table.
then traverse the string and return the index of matched index 
if you ffinish the loop return -1
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={};
        for(char i:s)
            arr[i-'a']++;
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
