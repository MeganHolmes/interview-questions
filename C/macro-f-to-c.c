// Implement a macro to convert fahrenheit to celsius

// Includes
#include <stdio.h>
#include <stdint.h>

// Defines
#define CONVERT_F_TO_C(f) (f-32) / 1.8f

void main()
{
    // Test cases

    // Test 1 Answer is 20.0
    float test_val = 68.0f;
    float result = CONVERT_F_TO_C(test_val);

    printf("%f Fahrenheit is %f in celsius\n", test_val, result);

    // Test 2 Answer is -17.78
    test_val = 0.0f;
    result = CONVERT_F_TO_C(test_val);

    printf("%f Fahrenheit is %f in celsius\n", test_val, result);

    // Test 3 Answer is -73.33
    test_val = -100.0f;
    result = CONVERT_F_TO_C(test_val);

    printf("%f Fahrenheit is %f in celsius\n", test_val, result);

    volatile uint8_t x = 2;
    volatile uint8_t* x_ptr = &x;


    uint16_t res = (uint16_t)*x_ptr * (uint16_t)*x_ptr;
    printf("Result = %i", res);

}
