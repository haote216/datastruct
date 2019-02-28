//链表的中间节点
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode *fast = head;
	struct ListNode *low = head;
	while (fast != NULL && (fast->next != NULL))
	{
		fast = fast->next->next;
		low = low->next;
	}
	return low;
}

//输出倒数第k个结点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode *Fast = pListHead;
	ListNode *Slow = pListHead;
	while (k--)
	{
		if (NULL == Fast)
			return NULL;
		Fast = Fast->next;
	}
	while (Fast != NULL)
	{
		Fast = Fast->next;
		Slow = Slow->next;
	}
	return Slow;
}

//合并俩个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode *cur1 = l1;
	struct ListNode *cur2 = l2;
	struct ListNode *Newhead = NULL;
	struct ListNode *pTail = NULL;
	if (cur1->val < cur2->val)
	{
		Newhead = cur1;
		cur1 = cur1->next;
	}
	else
	{
		Newhead = cur2;
		cur2 = cur2->next;
	}
	pTail = Newhead;
	while (cur1 && cur2)
	{
		if (cur1->val < cur2->val)
		{
			pTail->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			pTail->next = cur2;
			cur2 = cur2->next;
		}
		pTail = pTail->next;
	}
	if (cur1)
		pTail->next = cur1;
	else
		pTail->next = cur2;
	return Newhead;
}

//分割链表，小于x值的在前半部分，大于等于x值的在后半部分。
ListNode* partition(ListNode* pHead, int x) {
	ListNode *lt = NULL;		// < x 的第一个结点
	ListNode *lt_tail = NULL;	// < x 的最后一个结点
	ListNode *ge = NULL;		// >= x 的第一个结点
	ListNode *ge_tail = NULL;	// >= x 的最后一个结点
	ListNode *cur = pHead;
	while (cur != NULL) {
		ListNode *next = cur->next;
		//cur->next = NULL;
		if (cur->val < x) {
			if (lt_tail == NULL) {
				// 比 x 小的链表现在是空的
				lt = lt_tail = cur;
			}
			else {
				lt_tail->next = cur;
				lt_tail = cur;
			}
		}
		else {
			if (ge_tail == NULL) {
				ge = ge_tail = cur;
			}
			else {
				ge_tail->next = cur;
				ge_tail = cur;
			}
		}
		cur = next;
	}
	if (ge_tail != NULL) {
		ge_tail->next = NULL;
	}

	if (lt_tail == NULL) {
		return ge;
	}
	else {
		lt_tail->next = ge;
		return lt;
	}
}