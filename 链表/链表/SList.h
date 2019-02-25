#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;

typedef struct SListNode{
	SLTDataType _data;
	struct SListNode * _next;
}SListNode;

typedef struct SList{
	SListNode * _head;
}SList;

//����ĳ�ʼ��
void SListInit(SList *plist);

//���������
void SListDestory(SList *plist);

//�����½��
SListNode * SListBuyNode(SLTDataType value);

//ͷ��
void SListPushFront(SList *plist,SLTDataType value);

//β��
void SListPushBack(SList *plist, SLTDataType value);

//ͷɾ
void SListPopFront(SList *plist);

//βɾ
void SListPopBack(SList *plist);

// pos һ���������е�һ����Ч���
void SListInsertAfter(SListNode *pos, SLTDataType value);

void SListEraseAfter(SListNode *pos);

void SListInsertBefore(SList *plist, SListNode *pos, SLTDataType value);

// ��
void SListUpdate(SListNode *node, SLTDataType value);

// ��
// ȥ�ҵ������������ĵ�һ�� value�����û�ҵ������� NULL
SListNode * SListFind(const SList *plist, SLTDataType value);

// ��ӡ
void SListPrint(const SList *plist);