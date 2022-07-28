/*
Links:
https://leetcode.com/problems/valid-anagram/
https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1

anagram is when one string is a permutation of other string and vice versa
so how can we check if two string are anagrams.
just check if the count of each character is same in both strings

using hashing we can get the count of each character and check that.
using sorting, sorting both strings will make them equal if they are anagram.

use the hashing approach as it has linear time complexity
use the sorting approach when space use is limited it has nlogn complexity but constant space

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={};
        for(char ch:s)
            freq[ch-'a']++;
        for(char ch:t)
        {
            freq[ch-'a']--;
        }
        for(int i:freq)
            if(i!=0)
                return false;
        return true;
    }
};
