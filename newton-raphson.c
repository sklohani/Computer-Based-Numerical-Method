#include <stdio.h>
#include <math.h>

/*
1)  f(x)=x^2−2*x−5 = 0   with initial approximation x0 = 2
2)  f(x)=x*sinx+cosx = 0   with initial approximation x0 = 3.1416
3)  f(x)=x*tanx+1 = 0   with initial approximation x0 = 2.5
4)  Compute square root of a given number n. (your program accepts n as input and computes its square root)
*/

float func1(float x)
{
    return x*x - 2*x -5;
}
float d_func1(float x)
{
    return 2*x - 2;
}

float func2(float x)
{
    return x*sin(x) + cos(x);
}
float d_func2(float x)
{
    return x*cos(x);
}

float func3(float x)
{
    return x*tan(x) + 1;
}
float d_func3(float x)
{
    return tan(x) + x/(cos(x)*cos(x));
}

float func4(float x, float n)
{
    return x*x - n;
}

float d_func4(float x)
{
    return 2*x;
}

float root(float x, float f, float d_f)
{
    return  x - f/d_f;
}



int main()
{
    int i, k;
    float x_k, x_k_Plus_1, f_k, d_f_k, f_k_Plus_1, err = 0.000005;

    for(i = 1; i<=4; i++)
    {
            if(i == 1)
            {
                x_k = 2; // x0 = 2
                k = 1;
                f_k = func1(x_k);
                d_f_k = d_func1(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func1(x_k);
                    d_f_k = d_func1(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k);
                }

                f_k_Plus_1 = func1(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 2)
            {
                x_k = 3.1416; // x0 = 3.1416
                k = 1;
                f_k = func2(x_k);
                d_f_k = d_func2(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func2(x_k);
                    d_f_k = d_func2(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k);
                }

                f_k_Plus_1 = func2(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 3)
            {
                x_k = 2.5; // x0 = 2.5
                k = 1;
                f_k = func3(x_k);
                d_f_k = d_func3(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k);
                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func3(x_k);
                    d_f_k = d_func3(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k);
                }

                f_k_Plus_1 = func3(x_k_Plus_1);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n\n", x_k_Plus_1, f_k_Plus_1, k);
            }
            else if(i == 4)
            {
                float n;
                printf("Type the number : ");
                scanf("%f", &n);
                x_k = 0.1; // Lower Bound = 0
                k = 1;
                f_k = func4(x_k, n);
                d_f_k = d_func4(x_k);
                x_k_Plus_1 = root(x_k, f_k, d_f_k);


                while(fabs(x_k_Plus_1 - x_k) > err)
                {
                    k++;
                    x_k = x_k_Plus_1;
                    f_k = func4(x_k, n);
                    d_f_k = d_func4(x_k);
                    x_k_Plus_1 = root(x_k, f_k, d_f_k);
                }

                f_k_Plus_1 = func4(x_k_Plus_1, n);
                printf("x_k+1 : %.6f, f_k+1: %.6f, iteration : %d\n", x_k_Plus_1, f_k_Plus_1, k);
            }
        }

    return 0;
}
