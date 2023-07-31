// From https://www.hackerrank.com/challenges/plus-minus/problem

#include <stdio.h>

void plusMinus(int arr_count, int* arr) {
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    for (int idx = 0; idx < arr_count; idx++)
    {
        if (arr[idx] > 0)
        {
            positiveCount++;
        }
        else if (arr[idx] < 0)
        {
            negativeCount++;
        }
        else
        {
            zeroCount++;
        }
    }

    float positiveRatio = ((float)positiveCount)/((float)arr_count);
    float negativeRatio = ((float)negativeCount)/((float)arr_count);
    float zeroRatio = ((float)zeroCount)/((float)arr_count);

    printf("%.6f\n", positiveRatio);
    printf("%.6f\n", negativeRatio);
    printf("%.6f\n", zeroRatio);
}
