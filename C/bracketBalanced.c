// From https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

inline bool isOpener(char a)
{
    return (a == '(' || a == '[' || a == '{');
}

inline bool isMatchingPair(char a, char b)
{
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

char* isBalanced(char* s) {
    char* result = malloc(4*sizeof(char));

    int length = 0;
    for (int idx = 0; s[idx] != '\0'; idx++)
    {
        length++;
    }

    if (length % 2 != 0)
    {
        printf("Failed eveness check\n");
        result = "NO";
        return result;
    }

    char* tracker = malloc((length/2)*sizeof(char));
    int trackerIdx = 0;

    for (int idx = 0; idx < length; idx++)
    {
        if (isOpener(s[idx]))
        {
            printf("Add %c from idx %d to tracker at idx %d\n", s[idx], idx, trackerIdx);
            tracker[trackerIdx] = s[idx];
            trackerIdx++;
        }
        else if (trackerIdx == 0)
        {
            trackerIdx = -1; // Used as flag to trigger the result
            printf("Tracker index empty with %c at %d\n", s[idx], idx);
            break;
        }
        else if (isMatchingPair(tracker[trackerIdx-1], s[idx]))
        {
            printf("Remove %c from tracker at %d to match with %c at %d\n", tracker[trackerIdx-1], trackerIdx-1, s[idx], idx);
            trackerIdx--;
        }
        else
        {
            printf("Error. tracker char = %c, string char = %c, trackerIdx = %d, idx = %d\n",tracker[trackerIdx], s[idx], trackerIdx, idx);
        }

    }

    result = ((trackerIdx == 0) ? "YES" : "NO");
    return result;
}

int main(void)
{
    char test1[] = "{[()]}";
    char test2[] = "{[(])}";
    char test3[] = "{[]()}";
    char test4[] = "{[](){}{}[()]}";
    char test5[] = "{[[](()())]{}{}[()]}";
    char test6[] = "{{)[](}}";
    char test7[] = "{(([])[])[]]}";
    char test8[] = "]]{([])}";
    char test9[] = "([]){{}";
    char test10[] = "{{";
    char experimental[] = "{}()[[((()(({{[]}{}{{[]}}{}}))))]]{{{{([{{{{}}}}])}}}}";

    printf("\n");
    char* result = isBalanced(test1);
    printf("Test1 = %s, result = %s, expected result = YES\n\n\n",test1, result);
    assert(result[0] == 'Y');

    result = isBalanced(test2);
    printf("Test2 = %s, result = %s, expected result = NO\n\n\n",test2, result);
    assert(result[0] == 'N');

    result = isBalanced(test3);
    printf("Test3 = %s, result = %s, expected result = YES\n\n\n",test3, result);
    assert(result[0] == 'Y');

    result = isBalanced(test4);
    printf("Test4 = %s, result = %s, expected result = YES\n\n\n",test4, result);
    assert(result[0] == 'Y');

    result = isBalanced(test5);
    printf("Test5 = %s, result = %s, expected result = YES\n\n\n",test5, result);
    assert(result[0] == 'Y');

    result = isBalanced(test6);
    printf("Test6 = %s, result = %s, expected result = NO\n\n\n",test6, result);
    assert(result[0] == 'N');

    result = isBalanced(test7);
    printf("Test7 = %s, result = %s, expected result = NO\n\n\n",test7, result);
    assert(result[0] == 'N');

    result = isBalanced(test8);
    printf("Test8 = %s, result = %s, expected result = NO\n\n\n",test8, result);
    assert(result[0] == 'N');

    result = isBalanced(test9);
    printf("Test9 = %s, result = %s, expected result = NO\n\n\n",test9, result);
    assert(result[0] == 'N');

    result = isBalanced(test10);
    printf("Test10 = %s, result = %s, expected result = NO\n\n\n",test10, result);
    assert(result[0] == 'N');

    result = isBalanced(experimental);
    printf("experimental = %s, result = %s, expected result = ?\n\n\n",experimental, result);
    assert(result[0] == 'Y');
}
