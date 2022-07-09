/*
Links:
https://leetcode.com/problems/add-two-numbers/
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

this is just a simulation questions
thats what i like to call them
problems which wants us to emulate what we have tried in real life or something like that.
this is jus implementing of digit by digit addition via code.

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry=0) {
        if(!l1 && !l2 )
        {
            if(carry)
                return new ListNode(carry);
            return l1;
        }
        if(l1 && l2)
        {
            l1->val += l2->val+carry;
            carry = l1->val/10;
            l1->val = l1->val%10;
            l1->next  = addTwoNumbers(l1->next,l2->next,carry);
            return l1;
        }
        if(l1)
        {
            l1->val += carry;
            carry = l1->val/10;
            l1->val = l1->val%10;
            l1->next  = addTwoNumbers(l1->next,0,carry);
            return l1;
        }
        l2->val += carry;
        carry = l2->val/10;
        l2->val = l2->val%10;
        l2->next  = addTwoNumbers(l2->next,0,carry);
        return l2;
        
    }
};
