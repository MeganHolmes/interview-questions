// From: https://www.hackerrank.com/challenges/time-conversion/problem

#include "stdio.h"

char* timeConversion(char* s) {
    char hour[2] = {s[0], s[1]};
    char format = {s[8]};

    char* result = malloc(8 * sizeof(char));

    memcpy(result, s, 8); // This will remove the am/pm

    // This feels very stupid, but so is doing string manipulation in C.
    if (format == 'P')
    {
        if (!((hour[0] == '1') && (hour[1] == '2'))) // If hour != 12
        {
            if (hour[1] == '8' || hour[1] == '9' || hour[0] == '1') // If hour > 8
            {
                // if the hour is greater than 8 that means we are at or above 20 in military time
                result[0] = '2';

                if (result[1] > '7')
                {
                    // If the pm hour is 8 or 9 then we need to subtract 8 to get to military time
                    result[1] -= 8;
                }
                else
                {
                    // If the second digit of the pm hour time is less than 8 then we are at 10 or 11pm which is 22 or 23 military time. so we just add 2 to it
                    result[1] += 2;
                }
            }
            else
            {
                // Hour is between 1pm and 7pm (13-19)
                result[0] = '1';
                result[1] += 2;
            }
        }
        else
        {
            // Do nothing, hour is already correct.
        }

    }
    else if ((hour[0] == '1') && (hour[1] == '2'))
    {
        result[0] = '0';
        result[1] = '0';
    }

    return result;
}

int main()
{
    char test[] = "11:55:16PM";

    char* ret = timeConversion(&test);

    printf("Input = %s\n", test);
    printf("Output = %s\n", ret);

    return 0;
}
