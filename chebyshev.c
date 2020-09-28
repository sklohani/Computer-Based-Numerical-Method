#include <stdio.h>
#include <math.h>

/*
1.  f(x) = x^3 − 13*x − 12 = 0; Take x0 = 5.0 as initial approximation

2.  f(x) = x^7 + 3*x^6 + 7*x^5 + x^4 + 5*x^3 + 2*x^2 + 5x + 5 = 0;  Take x0 = −0.1 as initial approximation

3.  f(x) = x + sin(x) − 1/2 = 0; Take x0 = 1.36 as initial approximation

4.  f(x) = x^4 − x − 10 = 0; Take x0 = 1.71 as initial approximation
*/

float func1(float x)
{
    return pow(x, 3) - 13*x - 12;
}
float d_func1(float x)
{
    return 3*x*x - 13;
}
float d2_func1(float x)
{
    return 6*x;
}

float func2(float x)
{
    return pow(x, 7) + 3*pow(x, 6) + 7*pow(x, 5) + pow(x, 4) + 5*pow(x, 3) + 2*x*x + 5*x + 5;
}
float d_func2(float x)
{
    return 7*pow(x, 6) + 18*pow(x, 5) + 35*pow(x, 4) + 4*pow(x, 3) + 15*x*x + 4*x + 5;
}
float d2_func2(float x)
{
    return 42*pow(x, 5) + 90*pow(x, 4) + 140*pow(x, 3) + 12*x*x + 15*x + 4;
}

float func3(float x)
{
    return x + sin(x) - 0.5;
}
float d_func3(float x)
{
    return 1 + cos(x);
}
float d2_func3(float x)
{
    return -sin(x);
}

float func4(float x)
{
    return pow(x, 4)  - x - 10;
}
float d_func4(float x)
{
    return 4*pow(x, 3)  - 1;
}
float d2_func4(float x)
{
    return 12*x*x;
}

float root(float x_k, float f_k, float d_f_k, float d2_f_k)
{
    return x_k - f_k/d_f_k - (f_k*f_k*d2_f_k)/(2*pow(d_f_k, 3));
}

int main()
{
    int i, k;
    float x_k, x_k_Plus_1, f_k, d_f_k, d2_f_k, f_k_Plus_1, err = 0.000005;

    for(i = 1; i<=4; i++)
    {
            if(i == 1)
            {
                k = 1;
                x_k = 5;
                f_k = func1(x_k);
                d_f_k = d_func1(x_k);
                d2_f_k = d2_func1(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func1(x_k);
                    d_f_k = d_func1(x_k);
                    d2_f_k = d2_func1(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                }

                f_k_Plus_1 = func1(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 2)
            {
                k = 1;
                x_k = -0.1;
                f_k = func2(x_k);
                d_f_k = d_func2(x_k);
                d2_f_k = d2_func2(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func2(x_k);
                    d_f_k = d_func2(x_k);
                    d2_f_k = d2_func2(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                }

                f_k_Plus_1 = func2(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);

            }
            else if(i == 3)
            {
                k = 1;
                x_k = 1.36;
                f_k = func3(x_k);
                d_f_k = d_func3(x_k);
                d2_f_k = d2_func3(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func3(x_k);
                    d_f_k = d_func3(x_k);
                    d2_f_k = d2_func3(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                }

                f_k_Plus_1 = func3(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);

            }
            else if(i == 4)
            {
                k = 1;
                x_k = 1.71;
                f_k = func4(x_k);
                d_f_k = d_func4(x_k);
                d2_f_k = d2_func4(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func4(x_k);
                    d_f_k = d_func4(x_k);
                    d2_f_k = d2_func4(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k, d2_f_k);
                }

                f_k_Plus_1 = func4(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);

            }
        }

    return 0;
}
