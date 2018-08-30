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
	DataType data[MAX];//���������ݵ�����
	int sz;//��ǰ������ݸ���
}SeqList, *pSeqList;

void InitSeqList(pSeqList pSeq);//��ʼ��˳���
void PushBack(pSeqList pSeq, DataType d);//β��
void PrintSeqList(pSeqList pSeq);//��ӡ˳���
void PopBackSeqList(pSeqList pSeq);//βɾ
void PushFront(pSeqList pSeq, DataType d);//ͷ��
void PopFront(pSeqList pSeq);//ͷɾ
int Find(pSeqList pSeq, DataType d);//����ָ��Ԫ��
void Insert(pSeqList pSeq, int pos, DataType d);//ָ��λ��ǰ�����ָ��Ԫ��
void Erase(pSeqList pSeq, int pos);//ɾ��ָ��λ��Ԫ��
void Remove(pSeqList pSeq, DataType d);//ɾ��˳����г��ֵĵ�һ��ָ��Ԫ��
void RemoveAll (pSeqList pSeq, DataType d);//ɾ��˳���������ָ��Ԫ��
int Size(pSeqList pSeq);//����˳���Ԫ�ظ���
int Empty(pSeqList pSeq);//�ж�˳����Ƿ�Ϊ��
void BubbleSort(pSeqList pSeq);//ð������
void SelectSort(pSeqList pSeq);//ѡ������
void SelectSort_1(pSeqList pSeq);//ѡ�������Ż�
int BinarySearch(pSeqList pSeq, DataType d);//���ֲ���
int BinarySearch_1(pSeqList pSeq, int left, int right, DataType d);//�ݹ�ʵ�ֶ��ֲ���

#endif//__SEQLIST_H__

