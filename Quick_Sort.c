#include<stdio.h>
#include<stdlib.h>

int Partition(int A[], int low, int high)
{
	int pivotpos = A[low];
	while (low < high)
	{
		while (A[high] >= pivotpos && high > low)
			high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivotpos)
			low++;
		A[high] = A[low];
	}
	A[low] = pivotpos;
	return low;
}


void QuickSort(int A[] ,int low, int high )
{
	if (low < high)
	{
		int pivotpos = Partition(A, low, high);
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}


int main()
{
	// 示例数组，用于测试排序功能
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Before sorting: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	QuickSort(arr, 0, n - 1);

	printf("After sorting: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}