#include <stdio.h>
#include <math.h>

float func1(float x)
{
    float fx = (1/(1 + pow(x, 3)));
    return fx;
}
float func2(float x)
{
    float fx = pow(sin(x*M_PI), 2);
    return fx;
}
float func3(float x)
{
    float fx = exp(-1*pow(x, 2));
    return fx;
}
float func4(float x)
{
    float fx = x*exp(-x);
    return fx;
}

float trapezoidal(float h, float fa, float fb)
{
    float I = (fb + fa)*(h/2);
    return I;
}

int main()
{
    float x0, x1, a, b, h, fa, fb, I;
    int n, i;

//Function 1.
    printf("\n-------Function-1-------\n\n");
    x0 = 0; x1 = 3;

    for(n=2; n<=20; n++)
    {
        I = 0;
        h = (x1 - x0)/(n - 1);

        a = x0;
        for(i=2; i<= n; i++)
        {
            b = a + h;
            fa = func1(a);
            fb = func1(b);
            I = I + trapezoidal(h, fa, fb);
            a = b;
        }

        printf("Integral value for n = %d is: %f\n", n, I);
    }

//Function 2.
    printf("\n-------Function-2-------\n\n");
    x0 = 0; x1 = 1;

    for(n=2; n<=20; n++)
    {
        I = 0;
        h = (x1 - x0)/(n - 1);

        a = x0;
        for(i=2; i<= n; i++)
        {
            b = a + h;
            fa = func2(a);
            fb = func2(b);
            I = I + trapezoidal(h, fa, fb);
            a = b;
        }

        printf("Integral value for n = %d is: %f\n", n, I);
    }

//Function 3.
    printf("\n-------Function-3-------\n\n");
    x0 = 0; x1 = 0.8;

    for(n=2; n<=20; n++)
    {
        I = 0;
        h = (x1 - x0)/(n - 1);

        a = x0;
        for(i=2; i<= n; i++)
        {
            b = a + h;
            fa = func3(a);
            fb = func3(b);
            I = I + trapezoidal(h, fa, fb);
            a = b;
        }

        printf("Integral value for n = %d is: %f\n", n, I);
    }

//Function 4.
    printf("\n-------Function-4-------\n\n");
    x0 = 0; x1 = 1;

    for(n=2; n<=20; n++)
    {
        I = 0;
        h = (x1 - x0)/(n - 1);

        a = x0;
        for(i=2; i<= n; i++)
        {
            b = a + h;
            fa = func4(a);
            fb = func4(b);
            I = I + trapezoidal(h, fa, fb);
            a = b;
        }

        printf("Integral value for n = %d is: %f\n", n, I);
    }

    return 0;
}
