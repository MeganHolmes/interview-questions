// From https://www.hackerrank.com/challenges/caesar-cipher-1/problem

#include "stdio.h"
#include "stdlib.h"

char caesarRotate(char input, int rotationFactor, char lower, char upper)
{
    char output = input;
    int overshoot = (int)input + rotationFactor - (int)upper; // Casting as ints to avoid char overflow if rotationFactor is high

    if (overshoot > 0)
    {
        while (overshoot > 26) // Guarding against high values of rotationFactor.
        {
            overshoot -= 26;
        }
        output = lower + overshoot-1;
    }
    else // This branch will handle most cases unless high rotationFactor
    {
        output += rotationFactor;
    }
    return output;
}

char* caesarCipher(char* s, int rotationFactor) {
    char* result = calloc(100, sizeof(char));

    for (int idx = 0; idx < 100; idx++)
    {
        if (s[idx] >= 'A' && s[idx] <= 'Z')
        {
            // Capital letter
            result[idx] = caesarRotate(s[idx], rotationFactor, 'A', 'Z');
        }
        else if (s[idx] >= 'a' && s[idx] <= 'z')
        {
            // Lowercase letter
            result[idx] = caesarRotate(s[idx], rotationFactor, 'a', 'z');
        }
        else
        {
            // Special symbol
            result[idx] = s[idx];
        }
    }

    return result;
}

int main(void)
{
    char* test = {"If-you-are-reading-this-please-employ-me"};

    char* result = caesarCipher(test, 78);

    printf(result);

    return 0;
}
