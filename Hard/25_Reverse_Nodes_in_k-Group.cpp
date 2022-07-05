/*
Links : 
https://leetcode.com/problems/reverse-nodes-in-k-group/
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

if this question was regarding an array it would have been so easy to do so
u can just call  a reverse function for every group of k size and then reverse them in inplace

we can do that store all the nodes in a vector  then reverse themaccording to  question  and link them
while doing a linear scan
but that would make  the linked list lose its meaning.

so what we can do is when a function is called for a node we can just traverse through k elements and disconnect the node from its next and call samefunction on the next of it
and put the result of that sub call at the next of head after reversing the current k list.

Note: difference between the leet and gfg question is that when the length is not divisible by k then the last length%k sized group is not reversed 
*/
class Solution {
public:
    ListNode* rev(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* mid = head;
        int count=1;
        while(mid->next && count<k)
        {
            mid=mid->next;
            count++;
        }
        if(count!=k)
            return head;
        ListNode* next = mid->next;
        mid->next=NULL;
        mid = rev(head);
        head->next = reverseKGroup(next,k);
        return mid;
    }
};
