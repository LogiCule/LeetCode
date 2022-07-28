/*
Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

concatination approach:

add all the string in one line
u can add in different ways as concatenation will take a lot of time
we can use merge sort logic to add them as it reduces the total number of concatenation.
perform concatenation on both and then compare the answer.

simulation approach:
we will assume the that out result is already there.
we just need to make a way to access it like the result.
we will make two pointers for each array
one will point at to the current string and other will point to the curret char of that strnng
this way we can compare the strings
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0;
        int ii=0,ij=0;
        while(i<word1.size() && j<word2.size())
        {
                if(word1[i][ii]!=word2[j][ij])
                    return 0;
                ii++;
                ij++;
                if(i<word1.size() && word1[i].length()<=ii)
                {
                    i++;
                    ii=0;
                }
                if(j<word2.size() && word2[j].length()<=ij)
                {
                    j++;
                    ij=0;
                }
            
        }
        return j==word2.size() && i==word1.size();
        }
};
