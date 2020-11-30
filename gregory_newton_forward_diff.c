#include <stdio.h>
#include <math.h>

float forward_pow_3(float u, float f0, float d_f0, float d2_f0, float d3_f0)
{
    float p_x = f0 + u*d_f0 + (u*(u-1)/2)*d2_f0 + (u*(u-1)*(u-2)/(3*2))*d3_f0;

    return p_x;
}

float forward_pow_4(float u, float f0, float d_f0, float d2_f0, float d3_f0, float d4_f0)
{
    float p_x = f0 + u*d_f0 + (u*(u-1)/2)*d2_f0 + (u*(u-1)*(u-2)/(3*2))*d3_f0 + (u*(u-1)*(u-2)*(u-3)/(4*3*2))*d4_f0;

    return p_x;
}

int main()
{
    float x, x0, d_f0, d2_f0, d3_f0, d4_f0, f0, h, u, p_x;
    int i;
    float values1[2][5] = {{1891, 1901, 1911, 1921, 1931}, {46, 66, 81, 93, 101}};
    float values2[2][4] = {{0, 1, 2, 3}, {1, 0, 1, 10}};
    float values3[2][5] = {{2, 3, 4, 5, 6}, {1, 2, 6, 24, 120}};
    float d_f[4];
    float d2_f[3];
    float d3_f[2];

// First Function.

    //Difference Table
    for(i=0; i<4; i++)
    {
        d_f[i] = values1[1][i+1] - values1[1][i];
    }
    for(i=0; i<3; i++)
    {
        d2_f[i] = d_f[i+1] - d_f[i];
    }
    for(i=0;i<2;i++)
    {
        d3_f[i] = d2_f[i+1] - d2_f[i];
    }
    d4_f0 = d3_f[1] - d3_f[0];

    //Function value at x = 1895
    x = 1895; x0 = values1[0][0]; f0 = values1[1][0];
    h = values1[0][1] - values1[0][0];
    u = (x - x0)/h;
    d_f0 = d_f[0]; d2_f0 = d2_f[0]; d3_f0 = d3_f[0];


    p_x = forward_pow_4(u, f0, d_f0, d2_f0, d3_f0, d4_f0);

    printf("Function value of 1st function at x = %f is : %f\n", x, p_x);

//Second Function.

    //Difference Table
    for(i=0; i<3; i++)
    {
        d_f[i] = values2[1][i+1] - values2[1][i];
    }
    for(i=0; i<2; i++)
    {
        d2_f[i] = d_f[i+1] - d_f[i];
    }
    d3_f0 = d2_f[1] - d2_f[0];

    //Function value at x = -1
    x = -1; x0 = values2[0][0]; f0 = values2[1][0];
    h = values2[0][1] - values2[0][0];
    u = (x - x0)/h;
    d_f0 = d_f[0]; d2_f0 = d2_f[0];


    p_x = forward_pow_3(u, f0, d_f0, d2_f0, d3_f0);

    printf("Function value of 2nd function at x = %f is : %f\n", x, p_x);

//Third Function.

    //Difference Table
    for(i=0; i<4; i++)
    {
        d_f[i] = values3[1][i+1] - values3[1][i];
    }
    for(i=0; i<3; i++)
    {
        d2_f[i] = d_f[i+1] - d_f[i];
    }
    for(i=0;i<2;i++)
    {
        d3_f[i] = d2_f[i+1] - d2_f[i];
    }
    d4_f0 = d3_f[1] - d3_f[0];

    //Function value at x = 2.5
    x = 2.5; x0 = values3[0][0]; f0 = values3[1][0];
    h = values3[0][1] - values3[0][0];
    u = (x - x0)/h;
    d_f0 = d_f[0]; d2_f0 = d2_f[0]; d3_f0 = d3_f[0];


    p_x = forward_pow_4(u, f0, d_f0, d2_f0, d3_f0, d4_f0);

    printf("Function value of 3rd function at x = %f is : %f\n", x, p_x);

    //Function value at x = 4.5
    x = 4.5; x0 = values3[0][0]; f0 = values3[1][0];
    h = values3[0][1] - values3[0][0];
    u = (x - x0)/h;
    d_f0 = d_f[0]; d2_f0 = d2_f[0]; d3_f0 = d3_f[0];


    p_x = forward_pow_4(u, f0, d_f0, d2_f0, d3_f0, d4_f0);

    printf("Function value of 3rd function at x = %f is : %f\n", x, p_x);

    return 0;
}
