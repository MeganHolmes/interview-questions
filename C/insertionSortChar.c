

#include <stdio.h>

void swap(char* arr, int a, int b)
{
    char temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertionSort(char* arr, int arrSize)
{
    for (int currentIdx = 1; currentIdx < arrSize; currentIdx++)
    {
        int movingElement = currentIdx;
        for (int compareIdx = movingElement-1; compareIdx >= 0; compareIdx--)
        {
            if (arr[movingElement] < arr[compareIdx])
            {
                swap(arr, movingElement, compareIdx);
                movingElement = compareIdx;
            }
        }
    }
}

int main()
{
    char* arr = "asljkdfnakjnfqyuzv";

    printf("Original:\n");
    printf(arr);
    printf("\n");

    insertionSort(arr, 18);

    printf("Sorted:\n");
    printf(arr);
    printf("\n");

    return 0;
}
