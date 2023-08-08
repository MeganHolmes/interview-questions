// https://www.hackerrank.com/challenges/cipher/problem

// Includes
#include <stdio.h>
#include <stdlib.h>

char* decrypt(char* s, int k, int length)
{
    char* result = calloc(length,sizeof(char));
    result[0] = '1';

    for (int itr = 1; itr < length; itr++)
    {
        if (s[itr] == '1')
        {
            result[itr] = '0';
        }
    }


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
    char* test = "1110001"; // 1110001 result should be 101111
    char* result = decrypt(test, 2, 7);

    printf("\nIn  = %s\nOut = %s\n", test), result;

}
