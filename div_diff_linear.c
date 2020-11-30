#include <stdio.h>
#include <math.h>

float div_diff(float x0, float x1, float f0, float f1)
{
    return (f1 - f0)/(x1 - x0);
}

float div_diff_linear(float x, float x0, float f, float f0)
{
    return f0 + f*(x - x0);
}

int main()
{
    float x, x0, x1, f0, f1, p_x, f;

    float arr[2][5] = {{1, 2, 4, 7, 12}, {22, 30, 82, 106, 216}};

//Table for Divided Difference
    for(int i = 0; i<4; i++)
    {
        f = div_diff(arr[0][i], arr[0][i+1], arr[1][i], arr[1][i+1]);
        printf("f[%f, %f] = %f\n", arr[0][i], arr[0][i+1], f);
    }

//Function Value at 3

    // Taking values from the table given.
    x = 3; x0 = arr[0][1]; x1 = arr[0][2], f0 = arr[1][1]; f1 = arr[1][2];

    f = div_diff(x0, x1, f0, f1);
    p_x = div_diff_linear(x, x0, f, f0);

    printf("\nThe function value at 3 : %f\n", p_x);

//Function Value at 10

    // Taking values from the table given.
    x = 10; x0 = arr[0][3]; x1 = arr[0][4], f0 = arr[1][3]; f1 = arr[1][4];

    f = div_diff(x0, x1, f0, f1);
    p_x = div_diff_linear(x, x0, f, f0);

    printf("The function value at 10 : %f\n", p_x);

    return 0;
}
