/*
Links:
https://leetcode.com/problems/linked-list-cycle/
https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

Extra space approach:- 
the question is asking if there is cylce or not.
if there is a cycle we will be stuck in traversal forever
so if we keep a hashmap of the nodes seen so far 
we can return true if we see a node twice
and if we reach a null node we have no cycle.

Constant extra space:-
there is this 2 pointer approach where one pointer travels at double the speed of the other pointer
and they would meet at a point if there is a cycle but note that the point at which they meet is not the point where the cycle begins
*/

class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        // your code here
        Node* h1 = head;
        Node* h2 = head?head->next:NULL;
        while(h2 && h2->next)
        {
            if(h2==h1)
                return 1;
            h1=h1->next;
            h2=h2->next->next;
        }
        return 0;
    }
};
