#include <stdio.h>
#include <math.h>

float func1(float x);
float func2(float x);
float func3(float x);
float func4(float x);
float root(float x0, float x1, float f0, float f1);

/*
1)  f(x)=x^3–2*x–5=0   in the interval [2, 3]
2)  f(x)=cosx–x*exp(x)=0  in the interval [0, 1]
3)  f(x)=x–exp(−x)=0   in the interval [0, 1]
4)  f(x)=x^3–2*x^2+3*x–5=0  in the interval [1, 2]
*/

int main()
{
    int i, k;
    float x_k_Minus, x_k_Minus_1, x_k, x_k_Plus_1, f_k_Minus, f_k_Minus_1, f_k, f_k_Plus_1, err = 0.000005;

    for(i = 1; i<=4; i++)
    {
            if(i == 1)
            {
                k = 0;
                x_k_Minus_1 = 2; // x0 = 2
                x_k_Minus = x_k_Minus_1;
                x_k = 3; // x1 = 3

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus = func1(x_k_Minus);
                    f_k = func1(x_k);
                    x_k_Plus_1 = root(x_k_Minus, x_k, f_k_Minus, f_k);
                    f_k_Plus_1 = func1(x_k_Plus_1);

                    if(f_k_Plus_1*f_k < 0)
                    {
                        x_k_Minus = x_k;
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                    else
                    {
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                }
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 2)
            {
                k = 0;
                x_k_Minus_1 = 0; // x0 = 0
                x_k_Minus = x_k_Minus_1;
                x_k = 1; // x1 =

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus = func2(x_k_Minus);
                    f_k = func2(x_k);
                    x_k_Plus_1 = root(x_k_Minus, x_k, f_k_Minus, f_k);
                    f_k_Plus_1 = func2(x_k_Plus_1);

                    if(f_k_Plus_1*f_k < 0)
                    {
                        x_k_Minus = x_k;
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                    else
                    {
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                }
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 3)
            {
                k = 0;
                x_k_Minus_1 = 0; // x0 = 0
                x_k_Minus = x_k_Minus_1;
                x_k = 1; // x1 = 1

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus = func3(x_k_Minus);
                    f_k = func3(x_k);
                    x_k_Plus_1 = root(x_k_Minus, x_k, f_k_Minus, f_k);
                    f_k_Plus_1 = func3(x_k_Plus_1);

                    if(f_k_Plus_1*f_k < 0)
                    {
                        x_k_Minus = x_k;
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                    else
                    {
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                }
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 4)
            {
                k = 0;
                x_k_Minus_1 = 1; // x0 = 1
                x_k_Minus = x_k_Minus_1;
                x_k = 2; // x1 = 2

                while(fabs(x_k_Minus_1 - x_k)> err)
                {
                    k++;
                    f_k_Minus = func4(x_k_Minus);
                    f_k = func4(x_k);
                    x_k_Plus_1 = root(x_k_Minus, x_k, f_k_Minus, f_k);
                    f_k_Plus_1 = func4(x_k_Plus_1);

                    if(f_k_Plus_1*f_k < 0)
                    {
                        x_k_Minus = x_k;
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                    else
                    {
                        x_k_Minus_1 = x_k;
                        x_k = x_k_Plus_1;
                    }
                }
                printf("x_k+1 : %.5f, f_k+1: %.5f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
    }

    return 0;
}


float func1(float x)
{
    return x*x*x -2*x - 5;
}

float func2(float x)
{
    return cos(x) - x*exp(x);
}

float func3(float x)
{
    return x - exp(-x);
}

float func4(float x)
{
    return x*x*x - 2*x*x + 3*x -5;
}

float root(float x0, float x1, float f0, float f1)
{
    return  x1 - ((x1 - x0)*f1)/(f1 - f0);
}
