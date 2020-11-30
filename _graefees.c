#include <stdio.h>
#include <math.h>

int main()
{
    // Function : x^3 -  6*x^2 + 11*x - 6

    int i, m, k;
    float a[] = {6, -1, -43, 43, 1, -6};
    k = sizeof(a)/sizeof(a[0]);

    float b[k], root[k-1];
    for(m=0; m<4; m++)
    {
        b[0] = pow(a[0], 2);
        for(i=1; i<=k-2; i++)
        {
            b[i] = pow(a[i], 2) - 2*a[i+1]*a[i-1];
        }
        b[k-1] = pow(a[k-1], 2);

        printf("%d : ", m+1);
        for(i=1; i<=k-1; i++)
        {
            root[i-1] = pow(b[i]/b[i-1], 1/pow(2, m+1));
            printf("%f ", root[i-1]);
        }
        printf("\n");

        for(i=0; i<k; i++)
        {
            a[i] = b[i];
        }
    }

    return 0;
}
