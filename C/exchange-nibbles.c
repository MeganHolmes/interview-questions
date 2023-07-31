// Exchange 2 nibbles in a byte using shift operators

// Includes
#include <math.h>
#include <stdio.h>
#include <stdint.h>


uint8_t exchange_nibbles(uint8_t input)
{
    uint8_t result = input;
    input = input >> 4;
    result = result << 4;
    return result | input;
}

void print_binary(int input, int num_bits)
{

    while (num_bits > 0)
    {
        int bit_val = 1 << num_bits-1;

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
    // Test case 1: 1011 0010 = 178 answer should be: 0010 1011 = 43
    uint8_t test = 178;
    uint8_t result = exchange_nibbles(test);

    print_binary(test,8);
    printf(" Swapped to ");
    print_binary(result,8);
    printf("\n");
}
