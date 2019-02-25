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

//链表的初始化
void SListInit(SList *plist);

//链表的销毁
void SListDestory(SList *plist);

//申请新结点
SListNode * SListBuyNode(SLTDataType value);

//头插
void SListPushFront(SList *plist,SLTDataType value);

//尾插
void SListPushBack(SList *plist, SLTDataType value);

//头删
void SListPopFront(SList *plist);

//尾删
void SListPopBack(SList *plist);

// pos 一定是链表中的一个有效结点
void SListInsertAfter(SListNode *pos, SLTDataType value);

void SListEraseAfter(SListNode *pos);

void SListInsertBefore(SList *plist, SListNode *pos, SLTDataType value);

// 改
void SListUpdate(SListNode *node, SLTDataType value);

// 查
// 去找到链表中遇到的第一个 value，如果没找到，返回 NULL
SListNode * SListFind(const SList *plist, SLTDataType value);

// 打印
void SListPrint(const SList *plist);