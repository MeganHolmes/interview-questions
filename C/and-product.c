// https://www.hackerrank.com/challenges/and-product/problem

// includes
#include <stdint.h>
#include <stdio.h>

int and_product(int a, int b)
{
    int result = a;
    int itr_a = a +1;
    int itr_b = b;

    for (int ramp = 1; itr_a <= itr_b; ramp++)
    {
        result = result & itr_a & itr_b;

        itr_a += ramp;
        itr_b -= ramp;
    }

    return result;
}

void main()
{
    int a = 11;
    int b = 15;

    int result = and_product(a,b);

    printf("Result = %d\n", result);
}
