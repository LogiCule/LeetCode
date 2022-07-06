/*

https://leetcode.com/problems/fibonacci-number/

The recurrence relation for fibonacci number is f(n)  = f(n-1)+f(n-2)
where f(1)=1 f(0)=0;

we can do it using recursion
calling for f(n-1) and f(n-2)
till we reach 0 or 1 as the value for both cases are known

this approach is going to take n extraspace in form of the recursive call stack space

we can call use memomization here to store the result of a call if its being called first time
else we return its stored result
*/

class Solution {
public:
    vector<int> hash;
    int fib(int n) 
    {
        if(n<=1)
            return n;
        if(hash.size()<=n-2)
        {
            hash.push_back(fib(n-1)+fib(n-2));
            
        }
        return hash[n-2];
    }
};
