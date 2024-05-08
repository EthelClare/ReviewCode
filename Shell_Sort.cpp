#include<stdio.h>
#include<stdlib.h>

//ϣ�������ǶԲ�ֵ����Ľ�һ���Ż�

////n����������Ԫ�ظ���
//void ShellSort(int arr[] ,int n)
//{
//	int gap, i, j;
//	//��ʼ����
//	for (gap = n / 2; gap >= 1; gap /= 2)
//	{
//		for (i = gap + 1; i <= n; i++)
//		{
//			if (arr[i] < arr[i - gap])
//			{
//				arr[0] = arr[i];
//				for (j = i - gap; j > 0 && arr[0] < arr[j]; j -= gap)
//				{
//					arr[j + gap] = arr[j];
//				}
//				arr[j + gap] = arr[0];
//			}
//		}
//	}
//
//
//}
//����㴫�������ֱ��Ϊ�㼴��Ҫ���������,��ô
//�Ͳ��ܹ�ʹ��arr[0]��������ʱ����


void ShellArray(int arr[], int n)
{
    int gap, i, j;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = arr[i];
            j = i;
            
            while (j >= gap && temp < arr[j - gap])
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}



void printArray(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// ����ϣ��������
void testShellSort() 
{
	int arr1[] = { 22, 99, 55, 11, 33, 88, 66 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]) ;

	printf("Original array:\n");
	printArray(arr1, n1);

	ShellArray(arr1, n1);

	printf("Sorted array:\n");
	printArray(arr1, n1);
}


int main()
{
	testShellSort();
	return 0;

}