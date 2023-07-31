/* From: https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem

Function Description

Complete the calculate_the_maximum function

calculate_the_maximum has the following parameters:

    int n: the highest number to consider
    int k: the result of a comparison must be lower than this number to be considered

Prints

Print the maximum values for the and, or and xor comparisons, each on a separate line.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enums
enum LOGIC
{
    LOGIC_OR = 0,
    LOGIC_XOR,
    LOGIC_AND,
    LOGIC_NUM
};

void calculate_the_maximum(int n, int k) {


    int* best_vals = malloc(sizeof(int)*LOGIC_NUM);
    memset(best_vals, 0, sizeof(int)*LOGIC_NUM);

    for (int a = 1; a <= n; a++)
    {
        for (int b = a+1; b <= n; b++)
        {
            int ab_or = a|b;
            int ab_xor = a^b;
            int ab_and = a&b;

            if (ab_or < k && ab_or > best_vals[LOGIC_OR])
            {
                best_vals[LOGIC_OR] = ab_or;
            }

            if (ab_xor < k && ab_xor > best_vals[LOGIC_XOR])
            {
                best_vals[LOGIC_XOR] = ab_xor;
            }

            if (ab_and < k && ab_and > best_vals[LOGIC_AND])
            {
                best_vals[LOGIC_AND] = ab_and;
            }
        }
    }

    printf("%d\n%d\n%d", best_vals[LOGIC_AND], best_vals[LOGIC_OR],
        best_vals[LOGIC_XOR]);
}

int main() {
    int n = 5;
    int k = 4;

    calculate_the_maximum(n,k);

    return 0;
}
