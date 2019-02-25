#include"SList.h"

void SListInit(SList *plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	SListNode *next = NULL;
	while (cur != NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}
SListNode * SListBuyNode(SLTDataType value)
{
	SListNode * node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->_data = value;
	node->_next = NULL;
	return node;
}
void SListPushFront(SList *plist, SLTDataType value)
{
	assert(plist);
	SListNode *node = SListBuyNode(value);
	assert(node);
	node->_next = plist->_head;
	plist->_head = node;
}
void SListPushBack(SList *plist, SLTDataType value)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		SListPushFront(plist, value);
		return;
	}
	SListNode * cur = plist->_head;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	SListNode *node = SListBuyNode(value);
	cur->_next= node;
	node->_next = NULL;
}
void SListPopFront(SList *plist)
{
	assert(plist);
	assert(plist->_head);
	SListNode *old = plist->_head;
	plist->_head = plist->_head->_next;
	free(old);
}
void SListPopBack(SList *plist)
{
	assert(plist);
	assert(plist->_head);
	if (plist->_head->_next == NULL)
	{
		SListPopFront(plist);
		return;
	}
		
	SListNode *cur = plist->_head;
	while (cur->_next->_next)
	{
		cur = cur->_next;
	}
	free(cur->_next);
	cur->_next = NULL;
}
void SListInsertAfter(SListNode *pos, SLTDataType value)
{
	SListNode *node = SListBuyNode(value);
	node->_next = pos->_next;
	pos->_next = node;
}
void SListEraseAfter(SListNode *pos)
{
	SListNode *node = pos->_next;
	pos->_next = node->_next;
	free(node);
}
void SListInsertBefore(SList *plist, SListNode *pos, SLTDataType value)
{
	SListNode *cur = plist->_head;
	while (cur->_next != pos)
	{
		cur = cur->_next;
	}
	SListNode *node = SListBuyNode(value);
	cur->_next = node;
	node->_next = pos;
}
void SListUpdate(SListNode *node, SLTDataType value)
{
	node->_data = value;
}
SListNode * SListFind(const SList *plist, SLTDataType value)
{
	for (SListNode *cur = plist->_head; cur != NULL; cur = cur->_next) {
		if (cur->_data == value) {
			return cur;
		}
	}

	return NULL;
}
void SListPrint(const SList *plist)
{
	for (SListNode *cur = plist->_head; cur != NULL; cur = cur->_next) {
		printf("%d --> ", cur->_data);
	}
	printf("NULL\n");
}