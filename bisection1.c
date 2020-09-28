#include <stdio.h>
#include <math.h>

float func_1(float x);
int main()
{
// ----------function-1 f(x) = x^2 -5 between [0, 4] in 10 iteration-----------

    int  i;
    float root_1 = 0, root_2 = 4, f_1, f_2, m, f_m, root;
    f_1 = func_1(root_1);
    f_2 = func_1(root_2);

    if(f_1*f_2>0)
    {
        printf("Sign of both function is same.");
    }
    else
    {
        for(i=1;i<=10;i++)
        {
            m = (root_1+root_2)*0.5;
            f_m = func_1(m);
            if(f_1*f_m < 0)
            {
                root_2 = m;
            }
            else
            {
                root_1 = m;
            }
        }
        root = (root_1+root_2)*0.5;
        printf("Root of the equation is : %f", root);
    }
    return 0;
}

float func_1(float x)
{
    return x*x - 5;
}
