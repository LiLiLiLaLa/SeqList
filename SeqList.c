#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}

void PushBack(pSeqList pSeq, DataType d)
{
	//1.assert
	assert(pSeq != NULL);
	//2.�ж���
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷�����Ԫ��\n");
		return;
	}
	//3.β��
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;//�������sz,�ͷ��ʲ����²����Ԫ��
}

void PrintSeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��");
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d\t", pSeq->data[i]);
	}
	printf("\n");
}

void PopBackSeqList(pSeqList pSeq)
{
	//1.assert
	assert(pSeq != NULL);
	//2.�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ�գ��޷�����ɾ������\n");
		return;
	}
	//3.βɾ
	pSeq->sz--;
}

void PushFront(pSeqList pSeq, DataType d)
{
	//assert
	assert(pSeq != NULL);
	//�ж���
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷�����\n");
		return;
	}
	int i = pSeq->sz;
	for (i; i > 0; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[0] = d;
	pSeq->sz++;
}

void PopFront(pSeqList pSeq)
{
	//assert
	assert(pSeq != NULL);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ�գ��޷�����ɾ������\n");
		return;
	}
	//��ǰŲ
	int i = 0;
	for (i; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int Find(pSeqList pSeq, DataType d)
{
	int i = 0;
	//����
	assert(pSeq != NULL);
	//����
	for (i; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

void Insert(pSeqList pSeq, int pos, DataType d)
{
	//����
	//pos��С����
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	//����
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷�����");
		return;
	}
	//����
	int i = pSeq->sz - 1;
	for (i; i >= pos; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}

void Erase(pSeqList pSeq, int pos)
{
	//����
	//pos��С����
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ�գ��޷�����ɾ������\n");
		return;
	}
	//ɾ������
	int i = pos;
	for (i; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void Remove(pSeqList pSeq, DataType d)
{
	int i = 0;
	int pos = 0;
	//����
	assert(pSeq != NULL);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	if((pos=Find(pSeq,d))!=-1)
	{
		Erase(pSeq,pos);
	}
#if 0
	//����
	for (i; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			break;
		}
	}
	//�ҵ���û�ҵ�
	if (i == pSeq->sz)
	{
		printf("Ҫɾ����Ԫ�ز�����\n");
		return;
	}
	//ɾ������
	for (i; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
#endif
}


void RemoveAll(pSeqList pSeq, DataType d)
{
	int i = 0;
	int count = 0;
	//����
	assert(pSeq != NULL);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
#if 0
	for (i; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			int j = 0;
			for (j = i; j < pSeq->sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->sz--;
			--i;//��ֹ��ɾ��Ԫ������
		}
	}
#endif
#if 0
	DataType* tmp = (DataType*)malloc(sizeof(DataType)* pSeq->sz);
	for (i; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d)
		{
			tmp[count++] = pSeq->data[i];
		}
	}
	memcpy(pSeq->data, tmp, count*sizeof(DataType));
	pSeq->sz = count;
	free(tmp);
	tmp = NULL;
#endif
	for (i; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->sz = count;
}

int Size(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

int Empty(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

void Swap(DataType* p1, DataType* p2)
{
	DataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void BubbleSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pSeq != NULL);
	for (i=0; i < pSeq->sz - 1; i++)
	{
		for (j=0; j < pSeq->sz - 1 - i; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

void SelectSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	for (i; i < pSeq->sz - i; i++)
	{
		int max = 0;
		for (j = 1; j < pSeq->sz - i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}//max���һ�������Ԫ�ص��±�
		if (max != pSeq->sz - 1 - i)//max���Ǹ��˲���Ƚϵ����һ��Ԫ���±�
		{
			Swap(&(pSeq->data[max]), &(pSeq->data[pSeq->sz - 1 - i]));
		}//��max�±�ָ���Ԫ�غ͸��˲���Ƚϵ����һ��Ԫ�ؽ���λ��
	}
}

void SelectSort_1(pSeqList pSeq)
{
	int start = 0;
	int end = pSeq->sz - 1;
	assert(pSeq != NULL);
	while (start < end)
	{
		int i = 0;
		int max = start;
		int min = start;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[i] > pSeq->data[max])
			{
				max = i;
			}
			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}//max���һ�������Ԫ�ص��±�,min���һ������СԪ�ص��±�
		if (min != start)
		{
			Swap(&(pSeq->data[start]), &(pSeq->data[min]));
		}
		if (max == start)
		{
			max = min;
		}
		if (max != end)
		{
			Swap(&(pSeq->data[max]), &(pSeq->data[end]));
		}
		start++;
		end--;
	}
}

int BinarySearch(pSeqList pSeq, DataType d)
{
	int left = 0;
	int right = pSeq->sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] > d)
		{
			right = mid - 1;
		}
		else if (pSeq->data[mid] < d)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int BinarySearch_1(pSeqList pSeq, int left, int right, DataType d)
{
	int mid = 0;
	if (left > right)
	{
		return -1;
	}
	mid = left + (right - left) / 2;
	if (pSeq->data[mid] > d)
	{
		return BinarySearch_1(pSeq, left, mid - 1, d);
	}
	else if (pSeq->data[mid] < d)
	{
		return BinarySearch_1(pSeq, mid + 1, right, d);
	}
	else
		return mid;
}