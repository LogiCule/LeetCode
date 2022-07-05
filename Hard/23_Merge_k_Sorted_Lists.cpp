/*
First Approach

We can apply merge operation on each list cummulatively.
Take ans = null as ur intial ans;
then we traverse each list and merge it with ans.
i.e merge(ans,curentList)

Now  we have a correct solution but the complexity is a little bit at its capacity
it is gonna  be (number of lists) * (cumulative  length)

we need to reduce the number of merge operations here.
so we can use the mergeSort logic  to  reduce the number of merge  operations  fromn to log n.
*/
class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val<l2->val)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        l2->next = merge(l2->next,l1);
            return l2;
    }
    ListNode* mergeK(vector<ListNode*>& lists,int i,int j)
    {
        if(i>j)
            return NULL;
        if(i==j)
            return lists[i];
        if(j-i==1)
            return merge(lists[i],lists[j]);
        int mid = (i+j)/2;
        ListNode* left = mergeK(lists,i,mid);
        ListNode* right = mergeK(lists,mid+1,j);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeK(lists,0,lists.size()-1);
    }
};
