/*

Links: 
https://leetcode.com/problems/valid-parentheses/
https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/

This is problem is such a problem that once you see what fulfills the condition of being a valid parantheses the problem will solve itself.
Dont believe me? Lets have a look!

Valid parantheses is a string in which for every open bracket 
there should be a corresponding bracket.
What we need to check here is that every latest opened bracket is closed before another is closed.
We see that the last bracket which was opened is always checked for closing 
Last In First Out 
which is provided by stack
if we push every opened bracket in stack and at every clsoing bracket check the stack for its corresponding pair
our checks are done
and after the string is processed we check for stack emptiness as well
*/

class Solution {
public:
    bool isValid(string s) {
        stack <int> q;
        for(int ch:s)
        {
            if(ch==40 || ch==123 || ch==91)
            {
                q.push(ch);
            }
            else
            {
                if(q.empty())
                    return 0;
                int diff = ch-q.top();
                if(diff==1 || diff==2)
                    q.pop();
                else 
                    return 0;
            }
        }
        if(q.empty())
            return 1;
        return 0;
    }
};
