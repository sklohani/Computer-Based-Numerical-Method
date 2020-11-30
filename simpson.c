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

float simpson(float h, float fa, float fc, float fb)
{
    float I = (fa + 4*fc + fb)*(h/3);
    return I;
}

int main()
{
    float x0, x1, a, b, c, h, fa, fb, fc, I;
    int n, i;

//Function 1.
    printf("\n-------Function-1-------\n\n");
    x0 = 0; x1 = 3;

    for(n=2; n<=20; n++)
    {
        if(n%2 != 0)
        {
            I = 0;
            h = (x1 - x0)/(n - 1);

            a = x0;
            for(i=2; i<= n; i++)
            {
                if(i%2 != 0)
                {
                    c = a + h;
                    b = a + 2*h;
                    fa = func1(a);
                    fc = func1(c);
                    fb = func1(b);
                    I = I + simpson(h, fa, fc, fb);
                    a = b;
                }
            }

            printf("Integral value for n = %d is: %f\n", n, I);
        }
    }

//Function 2.
    printf("\n-------Function-2-------\n\n");
    x0 = 0; x1 = 1;

    for(n=2; n<=20; n++)
    {
        if(n%2 != 0)
        {
            I = 0;
            h = (x1 - x0)/(n - 1);

            a = x0;
            for(i=2; i<= n; i++)
            {
                if(i%2 != 0)
                {
                    c = a + h;
                    b = a + 2*h;
                    fa = func2(a);
                    fc = func2(c);
                    fb = func2(b);
                    I = I + simpson(h, fa, fc, fb);
                    a = b;
                }
            }

            printf("Integral value for n = %d is: %f\n", n, I);
        }
    }

//Function 3.
    printf("\n-------Function-3-------\n\n");
    x0 = 0; x1 = 0.8;

    for(n=2; n<=20; n++)
    {
        if(n%2 != 0)
        {
            I = 0;
            h = (x1 - x0)/(n - 1);

            a = x0;
            for(i=2; i<= n; i++)
            {
                if(i%2 != 0)
                {
                    c = a + h;
                    b = a + 2*h;
                    fa = func3(a);
                    fc = func3(c);
                    fb = func3(b);
                    I = I + simpson(h, fa, fc, fb);
                    a = b;
                }
            }

            printf("Integral value for n = %d is: %f\n", n, I);
        }
    }

//Function 4.
    printf("\n-------Function-4-------\n\n");
    x0 = 0; x1 = 1;

    for(n=2; n<=20; n++)
    {
        if(n%2 != 0)
        {
            I = 0;
            h = (x1 - x0)/(n - 1);

            a = x0;
            for(i=2; i<= n; i++)
            {
                if(i%2 != 0)
                {
                    c = a + h;
                    b = a + 2*h;
                    fa = func4(a);
                    fc = func4(c);
                    fb = func4(b);
                    I = I + simpson(h, fa, fc, fb);
                    a = b;
                }
            }

            printf("Integral value for n = %d is: %f\n", n, I);
        }
    }

    return 0;
}
