#include <stdio.h>
#include<math.h>

float d_lagrange_fund(float x, float x_var, float v1, float v2, float v3, float v4);
float d2_lagrange_fund(float x, float x_var, float v1, float v2, float v3, float v4);
float d1_numer_differen(float x, float x0, float x1, float x2, float x3, float x4, float f0, float f1, float f2, float f3, float f4);
float d2_numer_differen(float x, float x0, float x1, float x2, float x3, float x4, float f0, float f1, float f2, float f3, float f4);

int main()
{
    float x, x0, x1, x2, x3, x4, f0, f1, f2, f3, f4, dp_x, d2p_x;

    float values[2][5] = {{0.4, 0.5, 0.6, 0.7, 0.8}, {1.5836, 1.7974, 2.0442, 2.2375, 2.6511}};

    x = 0.6; x0 = values[0][0]; x1 = values[0][1]; x2 = values[0][2]; x3 = values[0][3]; x4 = values[0][4];
    f0 = values[1][0]; f1 = values[1][1]; f2 = values[1][2]; f3 = values[1][3]; f4 = values[1][4];

//First derivative.
    dp_x = d1_numer_differen(x, x0, x1, x2, x3, x4, f0, f1, f2, f3, f4);

    printf("f'(%f) = %f\n", x, dp_x);

//Second derivative.
    d2p_x = d2_numer_differen(x, x0, x1, x2, x3, x4, f0, f1, f2, f3, f4);

    printf("f''(%f) = %f\n", x, d2p_x);

    return 0;
}

//Function for finding first derivative of lagrange fundamental polynomial.
float d_lagrange_fund(float x, float x_var, float v1, float v2, float v3, float v4)
{
    float x_values[4] = {v1, v2, v3, v4}, num_prod, den_prod, num = 0, den, dlf;
    int i, j;

    for(i=0; i<4; i++)
    {
        num_prod = 1;
        for(j=0; j<4; j++)
        {
            if(j != i)
            {
                num_prod = num_prod*(x - x_values[j]);
            }
        }
        num = num + num_prod;
    }


    den_prod = 1;
    for(i=0; i<4; i++)
    {
        den_prod = den_prod*(x_var - x_values[i]);
    }
    den = den_prod;

    dlf =  num/den;

    return dlf;
}

//Function for finding second derivative of lagrange fundamental polynomial.
float d2_lagrange_fund(float x, float x_var, float v1, float v2, float v3, float v4)
{
    float x_values[4] = {v1, v2, v3, v4}, num_prod, den_prod, num, sum, den, dlf;
    int i, j, k;

    num = 0;
    for(i=0; i<4; i++)
    {
        sum = 0;
        for(j=0; j<4; j++)
        {
            if(j != i)
            {
                num_prod = 1;
                for(k=0; k<4; k++)
                {
                    if(k != i && k != j)
                    {
                        num_prod = num_prod*(x - x_values[k]);
                    }
                }
                sum = sum + num_prod;
            }
        }
        num = num + sum;
    }

    den_prod = 1;
    for(i=0; i<4; i++)
    {
        den_prod = den_prod*(x_var - x_values[i]);
    }
    den = den_prod;

    dlf =  num/den;

    return dlf;
}

//Function for finding numerical differentiation for first derivative.
float d1_numer_differen(float x, float x0, float x1, float x2, float x3, float x4, float f0, float f1, float f2, float f3, float f4)
{
    float dlf0 = d_lagrange_fund(x, x0, x1, x2, x3, x4);
    float dlf1 = d_lagrange_fund(x, x1, x0, x2, x3, x4);
    float dlf2 = d_lagrange_fund(x, x2, x0, x1, x3, x4);
    float dlf3 = d_lagrange_fund(x, x3, x0, x1, x2, x4);
    float dlf4 = d_lagrange_fund(x, x4, x0, x1, x2, x3);

    float dp4_x = dlf0*f0 + dlf1*f1 + dlf2*f2 + dlf3*f3 + dlf4*f4;

    return dp4_x;
}

//Function for finding numerical differentiation for second derivative.
float d2_numer_differen(float x, float x0, float x1, float x2, float x3, float x4, float f0, float f1, float f2, float f3, float f4)
{
    float d2_lf0 = d2_lagrange_fund(x, x0, x1, x2, x3, x4);
    float d2_lf1 = d2_lagrange_fund(x, x1, x0, x2, x3, x4);
    float d2_lf2 = d2_lagrange_fund(x, x2, x0, x1, x3, x4);
    float d2_lf3 = d2_lagrange_fund(x, x3, x0, x1, x2, x4);
    float d2_lf4 = d2_lagrange_fund(x, x4, x0, x1, x2, x3);

    float d2_p4_x = d2_lf0*f0 + d2_lf1*f1 + d2_lf2*f2 + d2_lf3*f3 + d2_lf4*f4;

    return d2_p4_x;
}
