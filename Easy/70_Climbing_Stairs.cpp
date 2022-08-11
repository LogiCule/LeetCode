/*
Links:
https://leetcode.com/problems/climbing-stairs/
https://practice.geeksforgeeks.org/problems/reach-the-nth-point5433/1

Recurrence Relation : 
for this question the relation is f(n) = f(n-1) + f(n-2)
where f(1) = 1 and f(2) = 2;

Recursive Approach:

We can recursively ask for the number of ways to climb stairs which are less than n till we can form the value for n.
breaking down the problem into smaller prolems and solving it.
For n it will call the func for n-1 and n-2 to form the current answer

But in this approach there is a huge overhead as in many case we are executing the whole function call chain 
for the values we already know the answer.
We can store the values if we are calling it for the first time
and then next time instead of executing the whole function call chain , we take the value straight from the stored value.

Recursive + Memoization :

How do we perform the storing ,as we know that to get the nth way to climb stairs we will need the values from 1 to n-1 
so we need a structure which can map the answer , the nth value being the key and the answer being the value mapped to that key
we can use a hashmap or an array 

The next problem is how do we kno that we have calculate the state or not
in hashmap it will be easy as it will contain only the calculated value
and in array we can put the default value of all the memory blocks as -1 since there is no way that the number of ways to climb a stair is in negative
Now we need to modified the above recursive approach is do a check before calling the function that the given value exists in the hash or not.

Iterative + Memoization:
We create the same structure to store the values answer and intialize it for 1 and 2
and we build our way to nth solution iteratively.

Iterative Approach:
While doing the above approach we observed that to calculate the current ans we only the previous two states
so we can elimate the need of whole map and only store the last two states in two varibles 
*/

class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2;
        if(n<=2)
            return n;
        for(int i=3;i<=n;i++)
        {
            b=a+b;
            a=b-a;
        }
        return b;
    }
};
