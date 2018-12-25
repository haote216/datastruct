#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SDataType;
typedef struct SeqList{
	SDataType *array;
	int size;
	int capacity;
}SeqList;
void SeqListInit(SeqList *seqlist,int capacity);
void SeqListDestory(SeqList *seqlist);
void CheckCapacity(SeqList *seqlist);
void SeqListPushFornt(SeqList *seqlist,SDataType value);
void SeqListPushBack(SeqList *seqlsit,SDataType value);
void SeqListInsert(SeqList *seqlsit,int pos,SDataType value);
void SeqListPopFornt(SeqList *seqlist);
void SeqListPopBack(SeqList *seqlsit);
void SeqListErase(SeqList *seqlist,int pos);
int SeqListFind(const SeqList *seqlist,SDataType value);
void SeqListModify(SeqList *seqlist,int pos,SDataType value);
void SeqListRemove(SeqList *seqlist,SDataType value);
bool SeqListEmpty(const SeqList *seqlist);
int SeqListSize(const SeqList *seqlist);
void SeqListPrint(const SeqList *seqlist);

