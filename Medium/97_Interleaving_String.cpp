/*
Links : 
https://leetcode.com/problems/interleaving-string/
https://practice.geeksforgeeks.org/problems/interleaved-strings/1/

this question is quite situation based
suppose we have two pointers i& j both pointing to one of the character in each string
so the whats the  max possible position of any of those two in the interleaved string 
it could not be more than i+j
so at each step we can recursively check if one of our string matches we call with the decreased string or we return false

now what can be our based case what is the least value that we can get both of the strings are empty
if both are empty and the third is  empty as well then we have an interleaved string other wise no
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool dp[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return dp[s1.length()][s2.length()];
    }
};
