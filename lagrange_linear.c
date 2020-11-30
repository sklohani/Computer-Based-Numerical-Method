#include <stdio.h>
#include <math.h>

float lagrange_linear(float x, float x0, float x1, float f0, float f1)
{
    float p_x = ((x - x1)/(x0 - x1))*f0 + ((x - x0)/(x1 - x0))*f1;

    return p_x;
}

int main()
{
    float x, x0, x1, f0, f1, p_x;

    float x_arr[] = {-2, 0, 5, 6};
    float fx_arr[] = {-2.63906, -2.48491, -1.94591, -1.79176};

//Function Value at -0.8

    // Taking values from the table given.
    x = -0.8; x0 = x_arr[0]; x1 = x_arr[1], f0 = fx_arr[0]; f1 = fx_arr[1];

    p_x = lagrange_linear(x, x0, x1, f0, f1);

    printf("The function value at -0.8 : %f\n", p_x);

//Function Value at 0.8

    // Taking values from the table given.
    x = 0.8; x0 = x_arr[1]; x1 = x_arr[2], f0 = fx_arr[1]; f1 = fx_arr[2];

    p_x = lagrange_linear(x, x0, x1, f0, f1);

    printf("The function value at 0.8 : %f\n", p_x);

//Function Value at 5.5

    // Taking values from the table given.
    x = 5.5; x0 = x_arr[2]; x1 = x_arr[3], f0 = fx_arr[2]; f1 = fx_arr[3];

    p_x = lagrange_linear(x, x0, x1, f0, f1);

    printf("The function value at 5.5 : %f\n", p_x);

    return 0;
}
