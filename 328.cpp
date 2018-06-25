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
	ListNode * oddEvenList(ListNode* head) {
		if ((head == NULL) || (head->next == NULL))
		{
			return head;
		}
		ListNode *e, *p, *q;
		e = head->next;
		q = head;
		int t = 1;
		while (q->next != NULL)
		{
			p = q;
			q = q->next;
			p->next = q->next;
			t++;
		}
		if (t % 2 == 0)
		{
			p->next = e;
		}
		else
		{
			q->next = e;
		}
		return head;
	}
};