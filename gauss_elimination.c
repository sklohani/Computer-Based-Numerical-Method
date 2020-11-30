#include <stdio.h>
#include <math.h>

void gauss_elimination(float a[3][3], float b[3])
{
    int i, j;
    float temp, x1, x2, x3;

    temp = a[1][0]/a[0][0];
    for(j=0; j<3; j++)
    {
        a[1][j] -= temp*a[0][j];
    }
    b[1] = b[1] - temp*b[0];

    temp = a[2][0]/a[0][0];
    for(j=0; j<3; j++)
    {
        a[2][j] -= temp*a[0][j];
    }
    b[2] = b[2] - temp*b[0];

    temp = a[2][1]/a[1][1];
    for(j=0; j<3; j++)
    {
        a[2][j] -= temp*a[1][j];
    }
    b[2] = b[2] - temp*b[1];

    x3 = b[2]/a[2][2];
    x2 = (b[1] - a[1][2]*x3)/a[1][1];
    x1 = (b[0] - a[0][1]*x2 - a[0][2]*x3)/a[0][0];

    printf("x1 = %f, x2 = %f, x3 = %f\n\n", x1, x2, x3);
}

int main()
{
    float a1_arr[3][3] = {{20, 15, 10}, {-3, -2.249, 7}, {5, 1, 3}}, b1_arr[3] = {45, 1.751, 9};
    float a2_arr[3][3] = {{4, 5, 7}, {0, 5, 6}, {9, 2, 3}}, b2_arr[3] = {16, 11, 15};
    float a3_arr[3][3] = {{2, 4, 6}, {3, 8, 5}, {-1, 1, 2}}, b3_arr[3] = {22, 27, 2};

// Linear Equation 1.
    printf("Solution for system of Linear Equation 1.\n");
    gauss_elimination(a1_arr, b1_arr);

// Linear Equation 2.
    printf("Solution for system of Linear Equation 2.\n");
    gauss_elimination(a2_arr, b2_arr);

// Linear Equation 3.
    printf("Solution for system of Linear Equation 3.\n");
    gauss_elimination(a3_arr, b3_arr);

    return 0;
}
