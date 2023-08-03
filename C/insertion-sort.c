

#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int* arr, int arrSize)
{
    for (int currentIdx = 1; currentIdx < arrSize; currentIdx++)
    {
        int movingElement = currentIdx;
        for (int compareIdx = movingElement-1; compareIdx >= 0; compareIdx--)
        {
            if (arr[movingElement] < arr[compareIdx])
            {
                swap(&arr[movingElement], &arr[compareIdx]);
                movingElement = compareIdx;
            }
        }
    }
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

    insertionSort(arr, 18);

    printf("Sorted:\n");
    for (int idx = 0; idx < 18; idx++)
    {
        printf("%d,",arr[idx]);
    }
    printf("\n");

    return 0;
}
