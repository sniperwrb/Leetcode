/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *r;
        ListNode *a;
        ListNode *b;
        ListNode *c;
        ListNode *d;
        r=head;
        b=r;
        if (b==NULL)
        {
            return r;
        }
        c=b->next;
        if (c==NULL)
        {
            return r;
        }
        r=c;
        while (1==1)
        {
            d=c->next;
            c->next=b;
            b->next=d;
            a=b;
            b=d; 
            if (b==NULL)
            {
                return r;
            }
            c=b->next;
            if (c==NULL)
            {
                return r;
            }
            a->next=c;
        }
    }
};