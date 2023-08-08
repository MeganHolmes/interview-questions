// From: https://www.hackerrank.com/challenges/mini-max-sum/problem

#include <stdlib.h>

void miniMaxSum(int arr_count, int* arr) {
    int lowestIdx = 0;
    int highestIdx = 0;
    unsigned long sum = arr[0];

    for (int idx = 1; idx < arr_count; idx++)
    {
        sum += arr[idx];

        if (arr[highestIdx] < arr[idx])
        {
            highestIdx = idx;
        }

        if (arr[lowestIdx] > arr[idx])
        {
            lowestIdx = idx;
        }
    }

    unsigned long lowestPossible = sum - (unsigned long)arr[highestIdx];
    unsigned long highestPossible = sum - (unsigned long)arr[lowestIdx];

    printf("%ld %ld", lowestPossible, highestPossible);
}
