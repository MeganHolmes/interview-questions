// Using: https://en.wikipedia.org/wiki/Cubic_Hermite_spline#Representations

#include <stdio.h>
#include <math.h>

float cubic_interp(float desired_x, float x1, float x2, float val1, float val2)
{
    float t = (desired_x - x1) / (x2 - x1);
    float t3 = pow(t,3);
    float t2 = pow(t,2);
    float h00 = 2*t3 - 3*t2 + 1;
    float h10 = t3 - 2*t2 + t;
    float h01 = -2*t3 + 3*t2;
    float h11 = t3 - t2;

    return h00*val1 + h10*x1 + h01*x2 + h11 * val2;
}

void main()
{
    float x1 = 1;
    float x2 = 3;
    float val1 = 1;
    float val2 = 3;
    float desired_x = 2.5;

    float result = cubic_interp(desired_x, x1, x2, val1, val2);

    printf("Interpolation between {%f, %f} and {%f, %f} at %f = %f\n",
    x1, val1, x2, val2, desired_x, result);
}
