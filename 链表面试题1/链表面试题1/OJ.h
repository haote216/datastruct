// 删除所有val值
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *prev = head;
	struct ListNode *cur = head->next;

	while (cur != NULL) {
		if (cur->val == val) {
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}

	if (head->val == val) {
		struct ListNode *newHead = head->next;
		free(head);
		return newHead;
	}
	else {
		return head;
	}
}

// 反转单链表 第一种方式
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *ret = NULL;

	while (head != NULL) {
		// 头删
		struct ListNode *node = head;
		head = head->next;

		// 头插 node -> ret
		node->next = ret;
		ret = node;
	}

	return ret;
}

// 反转单链表 第二种方式
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return head;
	}

	struct ListNode *prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = head->next;

	while (cur != NULL) {
		cur->next = prev;

		prev = cur;
		cur = next;
		if (next != NULL) {
			next = next->next;
		}
	}

	return prev;
}