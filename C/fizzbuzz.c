
#include <stdio.h>

void fizzbuzz(int n)
{
    for (int idx = 1; idx <= n; idx++)
    {
        if (idx % 3 == 0 && idx % 5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (idx % 3 == 0)
        {
            printf("Fizz\n");
        }
        else if (idx % 5 == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", idx);
        }
    }
}

int main()
{
    fizzbuzz(15);

    return 0;
}
