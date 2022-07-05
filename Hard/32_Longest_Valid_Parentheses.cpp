/*
Links:
https://leetcode.com/problems/longest-valid-parentheses/
https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

what is a valid paranthesis string
each open bracket should have a responding closing bracket for it after its occurence

Example:
()()(()()) Valid
)()()) Invalid

The first approach that comes to mind is we can check validity for each substring and keeptrack of max substring found

to optimize the first approach what we can do is simply we check validity for all substring of string size then check validity of substring of size-1 and so on
as soon we get  a valid one we return its length

Great but I think we can still do better as the above approach have a complexity of O(n^3) 
O(n^2) to generate all substring and O(n) 

Now we are gonna do this in a linear complexity.
we are gonna traverse the string and when we find an opening bracket we push it's index into the stack
and when we find a closing bracket
we check in the stack if the element at the top of stack is poiniting to an opening bracket or not
if yes we pop it and now we know that current index  - top of stack index will give us the length of valid parenthesis
otherwise we push the current index into stack;

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxx = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty() || s[st.top()]==')')
                {
                    st.push(i);
                }
                else if(s[st.top()]=='(')
                {
                    st.pop();
                    int len = st.empty()?-1:st.top();
                    maxx = max(maxx,i-len);
                }
            }
        }
        return maxx;
    }
};
