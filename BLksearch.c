#include<stdio.h>
#include<stdlib.h>

#define DATA_SIZE 30
#define BLOCK_SIZE 5
#define KeyType int


typedef struct
{
	KeyType key;
	int low, high;
}IdxType;


int s[] = {6,12,7,10,9,22,15,20,18,26,28,35,30,38,29,47,72,56,61,58};


//����������
void CreatIdx(int r[], IdxType idx[], int num_r, int blocknum)
{
	int i, j, k = 0;
	KeyType max;
	for (i = 0; i < num_r; i += blocknum)
	{
		max = r[i];
		for (j = i + 1; j < i + blocknum; j++)
		{
			if (r[j] > max)
			{
				max = r[j];
			}
		}
		idx[k].key = max;
		idx[k].low = i;
		
		if (i + blocknum < num_r - 1)
		{
			idx[k].high = i + blocknum-1;
		}
		else
		{
			idx[k].high = blocknum - 1;
		}
		k++;
	}
}

//�����ֿ�����㷨

int BlockSearch(int r[], IdxType idx[], int m, KeyType k)
{
	int low, high, mid, j, i =0, find = 0;
	
	//ͨ��˳��ıȽ����ҵ�k  �Ķ�Ӧ��Χ
	while (idx[i].key < k)
	{
		i++;
	}
	
	low = idx[i].low, high = idx[i].high;
	
	//��ʼ�ڴ˰���ڽ��в���
	while (low <= high && !find)
	{
		mid = low + (high - low) / 2;
		if (k < idx[mid].key)
			high = mid + 1;
		else if (k > idx[mid].key)
			low = mid + 1;
		else
		{
			high = mid - 1;
			find = 1;
		}
	}
	if (low < m)
	{
		i = idx[low].low;
		j = idx[low].low;
	}
	while (i < j && r[i] != k)
	{
		i++;
	}
	if (i > j)
		return -1;
	else
		return i;


}








int main()
{
	return 0;
}

