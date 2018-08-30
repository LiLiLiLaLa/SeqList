#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


#define MAX 100
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];//定义存放数据的数组
	int sz;//当前存放数据个数
}SeqList, *pSeqList;

void InitSeqList(pSeqList pSeq);//初始化顺序表
void PushBack(pSeqList pSeq, DataType d);//尾插
void PrintSeqList(pSeqList pSeq);//打印顺序表
void PopBackSeqList(pSeqList pSeq);//尾删
void PushFront(pSeqList pSeq, DataType d);//头插
void PopFront(pSeqList pSeq);//头删
int Find(pSeqList pSeq, DataType d);//查找指定元素
void Insert(pSeqList pSeq, int pos, DataType d);//指定位置前面插入指定元素
void Erase(pSeqList pSeq, int pos);//删除指定位置元素
void Remove(pSeqList pSeq, DataType d);//删除顺序表中出现的第一个指定元素
void RemoveAll (pSeqList pSeq, DataType d);//删除顺序表中所有指定元素
int Size(pSeqList pSeq);//返回顺序表元素个数
int Empty(pSeqList pSeq);//判断顺序表是否为空
void BubbleSort(pSeqList pSeq);//冒泡排序
void SelectSort(pSeqList pSeq);//选择排序
void SelectSort_1(pSeqList pSeq);//选择排序优化
int BinarySearch(pSeqList pSeq, DataType d);//二分查找
int BinarySearch_1(pSeqList pSeq, int left, int right, DataType d);//递归实现二分查找

#endif//__SEQLIST_H__

