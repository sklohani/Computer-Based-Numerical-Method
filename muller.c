#include <stdio.h>
#include <math.h>

/*
1.  f(x) = x^3 − 13*x − 12 = 0; Take x0=4.5; x1=5.5; x2=5.0 as initial approximations

2.  f(x) = x^7 + 3*x^6 + 7*x^5 + x^4 + 5*x^3 + 2*x^2 + 5*x + 5 = 0; Take x0=0; x1=−0.1; x2=−0.2 as initial approximations

3.  f(x) = x + sin(x) − 1/2 = 0; Take x0=1.0; x1=2.0; x2=1.36 as initial approximations

4.  f(x) = x^4 − x − 10 = 0; Take x0=1.0; x1=2.0; x2=1.71 as initial approximations
*/

float func1(float x)
{
    return pow(x, 3) - 13*x - 12;
}

float func2(float x)
{
    return pow(x, 7) + 3*pow(x, 6) + 7*pow(x, 5) + pow(x, 4) + 5*pow(x, 3) + 2*x*x + 5*x + 5;
}

float func3(float x)
{
    return x + sin(x) - 0.5;
}

float func4(float x)
{
    return pow(x, 4)  - x - 10;
}

float root(float x_k, float x_k_Minus_1, float x_k_Minus_2, float f_k, float f_k_Minus_1, float f_k_Minus_2)
{
    float h_k, h_k_Minus_1, lambda_k, delta_k, g_k, c_k, lambda_Plus, lambda_Minus, lambda_k_Plus_1, x_k_Plus_1;

    h_k = x_k - x_k_Minus_1;
    h_k_Minus_1 = x_k_Minus_1 - x_k_Minus_2;
    lambda_k = h_k/h_k_Minus_1;
    delta_k = 1 + lambda_k;

    g_k = lambda_k*lambda_k*f_k_Minus_2 - delta_k*delta_k*f_k_Minus_1 + (lambda_k + delta_k)*f_k;
    c_k = lambda_k*(lambda_k*f_k_Minus_2 - delta_k*f_k_Minus_1 + f_k);

    lambda_Plus = (-2*delta_k*f_k)/(g_k + sqrt(g_k*g_k - 4*delta_k*f_k*c_k));
    lambda_Minus = (-2*delta_k*f_k)/(g_k - sqrt(g_k*g_k - 4*delta_k*f_k*c_k));

    if(fabs(lambda_Minus)<fabs(lambda_Plus))
    {
        lambda_k_Plus_1 = lambda_Minus;
    }
    else
    {
        lambda_k_Plus_1 = lambda_Plus;
    }

    x_k_Plus_1 = x_k + lambda_k_Plus_1*(x_k - x_k_Minus_1);

    return x_k_Plus_1;
}

int main()
{
    int i, k;
    float x_k_Minus_2, x_k_Minus_1, x_k, x_k_Plus_1, f_k_Minus_2, f_k_Minus_1, f_k, f_k_Plus_1, err = 0.000005;

    for(i = 1; i<=4; i++)
    {
            if(i == 1)
            {
                k = 0;
                x_k_Minus_2 = 4.5;
                x_k_Minus_1 = 5.5;
                x_k = 5.0;

                while(fabs(x_k_Minus_1 - x_k) > err)
                {
                    k++;
                    f_k = func1(x_k);
                    f_k_Minus_1 = func1(x_k_Minus_1);
                    f_k_Minus_2 = func1(x_k_Minus_2);

                    x_k_Plus_1 = root(x_k, x_k_Minus_1, x_k_Minus_2, f_k, f_k_Minus_1, f_k_Minus_2);

                    x_k_Minus_2 = x_k_Minus_1;
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func1(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 2)
            {
                k = 0;
                x_k_Minus_2 = 0.0;
                x_k_Minus_1 = -0.1;
                x_k = -0.2;

                while(fabs(x_k_Minus_1 - x_k) > err)
                {
                    k++;
                    f_k = func2(x_k);
                    f_k_Minus_1 = func2(x_k_Minus_1);
                    f_k_Minus_2 = func2(x_k_Minus_2);

                    x_k_Plus_1 = root(x_k, x_k_Minus_1, x_k_Minus_2, f_k, f_k_Minus_1, f_k_Minus_2);

                    x_k_Minus_2 = x_k_Minus_1;
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func2(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);

            }
            else if(i == 3)
            {
                k = 0;
                x_k_Minus_2 = 1;
                x_k_Minus_1 = 2;
                x_k = 1.36;

                while(fabs(x_k_Minus_1 - x_k) > err)
                {
                    k++;
                    f_k = func3(x_k);
                    f_k_Minus_1 = func3(x_k_Minus_1);
                    f_k_Minus_2 = func3(x_k_Minus_2);

                    x_k_Plus_1 = root(x_k, x_k_Minus_1, x_k_Minus_2, f_k, f_k_Minus_1, f_k_Minus_2);

                    x_k_Minus_2 = x_k_Minus_1;
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func3(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);

            }
            else if(i == 4)
            {
                k = 0;
                x_k_Minus_2 = 1;
                x_k_Minus_1 = 2;
                x_k = 1.71;

                while(fabs(x_k_Minus_1 - x_k) > err)
                {
                    k++;
                    f_k = func4(x_k);
                    f_k_Minus_1 = func4(x_k_Minus_1);
                    f_k_Minus_2 = func4(x_k_Minus_2);

                    x_k_Plus_1 = root(x_k, x_k_Minus_1, x_k_Minus_2, f_k, f_k_Minus_1, f_k_Minus_2);

                    x_k_Minus_2 = x_k_Minus_1;
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func4(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);

            }
        }

    return 0;
}

