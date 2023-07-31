// Implement bilinear interpolation

// Includes
#include <stdio.h>
#include <assert.h>

// Structs
struct Point
{
    float x;
    float y;
    float value;
};

// Function prototypes
float linear_interp(float prop, float x_start, float x_end,
    float val_start, float val_end);
float bilinear_interp(struct Point* desired, struct Point* p1, struct Point* p2,
 struct Point* p3, struct Point* p4);

 void main()
 {
    // Test cases

    // Test 1 - Basic test: Answer should be 1.0
    struct Point desired = {1,1,0};
    struct Point p1 = {0,0,0};
    struct Point p2 = {2,0,1};
    struct Point p3 = {0,2,1};
    struct Point p4 = {2,2,2};

    float result = bilinear_interp(&desired, &p1, &p2, &p3, &p4);

    printf("Bilinear interpolation of points {%f, %f, %f}, {%f, %f, %f} "
        "{%f,%f, %f}, {%f, %f, %f} at {%f, %f} is %f\n", p1.x, p1.y, p1.value,
        p2.x, p2.y, p2.value, p3.x, p3.y, p3.value, p4.x, p4.y, p4.value,
        desired.x, desired.y, result);

    // Test 2 - Non-trivial interpolation: Answer should be 39.57
    desired.x = 8; desired.y = 17;
    p1.x = 4;  p1.y = 11; p1.value = 41;
    p2.x = 11; p2.y = 11; p2.value = 29;
    p3.x = 4;  p3.y = 20; p3.value = 44;
    p4.x = 11; p4.y = 20; p4.value = 41;

    result = bilinear_interp(&desired, &p1, &p2, &p3, &p4);

    printf("Bilinear interpolation of points {%f, %f, %f}, {%f, %f, %f} "
        "{%f,%f, %f}, {%f, %f, %f} at {%f, %f} is %f\n", p1.x, p1.y, p1.value,
        p2.x, p2.y, p2.value, p3.x, p3.y, p3.value, p4.x, p4.y, p4.value,
        desired.x, desired.y, result);

    // Test 3 - Half negatives: Answer should be 31.96
    desired.x = 0; desired.y = 0;
    p1.x = -4;  p1.y = -11; p1.value = 41;
    p2.x = 11; p2.y = -11; p2.value = 29;
    p3.x = -4; p3.y = 20;  p3.value = 44;
    p4.x = 11; p4.y = 20;  p4.value = -41;

    result = bilinear_interp(&desired, &p1, &p2, &p3, &p4);

    printf("Bilinear interpolation of points {%f, %f, %f}, {%f, %f, %f} "
        "{%f,%f, %f}, {%f, %f, %f} at {%f, %f} is %f\n", p1.x, p1.y, p1.value,
        p2.x, p2.y, p2.value, p3.x, p3.y, p3.value, p4.x, p4.y, p4.value,
        desired.x, desired.y, result);

    // Test 4 - Negative values: Answer should be -39.72
    desired.x = 0; desired.y = 0;
    p1.x = -4;  p1.y = -11; p1.value = -41;
    p2.x = 11; p2.y = -11; p2.value = -29;
    p3.x = -4; p3.y = 20;  p3.value = -44;
    p4.x = 11; p4.y = 20;  p4.value = -41;

    result = bilinear_interp(&desired, &p1, &p2, &p3, &p4);

    printf("Bilinear interpolation of points {%f, %f, %f}, {%f, %f, %f} "
        "{%f,%f, %f}, {%f, %f, %f} at {%f, %f} is %f\n", p1.x, p1.y, p1.value,
        p2.x, p2.y, p2.value, p3.x, p3.y, p3.value, p4.x, p4.y, p4.value,
        desired.x, desired.y, result);

    // Test 5 - Literal corner case: Answer should be -41
    desired.x = 11; desired.y = 20;
    p1.x = -4;  p1.y = -11; p1.value = -41;
    p2.x = 11; p2.y = -11; p2.value = -29;
    p3.x = -4; p3.y = 20;  p3.value = -44;
    p4.x = 11; p4.y = 20;  p4.value = -41;

    result = bilinear_interp(&desired, &p1, &p2, &p3, &p4);

    printf("Bilinear interpolation of points {%f, %f, %f}, {%f, %f, %f} "
        "{%f,%f, %f}, {%f, %f, %f} at {%f, %f} is %f\n", p1.x, p1.y, p1.value,
        p2.x, p2.y, p2.value, p3.x, p3.y, p3.value, p4.x, p4.y, p4.value,
        desired.x, desired.y, result);

 }

float linear_interp(float prop, float x_start, float x_end,
    float val_start, float val_end)
{
    assert(x_start != x_end);

    return (prop - x_start)*(val_end - val_start)/(x_end - x_start) + val_start;
}

float bilinear_interp(struct Point* desired, struct Point* p1, struct Point* p2,
 struct Point* p3, struct Point* p4)
 {
     assert(p1->y == p2->y);
     assert(p3->y == p4->y);
     assert(p1->x == p3->x);
     assert(p2->x == p4->x);
     assert(desired->x >= p1->x);
     assert(desired->x <= p2->x);
     assert(desired->y >= p1->y);
     assert(desired->y <= p3->y);

     float x_interp1 = linear_interp(desired->x, p1->x, p2->x,
        p1->value, p2->value);
     float x_interp2 = linear_interp(desired->x, p3->x, p4->x,
        p3->value, p4->value);
     return linear_interp(desired->y, p1->y, p3->y, x_interp1, x_interp2);
 }
