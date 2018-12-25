#include"SeqList.h"
void SeqListInit(SeqList *seqlist, int capacity)
{
	assert(seqlist);
	seqlist->array = (SDataType *)malloc(sizeof(SDataType)*capacity);
	seqlist->capacity = capacity;
	seqlist->size = 0;
}
void SeqListDestory(SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	free(seqlist->array);
	seqlist->array = NULL;
	seqlist->capacity = 0;
	seqlist->size = 0;
}
static void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size < seqlist->capacity)
		return;
	int capacity = 2 * seqlist->capacity;
	SDataType * array = (SDataType *)malloc(sizeof(SDataType)*capacity);
	assert(array);
	for (int i = 0; i < seqlist->size; i++)
	{
		array[i] = seqlist->array[i];
	}
	free(seqlist->array);
	seqlist->array = array;
	seqlist->capacity = capacity;
}
void SeqListPushFornt(SeqList *seqlist, SDataType value)
{
	assert(seqlist);
	assert(seqlist->array);
	CheckCapacity(seqlist);
	for (int i = seqlist->size; i > 0; i--)
	{
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}
void SeqListPushBack(SeqList *seqlist, SDataType value)
{
	assert(seqlist);
	assert(seqlist->array);
	CheckCapacity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}
void SeqListInsert(SeqList *seqlist, int pos, SDataType value)
{
	assert(seqlist);
	assert(seqlist->array);
	assert(pos <= seqlist->size && pos >= 0);
	CheckCapacity(seqlist);
	for (int i = seqlist->size; i > pos; i++)
	{
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}
void SeqListPopFornt(SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	assert(seqlist->size > 0);
	for (int i = 1; i < seqlist->size; i++)
	{
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}
void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	assert(seqlist->size > 0);
	seqlist->size--;
}
void SeqListErase(SeqList *seqlist,int pos)
{
	assert(seqlist);
	assert(seqlist->array);
	assert(seqlist->size > 0);
	assert(pos <= seqlist->size && pos >= 0);
	for (int i = seqlist->size; i > pos; i--)
	{
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}
int SeqListFind(const SeqList *seqlist, SDataType value)
{
	assert(seqlist);
	assert(seqlist->array);
	for (int i = 0; i < seqlist->size; i++)
	{
		if (seqlist->array[i] == value)
			return i;
	}
	return 0;
}
void SeqListModify(SeqList *seqlist,int pos, SDataType value)
{
	assert(seqlist);
	assert(seqlist->array);
	assert(pos >= 0 && pos <= seqlist->size);
	seqlist->array[pos] = value;
}
void SeqListRemove(SeqList *seqlist, SDataType value)
{
	assert(seqlist);
	assert(seqlist->array);
	for (int i = 0; i < seqlist->size; i++)
	{
		if (seqlist->array[i] == value)
		{
			for (int j = seqlist->size; j >i; j--)
			{
				seqlist->array[j] = seqlist->array[j];
				seqlist->size--;
				break;
			}
			break;
				
		}
	}
}
bool SeqListEmpty(const SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	return seqlist->size == 0;
}
int SeqListSize(const SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	return seqlist->size;
}
void SeqListPrint(const SeqList *seqlist)
{
	assert(seqlist);
	assert(seqlist->array);
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d ", seqlist->array[i]);
	}
}