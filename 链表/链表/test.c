#include"SList.h"

void TestSList1() {
	SList plist;
	SListInit(&plist);
	assert(plist._head == NULL);

	SListPushBack(&plist, 11);
	SListPushBack(&plist, 12);
	SListPushBack(&plist, 13);

	SListNode *n12 = SListFind(&plist, 12);
	assert(n12 != NULL);

	SListPrint(&plist);
	// 11 12 13

	SListInsertAfter(n12, 103);


	SListPrint(&plist);
	// 11 12 103 13

	SListEraseAfter(n12);

	SListPrint(&plist);
	// 11 12 13

	SListInsertBefore(&plist, n12, 101);

	SListPrint(&plist);
	// 11 101 12 13

	printf("´ó³É¹¦\n");
}
int main()
{
	TestSList1();
	system("pause");
	return 0;
}