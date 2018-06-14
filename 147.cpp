ListNode* insertionSortList(ListNode* head) {
	vector<int> v;
	ListNode *p;
	int i;
	p = head;
	while (p != NULL)
	{
		v.push_back(p->val);
		p = p->next;
	}
	sort(v.begin(), v.end());
	p = head;
	i = 0;
	while (p != NULL)
	{
		p->val = v[i];
		i++;
		p = p->next;
	}
	return head;
}