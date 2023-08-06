// From https://www.hackerrank.com/challenges/grid-challenge/problem

#include <stdlib.h>

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

char* gridChallenge(int grid_count, char** grid) {
    char* result = malloc(3 * sizeof(char));
    result = "YES";

    char* lastLetter = malloc(grid_count * sizeof(char));
    for (int rowIdx = 0; rowIdx < grid_count; rowIdx++)
    {
        // Used insertion sort because it was easy and good for small grids
        // for real projects should use something faster if grid_count > ~10.
        insertionSort(grid[rowIdx], grid_count);

        if (result != "NO") // If the result is NO we can skip the comparisons.
        {
            if (rowIdx == 0)
            {
                lastLetter = grid[rowIdx];
            }
            else
            {
                for (int colIdx = 0; colIdx < grid_count; colIdx++)
                {
                    if (grid[rowIdx][colIdx] < lastLetter[colIdx])
                    {
                        result = "NO";
                        break;
                    }
                }

                lastLetter = grid[rowIdx];
            }
        }
    }

    return result;
}
