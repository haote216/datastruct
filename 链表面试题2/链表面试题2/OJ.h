//������м�ڵ�
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

//���������k�����
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

//�ϲ�������������
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

//�ָ�����С��xֵ����ǰ�벿�֣����ڵ���xֵ���ں�벿�֡�
ListNode* partition(ListNode* pHead, int x) {
	ListNode *lt = NULL;		// < x �ĵ�һ�����
	ListNode *lt_tail = NULL;	// < x �����һ�����
	ListNode *ge = NULL;		// >= x �ĵ�һ�����
	ListNode *ge_tail = NULL;	// >= x �����һ�����
	ListNode *cur = pHead;
	while (cur != NULL) {
		ListNode *next = cur->next;
		//cur->next = NULL;
		if (cur->val < x) {
			if (lt_tail == NULL) {
				// �� x С�����������ǿյ�
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

//ɾ���������ظ��Ľ��
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}
	ListNode *prev = NULL;	// ����ɾ���Ľ�㣬�� p1 ��ǰһ�����
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;
	ListNode *result = pHead;		// ���ڷ��صĵ�һ�����
	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// ɾ��
			ListNode *next;
			for (ListNode *node = p1; node != p2; node = next) {
				next = node->next;
				free(node);
			}
			// ����ƴ������
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				// 1 --> 1 --> 1 --> 2 --> NULL
				// �����
				result = p2;
			}
			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}
	return result;
}

//����
bool chkPalindrome(ListNode* A) {
	if (A == NULL)
		return false;
	else if (A->next == NULL)
		return true;
	//����ָ���ҳ��м�ڵ�
	ListNode* quick = A;
	ListNode* slow = A;
	while (quick != NULL&&quick->next != NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
	}
	//��ת
	ListNode* p = slow->next;
	ListNode* p1 = p->next;
	while (p != NULL)
	{
		p->next = slow;
		slow = p;
		p = p1;
		p1 = p1->next;
	}

	while (A != slow)
	{
		if ((A->val) != (slow->val))
		{
			return false;
		}
		else{
			if (A->next == slow)
			{
				return true;
			}
			A = A->next;
			slow = slow->next;
		}
	}
	return true;
}

bool chkPalindrome(ListNode* A) {
	ListNode * middle = middleNode(A);
	// middle ���м�ĵ�һ��
	// ��������middle ��next
	ListNode * r = reverseList(middle->next);

	ListNode *n1 = A, *n2 = r;
	while (n1 != NULL && n2 != NULL) {
		if (n1->val != n2->val) {
			return false;
		}

		n1 = n1->next;
		n2 = n2->next;
	}

	return true;
}

//�������������ҳ����ǵĵ�һ���������
int getLength(struct ListNode *head) {
	int n = 0;
	struct ListNode *cur = head;
	while (cur != NULL) {
		cur = cur->next;
		n++;
	}

	return n;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

	int lenA = getLength(headA);
	int lenB = getLength(headB);

	struct ListNode *longHead;
	struct ListNode *shortHead;
	int diff;

	if (lenA >= lenB) {
		longHead = headA;
		shortHead = headB;
		diff = lenA - lenB;
	}
	else {
		longHead = headB;
		shortHead = headA;
		diff = lenB - lenA;
	}

	for (int i = 0; i < diff; i++) {
		longHead = longHead->next;
	}

	while (longHead != shortHead) {
		longHead = longHead->next;
		shortHead = shortHead->next;
	}

	return longHead;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL)
		return NULL;
	if (headB == NULL)
		return NULL;
	struct ListNode*cur1 = headA;
	struct ListNode*cur2 = headB;
	struct ListNode*tmp = NULL;
	int n1 = 0;
	int n2 = 0;
	while (cur1)
	{
		if (cur1->next)
			cur1 = cur1->next;
		else
			break;
		n1++;
	}
	while (cur2)
	{
		if (cur2->next)
			cur2 = cur2->next;
		else
			break;
		n2++;
	}
	cur1 = headA;
	cur2 = headB;
	if (n1>n2)
	{
		int k = n1 - n2;
		while (k--)
		{
			cur1 = cur1->next;
		}
	}
	else
	{
		int k = n2 - n1;
		while (k--)
		{
			cur2 = cur2->next;
		}
	}
	while (cur1 && cur2)
	{
		if (cur1 == cur2)
		{
			tmp = cur1;
			break;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return tmp;
}

//����һ�������ж��������Ƿ��л�
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	struct ListNode*fast = head->next;
	struct ListNode*slow = head;
	while (fast != slow)
	{
		if (fast == NULL || fast->next == NULL)
		{
			return false;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return true;
}

//����һ��������������ʼ�뻷�ĵ�һ����㣬���û�л��ͷ��ؿ�
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL)
		return NULL;
	bool hasCycle = true;
	struct ListNode*fast = head->next;
	struct ListNode*slow = head;
	while (fast != slow)
	{
		if (fast == NULL || fast->next == NULL)
		{
			hasCycle = false;
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	if (hasCycle)
	{
		struct ListNode*node = head;
		while (slow != node)
		{
			slow = slow->next;
			node = node->next;
		}
		return node;
	}
	else
		return NULL;
}