#include <stdio.h>
#include <math.h>

float func(float x);
int main()
{
// For function f(x) = x^3 -4*x -9 between [2.706, 2.707] in 4 iteration----
    int i;
    float root_1=2.706, root_2=2.707, mid, f_1, f_2, f_mid, root;

    f_1 = func(root_1);
    f_2 = func(root_2);

    if (f_1*f_2 > 0)
    {
        printf("Sign of both function values is same.");
    }
    else
    {
        for(i=1;i<=4;i++)
        {
            mid = (root_1+root_2)*0.5;
            f_mid = func(mid);
            if (f_1*f_mid < 0)
            {
                root_2 = mid;
            }
            else
            {
                root_1 = mid;
            }
        }
        root = 0.5*(root_1 + root_2);
        printf("%f", root);
    }
    return 0;



//--------- For function f(x) = x-1.4*cos(x)------------------------------------
    // int i = 0;
    // float root_1, root_2, eps, mid, f_1, f_2, f_mid, root;

    // scanf("%f, %f, %f", &root_1, &root_2, &eps);

    // f_1 = root_1-1.4*cos(root_1);
    // f_2 = root_2-1.4*cos(root_2);

    // if (f_1*f_2 > 0)
    // {
    //     printf("Sign of both function values is same.");
    //     return 0;
    // }
    // while (fabs(root_1 - root_2) >= eps)
    // {
    //     mid = (root_1+root_2)*0.5;
    //     f_mid = mid-1.4*cos(mid);
    //     i = i + 1;
    //     if (f_1*f_mid < 0)
    //     {
    //         root_2 = mid;
    //     }
    //     else
    //     {
    //         root_1 = mid;
    //     }
    // }
    // root = 0.5*(root_1 + root_2);
    // printf("%f, %d", root, i);
    // return 0;
//------------------------------------------------------------------------------
}

float func(float x)
{
    return x*x*x -4*x - 9;
}
