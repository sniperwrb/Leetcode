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
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p, *q, *x, *y, *z;
		y = l1; z = l2;
		int h, j;
		j = 0;
		q = new ListNode(0);
		p = q; x = q;
		while ((y != NULL) && (z != NULL))
		{
			h = y->val + z->val + j;
			j = h / 10;
			h %= 10;
			q = new ListNode(h);
			x->next = q;
			x = q;
			y = y->next;
			z = z->next;
		}
		//now at least one shall be null!
		if (y == NULL) //get z
		{
			y = z;
		}
		while (y != NULL)
		{
			h = y->val + j;
			j = h / 10;
			h %= 10;
			q = new ListNode(h);
			x->next = q;
			x = q;
			y = y->next;
		}
		if (j>0)
		{
			q = new ListNode(j);
			x->next = q;
		}
		p = p->next;
		return p;
	}
};