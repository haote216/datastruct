#include"SeqList.h"
void test()
{
	SeqList seqlist;
	SeqListInit(&seqlist,5);
	SeqListPushFornt(&seqlist, 2);
	SeqListPushFornt(&seqlist, 3);
	SeqListPushFornt(&seqlist, 4);
	SeqListPushFornt(&seqlist, 5);
	SeqListPushBack(&seqlist, 6);
	SeqListPushBack(&seqlist, 7);
	SeqListPrint(&seqlist);
}
int main()
{
	test();
	system("pause");
	return 0;
}