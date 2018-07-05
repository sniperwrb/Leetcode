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
	ListNode * sortList(ListNode* head) {
		vector<int> a;
		int l;
		ListNode *p;
		p = head;
		l = 0;
		while (p != NULL)
		{
			a.push_back(p->val);
			l++;
			p = p->next;
		}
		sort(a.begin(), a.end());
		p = head;
		int i;
		for (i = 0; i<l; i++)
		{
			p->val = a[i];
			p = p->next;
		}
		return head;
	}
};