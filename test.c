#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void TestPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBackSeqList(&seq);
	PrintSeqList(&seq);
	PopBackSeqList(&seq);
	PrintSeqList(&seq);
	PopBackSeqList(&seq);
	PrintSeqList(&seq);
	PopBackSeqList(&seq);
	PrintSeqList(&seq);
	PopBackSeqList(&seq);
	PrintSeqList(&seq);
}

void TestPushFront()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);//4,3,2,1
	PopFront(&seq);
	PrintSeqList(&seq);
}

void TestFind()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);//4,3,2,1
	pos = Find(&seq, 13);//1
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是%d\n", pos);
	}
}

void TestInsert()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);//4,3,2,1
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		//指定位置前面插入指定元素
		Insert(&seq, pos, 5);
	}
	PrintSeqList(&seq);//4,5,3,2,1
}

void TestErase()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);//4,3,2,1
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		//删除指定位置元素
		Erase(&seq, pos);
	}
	PrintSeqList(&seq);//4,5,3,2,1
}

void TestRemove()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1); 
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	Remove(&seq, 2);
	PrintSeqList(&seq);//1,2,4,5,2,3
}

void TestRemoveAll()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 1);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 1);
	PushBack(&seq, 3);
	if (Empty(&seq))
		printf("顺序表元素个数为：%d\n", Size(&seq));//返回顺序表大小（元素个数）
	PrintSeqList(&seq);
	RemoveAll(&seq, 1);
	PrintSeqList(&seq);
}

void TestBubbleSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 0);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 5);
	PushFront(&seq, 6);
	PushFront(&seq, 7);
	PushFront(&seq, 8);
	PushFront(&seq, 9);
	PrintSeqList(&seq);
	BubbleSort(&seq);
	PrintSeqList(&seq);
}

void TestSelectSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 0);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 5);
	PushFront(&seq, 6);
	PushFront(&seq, 7);
	PushFront(&seq, 8);
	PushFront(&seq, 9);
	PrintSeqList(&seq);
	//SelectSort(&seq);
	SelectSort_1(&seq);
	PrintSeqList(&seq);
}

void TestBinarySearch()
{
	SeqList seq;
	int i = 0;
	int pos = 0;
	InitSeqList(&seq);
	PushFront(&seq, 10);
	PushFront(&seq, 9);
	PushFront(&seq, 8);
	PushFront(&seq, 7);
	PushFront(&seq, 6);
	PushFront(&seq, 5);
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	PrintSeqList(&seq);
	//pos = BinarySearch(&seq, 7);
	pos = BinarySearch_1(&seq, 0,seq.sz-1, -7);
	if (pos != -1)
	{
		printf("下标是：%d", pos);
	}
	else
	{
		printf("没找到该元素\n");
	}
}

int main()
{
	//TestPushBack();
	//TestPushFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestRemoveAll();
	//TestBubbleSort();
	//TestSelectSort();
	TestBinarySearch();
	system("pause");
	return 0;
}
