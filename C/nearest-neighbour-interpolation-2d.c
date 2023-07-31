// Implement nearest neighbour interpolation in 2D

// Includes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Defines

// Structs
struct point {
    float x;
    float y;
    float val;
};

// sqrt( (x1 - x2)^2 + (y1 - y2)^2 )
float calculate_distance(struct point* p1, struct point* p2)
{
    return sqrtf(powf(p1->x - p2->x,2) + powf(p1->y - p2->y,2));
}

void populate_points(struct point* points, int num)
{
    for (int itr = 0; itr < num; itr++)
    {
        points[itr].x = itr;
        points[itr].y = itr;
        points[itr].val = itr;
    }
}

int find_minimum(float* distances, int num)
{
    float smallest = distances[0];
    int smallest_idx = 0;

    for (int itr = 1; itr < num; itr++)
    {
        if (distances[itr] < smallest)
        {
            smallest = distances[itr];
            smallest_idx = itr;
        }
    }

    return smallest_idx;
}

// Brute force approach
void nearest_neighbour_interp_bf(
    struct point* points,
    struct point* new,
    int num_points)
{
    float* distances = calloc(num_points, sizeof(float));

    for (int itr = 0; itr < num_points; itr++)
    {
        distances[itr] = calculate_distance(&points[itr], new);
    }

    int closet = find_minimum(distances, num_points);

    new->val = points[closet].val;
}

void main()
{
    int num_points = 10;
    struct point* points = calloc(num_points, sizeof(struct point));
    populate_points(points, num_points);

    struct point test = {3.7,3.7};

    nearest_neighbour_interp_bf(points, &test, num_points);

    printf("test point = {%f,%f,%f}\n", test.x, test.y ,test.val);
}
