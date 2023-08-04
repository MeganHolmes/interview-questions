// From: https://www.hackerrank.com/challenges/lonely-integer/problem

#include <stdio.h>

void print_binary(unsigned int input, int num_bits)
{
    while (num_bits > 0)
    {
        unsigned int bit_val = 1 << num_bits - 1;

        if (input >= bit_val)
        {
            printf("1");
            input = input - bit_val;
        }
        else
        {
            printf("0");
        }

        num_bits--;
    }
    printf("\n");
}

int lonelyinteger(int a_count, int* a) {
    // Could do a smaller array if i had uint64_t or uint128_t
    unsigned int bitArray[4] = {0,0,0,0};
    for (int idx = 0; idx < a_count; idx++)
    {
        for (int bitArrayIdx = 0; bitArrayIdx < 4; bitArrayIdx++)
        {
            if (a[idx] < 32*(bitArrayIdx+1))
            {
                unsigned int mask = 1 << a[idx];
                bitArray[bitArrayIdx] = bitArray[bitArrayIdx] ^ mask;
                break;
            }
        }
    }


    int lonelyInt = -1;

    for (int bitArrayIdx = 0; bitArrayIdx < 4; bitArrayIdx++)
    {
        if (bitArray[bitArrayIdx] > 0)
        {
            unsigned int bitCount = 0;
            while (bitArray[bitArrayIdx] != 1)
            {
                bitArray[bitArrayIdx] = bitArray[bitArrayIdx] >> 1;
                bitCount++;
            }
            lonelyInt = bitArrayIdx*32 + bitCount;
            break;
        }
    }

    return lonelyInt;
}

int main(void)
{
    int testArr[19] = {1,1,2,2,3,3,4,4,5,6,6,7,7,8,8,9,9,0,0};

    int result = lonelyinteger(19, testArr);

    printf("Result = %d", result);

    return 0;
}
