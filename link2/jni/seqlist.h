#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef void SeqList;
typedef void SeqListNode;

SeqList * SeqList_create(int capacity);

void SeqList_Destory(SeqList* list);

void SeqList_Ceear(SeqList * list);

int SeqList_Length(SeqList * list);

int SeqList_Capacity(SeqList * list);

int SeqList_Insert(SeqList* list,SeqListNode * node,int pos);

SeqListNode * SeqList_Get(SeqList * list,int pos);

SeqListNode * SeqList_Delete(SeqList * list,int pos);
#endif // __MY_SEQLIST_H__
