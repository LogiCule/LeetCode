/*
Link : https://leetcode.com/problems/simplify-path/

Stack Approach:
we traverse the string  and when we find / we ignore it
then we make the string till the next / and see
if the new string .. then we pop the stack if any element in it
if . is the new string we ignore 
else we push it into the stack

*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i=0;
        while(i<path.length())
        {
            if(path[i]=='/')
            {
                i++;
                continue;
            }
            string temp = "";
            while(i<path.length() && path[i]!='/')
                  temp+=path[i++];
            if(temp.compare(".")==0)
            {
                continue;
            }
            else if(temp.compare("..")==0)
            {
                if(s.size())
                    s.pop();
            }
            else
                s.push(temp);
            
        }
        string res = "";
        while(s.size())
        {
            res = "/" + s.top()+res;
            s.pop();
        }
        return res.length()?res:"/";
    }
};
