
#include "stdio.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int* arr, int low, int high)
{
    if (high -  low < 2)
    {
        return;
    }

    int pivot = arr[high];
    int pivotIdx = low - 1;

    for (int compareIdx = low; compareIdx < high; compareIdx++)
    {
        if (pivot >= arr[compareIdx])
        {
            pivotIdx++;
            swap(&arr[pivotIdx], &arr[compareIdx]);
        }
    }
    
    pivotIdx++;
    swap(&arr[pivotIdx], &arr[high]);

    quicksort(arr, low, pivotIdx-1); // left side
    quicksort(arr, pivotIdx + 1, high); // right side
}

int main()
{
    int arr[18] = {4,6,8,2,0,1,5,4,3,7, 9, 13, 11, 100, 88, 66, 33, 44};

    printf("Original:\n");
    for (int idx = 0; idx < 18; idx++)
    {
        printf("%d,",arr[idx]);
    }
    printf("\n");

    quicksort(arr, 0, 18-1);

    printf("Sorted:\n");
    for (int idx = 0; idx < 18; idx++)
    {
        printf("%d,",arr[idx]);
    }
    printf("\n");

    return 0;
}
