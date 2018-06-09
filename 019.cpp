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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i,l,x;
        ListNode *p;
        p=head;
        l=0;
        while (p!=NULL)
        {
            l=l+1;
            p=p->next;
        }
        x=l-n+1;
        if (x==1)
        {
            head=head->next;
        }
        if (x>1)
        {
            p=head;
            for (i=2;i<x;i++)
            {
                p=p->next;
            }
            p->next=p->next->next;
        }
        return head;
    }
};