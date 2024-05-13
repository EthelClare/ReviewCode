#include<stdio.h>
#include<stdlib.h>

//大根堆

void HeadAdjust(int arr[], int k, int len)
{
	//数组第一个结构用来储存当前根节点的值
	int temp = arr[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && arr[i] < arr[i + 1])
		{
			i++;
		}
		if (temp >= arr[i])
			break;
		else
		{
			arr[k] = arr[i];
			k = i;
		}
	}
	arr[k] = temp;
}

void BuildMaxHeap(int arr[], int len)
{
	for (int i = len / 2; i > 0; i--)
	{
		HeadAdjust(arr, i, len);
	}
}

//最小堆
void HeadAdjust_Min(int arr[], int k, int len)
{
	int temp = arr[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i<len && arr[i] > arr[i + 1])
		{
			i++;
		}
		if (temp <= arr[i])
		{
			break;
		}
		else
		{
			arr[k] = arr[i]; 
			k = i;
		}
	}
	arr[k] = temp;
}

void BuildMinHeap(int arr[], int len)
{
	for (int i = len / 2; i > 0; i--)
	{
		HeadAdjust_Min(arr, i, len);
	}
}



void test01()
{
	int arr[] = { 0 ,99, 77 , 66,11,22,33,55,34,76,23 };


	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	BuildMaxHeap(arr + 1, len);
	for (int i = 1; i <= len; i++)
	{
		printf(" %d ", arr[i]);
		
	}
	printf("\n");
	
}

int main()
{

	test01();
	
	return 0;
}