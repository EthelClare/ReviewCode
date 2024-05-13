#include<stdio.h>
#include<stdlib.h>


//�����Ǽ�������㷨����ʵ��



//��������
void SelectionSort(int arr[], int n)
{
	int i, j, min_index;
	for (i = 0; i < n; i++)
	{
		min_index = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}

	}
}

//��������

void Selection_ascending(int arr[], int n)
{
	int i, j, max_index;

	for (i = 0; i < n; i++)
	{
		max_index = i;
		
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[max_index])
			{
				max_index = j;
			}
		}
		if (max_index != i)
		{
			int temp = arr[max_index];
			arr[max_index] = arr[i];
			arr[i] = temp;
		}

	}
}





int main()
{
	int arr[] = { 64, 25, 12, 22, 11, 90, 80, 75, 30, 5 }; // ������������
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("ԭʼ����: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	SelectionSort(arr, n);

	printf("����������: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	Selection_ascending(arr, n);

	printf("����������: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}