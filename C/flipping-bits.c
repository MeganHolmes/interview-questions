// https://www.hackerrank.com/challenges/flipping-bits/

// Includes
#include <stdio.h>
#include <stdint.h>

uint32_t flippingBits(uint32_t n) {
    return ~n;
}

void print_binary(uint32_t input, uint32_t num_bits)
{
    while (num_bits > 0)
    {
        uint32_t bit_val = 1 << num_bits - 1;

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
}

void main()
{
    uint32_t in = 42;
    uint32_t result = flippingBits(in);

    printf("In  = ");
    print_binary(in, 32);
    printf("\nOut = ");
    print_binary(result, 32);
    printf("\n");
}
