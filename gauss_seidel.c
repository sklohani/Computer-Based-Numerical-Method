#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 3

float *gauss_seidal(float A[M][M], float B[M], float X[M], int n)
{
    int i, j;
    static float sol[M];
    float res;

    for(i=0; i<n; i++)
    {
        res = 0;
        for(j=0; j<n; j++)
        {
            if(j != i)
            {
                res += A[i][j]*X[j];
            }
        }
        res = -1*res;
        res += B[i];
        res /= A[i][i];
        sol[i] = res;
        X[i] = res;
    }

    return sol;
}

int main()
{
    int i, j, iter, n;
    n = M;
    float A[M][M] = {{9, 1, 1}, {2, 10, 3}, {3, 4, 11}};
    float B[M] = {10, 19, 0};
    float X[M] = {0, 0, 0};
    float *sol;
    iter = 2;

    for(i=0; i<iter; i++)
    {
        sol = gauss_seidal(A, B, X, n);

        for(j=0; j<n; j++)
        {
            X[j] = *(sol+j);
        }
    }

    for(i=0; i<n; i++)
    {
        printf("%f ", sol[i]);
    }

    return 0;
}
