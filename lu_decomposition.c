#include <stdio.h>
#include <math.h>

void lu_decom(float a[3][3], float b[3], int n)
{
    int i, j, k;
    float l[3][3], u[3][3], z[3], x[3];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i<j)
                l[i][j] = 0;
            else
            {
                l[i][j] = a[i][j];
                for(k=0; k<j; k++)
                {
                    l[i][j] = l[i][j] - l[i][k]*u[k][j];
                }
            }
        }

        for(j=0; j<n; j++)
        {
            if(i>j)
                u[i][j] = 0;
            else if(i == j)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j];
                for(k=0; k<i; k++)
                {
                    u[i][j] = u[i][j] - l[i][k]*u[k][j];
                }
                u[i][j] /= l[i][i];
            }
        }
    }

    for(i=0; i<n; i++)
    {
        z[i] = b[i];
        for(j=0; j<i; j++)
        {
            z[i] -= l[i][j]*z[j];
        }
        z[i] /= l[i][i];
    }

    for(i=n-1; i>=0; i--)
    {
        x[i] = z[i];
        for(j=i+1; j<n; j++)
        {
            x[i] -= u[i][j]*x[j];
        }
    }

    for(i=0; i<3; i++)
    {
        printf("x%d = %f\n", i+1, x[i]);
    }
}

int main()
{
    int n;
    float a1_arr[3][3] = {{1, 2, 4}, {3, 8, 14}, {2, 6, 13}}, b1_arr[3] = {3, 13, 4};
    float a2_arr[3][3] = {{1, 6, 2}, {-1, -3, -1}, {2, 12, 5}}, b2_arr[3] = {9, 17, -4};
    float a3_arr[3][3] = {{25, 5, 1}, {64, 8, 1}, {144, 12, 1}}, b3_arr[3] = {106.8, 177.2, 279.2};

// Linear Equation 1.
    printf("Solution for system of Linear Equation 1.\n");
    n = sizeof(b1_arr)/sizeof(b1_arr[0]);
    lu_decom(a1_arr, b1_arr, n);

// Linear Equation 2.
    printf("\nSolution for system of Linear Equation 2.\n");
    n = sizeof(b2_arr)/sizeof(b2_arr[0]);
    lu_decom(a2_arr, b2_arr, n);

// Linear Equation 3.
    printf("\nSolution for system of Linear Equation 3.\n");
    n = sizeof(b3_arr)/sizeof(b3_arr[0]);
    lu_decom(a3_arr, b3_arr, n);

    return 0;
}
