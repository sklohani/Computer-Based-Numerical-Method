#include <stdio.h>
#include <math.h>

float func(float x, float y)
{
    return -2*x*pow(y, 2);
}

int main()
{
    int i, ival;
    float x = 0, y = 1, h = 0.2, err = 0.00001;
    float for_x = 0.4;
    ival = for_x/h;

    float x1, y1, y12, dy_dx0, dy_dx1;

    for(i=0; i<ival; i++)
    {
        dy_dx0 = func(x, y);
        x1 = x + h;
        y1 = y + dy_dx0*h;

        do
        {
            y12 = y1;
            dy_dx1 = func(x1, y12);
            y1 = y + ((dy_dx0 + dy_dx1)/2)*h;
        }while(fabs(y1 - y12) > err);

        x = x1;
        y = y1;
    }

    printf("%f", y);
    return 0;
}
