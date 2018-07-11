#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int *sortArr = (int*)malloc(sizeof(int)*(right + 1));
	int sIdx = left;

	// 병합 할 두 영역의 데이터들을 비교, 정렬순서대로 sortArr에 하나씩 옮김.
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx]) sortArr[sIdx] = arr[fIdx++];
		else sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		// 뒷부분 처리.
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		// 앞부분 처리.
		for (i = fIdx; i <= mid;i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right;i++)
		arr[i] = sortArr[i];

	free(sortArr);	
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right) // 더 나눌 수 있다는 뜻.
	{
		mid = (left + right) / 2;

		//둘로 나눠 정렬.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// 정렬된 두 배열 병합
		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	int i;

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	
	for (i = 0; i < 7;i++)
		printf("%d ", arr[i]);

	putchar('\n');

	return 0;
}