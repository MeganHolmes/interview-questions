// From https://www.hackerrank.com/challenges/countingsort1/problem

#include <stdlib.h>

int* countingSort(int arr_count, int* arr, int* result_count) {
    *result_count = 100;
    int *result = calloc(*result_count, sizeof(int));

    for (int idx = 0; idx < arr_count; idx++)
    {
        result[arr[idx]]++;
    }

    return result;
}
