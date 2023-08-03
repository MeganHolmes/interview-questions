

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mergesort(int* arr, int arrSize)
{
    int splitSize = arrSize/2;

    if (arrSize > 1)
    {
        // If this was parallelized you could spawn a new thread to do the left side,
        // this current thread could do the right, then when the right side returns,
        // it would wait for the left side to finish if not already finished. then
        // the rest of the algorithm could continue unchanged. Still might be a better
        // way to do it though, I'm not a PhD.
        mergesort(arr, splitSize); // Left side
        mergesort(arr + splitSize, arrSize - splitSize); // Left side
    }
    else
    {
        return;
    }


    int* newArr = malloc(arrSize * sizeof(int));

    int leftIdx = 0;
    int rightIdx = splitSize;
    int newIdx = 0;
    while (newIdx < arrSize)
    {
        // Check if the remaining of the array is trivial
        if (leftIdx >= splitSize)
        {
            // If the left side is exhausted then we can leave the right side as is
            break;
        }
        else if (rightIdx >= arrSize)
        {
            // If the right side is exhausted we need to move some memory from the left to the right side
            memmove(arr+newIdx, arr+leftIdx, sizeof(int)*(splitSize-leftIdx));
            break;
        }

        if (arr[leftIdx] <= arr[rightIdx])
        {
            newArr[newIdx] = arr[leftIdx];
            leftIdx++;
        }
        else
        {
            newArr[newIdx] = arr[rightIdx];
            rightIdx++;
        }

        newIdx++;
    }

    memcpy(arr, newArr, sizeof(int)*newIdx);
    free(newArr);
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

    mergesort(arr, 18);

    printf("Sorted:\n");
    for (int idx = 0; idx < 18; idx++)
    {
        printf("%d,",arr[idx]);
    }
    printf("\n");

    return 0;
}
