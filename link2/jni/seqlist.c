#include "seqlist.h"

#include <android/log.h>
typedef struct _tag_SeqList {
	int capacity;
	int length;
	unsigned int *node;
} TSeqList;
//SeqList * SeqList_create(int capacity){
//	TSeqList  * ret = NULL;
//	ret = (TSeqList *) malloc(sizeof(TSeqList));
//	if(ret ==NULL){
//		return NULL;
//	}
//	ret->capacity = capacity;
//	ret->node = (unsigned int *)malloc(sizeof(int)*capacity);
//	if(ret->node == NULL){
//		return NULL;
//	}
//	ret->length = 0;
//	return ret;
//}
//第二种方式
//一次性清空内存
void * SeqList_create(int capacity) {
	TSeqList * ret = NULL;
	if (capacity < 0) {
		return NULL;
	}
	ret = (TSeqList *) malloc(
			sizeof(TSeqList) + sizeof(unsigned int ) * capacity);
	if (ret == NULL) {
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)(ret + 1);
	ret->length = 0;
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "creae: %d\n",ret->length);
	return ret;
}
void SeqList_Destory(SeqList* list) {
	if (list == NULL) {
		return;
	}
	free(list);
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "正常销毁 \n");
	return ;
}

void SeqList_Ceear(SeqList * list) {
	TSeqList * tlist = list;
	if (list == NULL) {
		return;
	}
	tlist->length = 0;
	return;
}

int SeqList_Length(SeqList * list) {
	TSeqList * tlist = list;
	if (list == NULL) {
		return -1;
	}
	return tlist->length;
}

int SeqList_Capacity(SeqList * list) {
	TSeqList *tlist = list;
	if (list == NULL) {
		return -1;
	}
	return tlist->capacity;
}

//int SeqList_Insert(SeqList* list, SeqListNode * node, int pos) {
//		int i = 0;
//		TSeqList *tlist = list;
//		if (list == NULL || node== NULL )
//		{
//			return -1;
//		}
//		if (pos<0 || pos>=tlist->capacity )
//		{
//			return -2;
//		}
//		//判断是否已经man
//		if (tlist->length >= tlist->capacity)
//		{
//			return -3;
//		}
//		//容错
//		if (pos > tlist->length)
//		{
//			pos = tlist->length;
//		}
//
//		//插入算法 有两步
//		//从插入的位置 后移元素
//		//注意length能表示出现在数组的最后元素位置
//		//最后元素的下标为 tlist->node[length-1];
//		for (i=tlist->length; i>pos; i--)
//		{
//			tlist->node[i] = tlist->node[i-1];
//		}
//		//在pos位置插入元素
//		tlist->node[pos] = (unsigned int)node; //20140514这个地方不能加 (unsigned int *)
//		//如果你加*，说明你对	unsigned int *node ; // unsigned int nodeAarry[100]还没有理解
//		tlist->length ++;
//		__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert: %d\n",tlist->length);
//		return 0;
//}
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i = 0;
	TSeqList *tlist = list;
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert1: %d\n",tlist->length);
	if (list == NULL || node== NULL )
	{
		return -1;
	}
	if (pos<0 || pos>=tlist->capacity )
	{
		return -2;
	}
	//判断是否已经man
	if (tlist->length >= tlist->capacity)
	{
		return -3;
	}
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert2: %d\n",tlist->length);
	//容错
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert3: %d\n",tlist->length);
	//插入算法 有两步
	//从插入的位置 后移元素
	//注意length能表示出现在数组的最后元素位置
	//最后元素的下标为 tlist->node[length-1];
	for (i=tlist->length; i>pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert4: %d\n",tlist->length);
	//在pos位置插入元素
	tlist->node[pos] = (unsigned int)node; //20140514这个地方不能加 (unsigned int *)
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert5: %d\n",tlist->length);
	tlist->length +=1;
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insert: %d\n",tlist->length);
	return 0;
}


SeqListNode * SeqList_Get(SeqList * list, int pos) {
    	int i = 0;
		TSeqList *tlist = list;
		//if (list== NULL || pos<0 || pos>=tlist->length)
		if (list== NULL || pos<0 || pos>tlist->length)
		{
			return NULL;
		}
		return (SeqListNode*)tlist->node[pos];
}
SeqListNode * SeqList_Delete(SeqList * list, int pos) {
		int i = 0;
		TSeqList *tlist = list;
		SeqListNode* ret = NULL;
		if (list == NULL || pos<0 || pos>tlist->length)
		{
			return NULL;
		}
		//缓存要删除的结点
		ret = (SeqListNode*)tlist->node[pos];
		//对链表进行移动
		for (i=pos+1; i<tlist->length; i++)
		{
			tlist->node[i-1] = tlist->node[i];
	 	}
		tlist->length --;
		return ret;
}

