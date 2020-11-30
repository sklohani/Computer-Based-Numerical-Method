#include <stdio.h>
#include <math.h>

float lagrange_power_2(float x, float x0, float x1, float x2, float f0, float f1, float f2)
{
    float lf0 = ((x - x1)*(x - x2))/((x0 - x1)*(x0 - x2));
    float lf1 = ((x - x0)*(x - x2))/((x1 - x0)*(x1 - x2));
    float lf2 = ((x - x0)*(x - x1))/((x2 - x0)*(x2 - x1));

    float p2_x = lf0*f0 + lf1*f1 + lf2*f2;

    return p2_x;
}

float lagrange_power_4(float x, float x0, float x1, float x2, float x3, float x4, float f0, float f1, float f2, float f3, float f4)
{
    float lf0 = ((x - x1)*(x - x2)*(x - x3)*(x - x4))/((x0 - x1)*(x0 - x2)*(x0 - x3)*(x0 - x4));
    float lf1 = ((x - x0)*(x - x2)*(x - x3)*(x - x4))/((x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4));
    float lf2 = ((x - x0)*(x - x1)*(x - x3)*(x - x4))/((x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4));
    float lf3 = ((x - x0)*(x - x1)*(x - x2)*(x - x4))/((x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4));
    float lf4 = ((x - x0)*(x - x1)*(x - x2)*(x - x3))/((x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3));

    float p4_x = lf0*f0 + lf1*f1 + lf2*f2 + lf3*f3 + lf4*f4;

    return p4_x;
}

float lagrange_power_5(float x, float x0, float x1, float x2, float x3, float x4, float x5, float f0, float f1, float f2, float f3, float f4, float f5)
{
    float lf0 = ((x - x1)*(x - x2)*(x - x3)*(x - x4)*(x - x5))/((x0 - x1)*(x0 - x2)*(x0 - x3)*(x0 - x4)*(x0 - x5));
    float lf1 = ((x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5))/((x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5));
    float lf2 = ((x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5))/((x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5));
    float lf3 = ((x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5))/((x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5));
    float lf4 = ((x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5))/((x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5));
    float lf5 = ((x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4))/((x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4));

    float p5_x = lf0*f0 + lf1*f1 + lf2*f2 + lf3*f3 + lf4*f4 + lf5*f5;

    return p5_x;
}

int main()
{
    float x, x0, x1, x2, x3, x4, x5, f0, f1, f2, f3, f4, f5, p_x;

    float values1[2][3] = {{0, 1, 3}, {1, 3, 35}};
    float values2[2][6] = {{0, 1, 2, 4, 5, 6}, {1, 14, 15, 5, 6, 19}};
    float values3[2][5] = {{0.1, 0.2, 0.3, 0.4, 0.5}, {9.9833, 4.9667, 3.2836, 2.4339, 1.9177}};

//First Function.

    x = 2; x0 = values1[0][0]; x1 = values1[0][1]; x2 = values1[0][2];
    f0 = values1[1][0]; f1 = values1[1][1]; f2 = values1[1][2];

    p_x = lagrange_power_2(x, x0, x1, x2, f0, f1, f2);
    printf("Function value for 1st function at x = %f is : %f\n", x, p_x);

// Second Function.

    x = 3; x0 = values2[0][0]; x1 = values2[0][1]; x2 = values2[0][2]; x3 = values2[0][3]; x4 = values2[0][4]; x5 = values2[0][5];
    f0 = values2[1][0]; f1 = values2[1][1]; f2 = values2[1][2]; f3 = values2[1][3]; f4 = values2[1][4]; f5 = values2[1][5];

    p_x = lagrange_power_5(x, x0, x1, x2, x3, x4, x5, f0, f1, f2, f3, f4, f5);
    printf("Function value for 2nd function at x = %f is : %f\n", x, p_x);

// Third Function.

    //Function value at x = 0.25
    x = 0.25; x0 = values3[0][0]; x1 = values3[0][1]; x2 = values3[0][2]; x3 = values3[0][3]; x4 = values3[0][4];
    f0 = values3[1][0]; f1 = values3[1][1]; f2 = values3[1][2]; f3 = values3[1][3]; f4 = values3[1][4];

    p_x = lagrange_power_4(x, x0, x1, x2, x3, x4, f0, f1, f2, f3, f4);
    printf("Function value for 3rd function at x = %f is : %f\n", x, p_x);

    //Function value at x = 0.35;
    x = 0.35; x0 = values3[0][0]; x1 = values3[0][1]; x2 = values3[0][2]; x3 = values3[0][3]; x4 = values3[0][4];
    f0 = values3[1][0]; f1 = values3[1][1]; f2 = values3[1][2]; f3 = values3[1][3]; f4 = values3[1][4];

    p_x = lagrange_power_4(x, x0, x1, x2, x3, x4, f0, f1, f2, f3, f4);
    printf("Function value for 3rd function at x = %f is : %f\n", x, p_x);

    return 0;
}
