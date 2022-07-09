/*
Links:
https://leetcode.com/problems/longest-substring-without-repeating-characters/
https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1/

Here comes a concept known as sliding window 
imagine a rubber band that can stretch endlessly or atleast to the length of string
now put the rubber band at the start and then keep stretching till as u go through character u are seeing through first time
and when u come over a character u have seen before stop here record the length and 
then push the lower end of the rubber band to the position next to the previously seen position of the current element and 
keep doing that till the rubber band reaches the end of string
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxx=0;
        int low=0,high=0;
        unordered_map <char,int> freq;
        while(high<s.length())
        {
            if(freq.find(s[high])==freq.end() || freq[s[high]]==-1)
            {
                freq[s[high]]=high;
                maxx = max(maxx,high-low+1);
                
            }
            else
            {
                for(int i=low;i<freq[s[high]];i++)
                {
                    freq[s[i]]=-1;
                }
                low=freq[s[high]]+1;
                freq[s[high]]=high;
                maxx = max(maxx,high-low+1);
            }
            high++;
        }
        return maxx;
        
    }
};
