#include <stdio.h>
#include <math.h>

float func(float x, float y)
{
    return x + y;
}

float runge_kutta(float x, float y, float h)
{
    float k1, k2, k3, k4, dy;

    k1 = func(x, y)*h;
    printf("%f\n", k1);
    k2 = func((x+h/2), (y+k1/2))*h;
    printf("%f\n", k2);
    k3 = func((x+h/2), (y+k2/2))*h;
    printf("%f\n", k3);
    k4 = func((x+h), (y+k3))*h;
    printf("%f\n", k4);

    dy = (k1 + 2*k2 + 2*k3 + k4)/6;
    printf("%f\n", dy);

    return dy;
}

int main()
{
    int i, ival;
    float x = 0, y = 1;
    float h = 0.1;
    float dy;
    ival = 2;

    for(i=0; i<ival; i++)
    {
        dy = runge_kutta(x, y, h);
        x = x + h;
        y = y + dy;

        printf("%f, %f\n", x, y);
    }

    return 0;
}
