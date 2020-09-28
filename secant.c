#include <stdio.h>
#include <math.h>

float func1(float x);
float func2(float x);
float func3(float x);
float func4(float x);
float root(float x0, float x1, float f0, float f1);

int main()
{
    int i, k;
    float x0 = 0, x1 = 1, x_k_Minus_1, x_k, x_k_Plus_1, f_k_Minus_1, f_k, f_k_Plus_1, err = 0.000005;

    for(i = 1; i<=4; i++)
    {
            if(i == 1)
            {
                k = 0;
                x_k_Minus_1 = x0;
                x_k = x1;

                while(fabs(x_k_Minus_1 - x_k) > err)
                {
                    k++;
                    f_k_Minus_1 = func1(x_k_Minus_1);
                    f_k = func1(x_k);
                    x_k_Plus_1 = root(x_k_Minus_1, x_k, f_k_Minus_1, f_k);
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func1(x_k_Plus_1);
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 2)
            {
                k = 0;
                x_k_Minus_1 = x0;
                x_k = x1;

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus_1 = func2(x_k_Minus_1);
                    f_k = func2(x_k);
                    x_k_Plus_1 = root(x_k_Minus_1, x_k, f_k_Minus_1, f_k);
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func2(x_k_Plus_1);
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 3)
            {
                k = 0;
                x_k_Minus_1 = x0;
                x_k = x1;

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus_1 = func3(x_k_Minus_1);
                    f_k = func3(x_k);
                    x_k_Plus_1 = root(x_k_Minus_1, x_k, f_k_Minus_1, f_k);
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func3(x_k_Plus_1);
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 4)
            {
                k = 0;
                x_k_Minus_1 = x0;
                x_k = x1;

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus_1 = func4(x_k_Minus_1);
                    f_k = func4(x_k);
                    x_k_Plus_1 = root(x_k_Minus_1, x_k, f_k_Minus_1, f_k);
                    x_k_Minus_1 = x_k;
                    x_k = x_k_Plus_1;
                }
                f_k_Plus_1 = func4(x_k_Plus_1);
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
        }

    return 0;
}

float func1(float x)
{
    return cos(x) + 2*sin(x) + x*x;
}

float func2(float x)
{
    return x*x*x - 4;
}

float func3(float x)
{
    return 3*x + sin(x) - exp(x);
}

float func4(float x)
{
    return exp(x) - 3*x;
}

float root(float x0, float x1, float f0, float f1)
{
    return  x1 - ((x1 - x0)*f1)/(f1 - f0);
}
