// Implement cubic interpolation

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float cubic_interp(float desired_x, float* x_vals, float* y_vals)
{
    float b0 = y_vals[0];
    float b1 = (y_vals[1] - y_vals[0]) / (x_vals[1] - x_vals[0]);
    float b2 = ((y_vals[2] - y_vals[1]) / (x_vals[2] - x_vals[1]) - b1) /
     (x_vals[2] - x_vals[0]);

    return b0 + b1*(desired_x - x_vals[0]) + b2*(desired_x - x_vals[0])*
    (desired_x-x_vals[1]);
}

void main()
{
    float* x_vals = calloc(3, sizeof(float));
    float* y_vals = calloc(3, sizeof(float));
    x_vals[0] = 0;
    x_vals[1] = 1;
    x_vals[2] = 2;
    y_vals[0] = 1;
    y_vals[1] = 2;
    y_vals[2] = 3;
    float desired_x = 0;

    float result = cubic_interp(desired_x, x_vals, y_vals);

    printf("Result = %f\n",result);
}
