#include <stdio.h>
#include <math.h>

float linear_interpolation(float x, float x0, float x1, float f0, float f1)
{
    float p_x = ((f0 - f1)/(x0 - x1))*x + (x0*f1 - x1*f0)/(x0 - x1);

    return p_x;
}

int main()
{
    float x, x0, x1, f0, f1, p_x;

//Function Value at 1.15

    // Taking values from the table given.
    x = 1.15; x0 = 1.1; x1 = 1.2, f0 = 1.9648; f1 = 2.5722;

    p_x = linear_interpolation(x, x0, x1, f0, f1);

    printf("The function value at 1.15 : %f\n", p_x);

//Function Value at 1.25

    // Taking values from the table given.
    x = 1.25; x0 = 1.2; x1 = 1.3, f0 = 2.5722; f1 = 3.6021;

    p_x = linear_interpolation(x, x0, x1, f0, f1);

    printf("The function value at 1.25 : %f\n", p_x);

    return 0;
}
