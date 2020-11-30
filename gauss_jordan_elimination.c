#include <stdio.h>
#include <math.h>

void gauss_jordan_elimination(float a[3][3], float b[3])
{
    int i, j;
    float I[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    float ai[3][6], x[3], temp, temp2;

// Forming Argument matrix of Matrix A and I.
    for(i=0; i<3; i++)
    {
        for(j=0; j<6; j++)
        {
            if(j<3)
            {
                ai[i][j] = a[i][j];
            }
            else
            {
                ai[i][j] = I[i][j-3];
            }
        }
    }

// Finding Matrix A inverse by Gauss Jordan elimination method.
    temp = ai[0][0];
    for(j=0; j<6; j++)
    {
        ai[0][j] = ai[0][j]/temp;
    }

    temp = ai[1][0];
    temp2 = ai[2][0];
    for(j=0; j<6; j++)
    {
        ai[1][j] = ai[1][j] - temp*ai[0][j];
        ai[2][j] = ai[2][j] - temp2*ai[0][j];
    }

    temp = ai[1][1];
    for(j=0; j<6; j++)
    {
        ai[1][j] = ai[1][j]/temp;
    }

    temp = ai[0][1];
    temp2 = ai[2][1];
    for(j=0; j<6; j++)
    {
        ai[0][j] = ai[0][j] - temp*ai[1][j];
        ai[2][j] = ai[2][j] - temp2*ai[1][j];
    }

    temp = ai[2][2];
    for(j=0; j<6; j++)
    {
        ai[2][j] = ai[2][j]/temp;
    }

    temp = ai[0][2];
    temp2 = ai[1][2];
    for(j=0; j<6; j++)
    {
        ai[0][j] = ai[0][j] - temp*ai[2][j];
        ai[1][j] = ai[1][j] - temp2*ai[2][j];
    }

// Finding roots by matrix multiplication of A inverse and B.
    for(i=0; i<3; i++)
    {
        x[i] = 0;
        for(j=0; j<3; j++)
        {
            temp = ai[i][j+3]*b[j];
            x[i] = x[i] + temp;
        }
    }

// Printing the roots.
    for(i=0; i<3; i++)
    {
        printf("x%d = %f\n", i+1, x[i]);
    }
}

int main()
{
    float a1_arr[3][3] = {{1, 3, -5}, {3, 11, -9}, {-1, 1, 6}}, b1_arr[3] = {2, 4, 5};
    float a2_arr[3][3] = {{1, 1, 1}, {2, 3, 5}, {4, 0, 5}}, b2_arr[3] = {5, 8, 2};
    float a3_arr[3][3] = {{1, 2, -3}, {6, 3, 9}, {7, 17, -19}}, b3_arr[3] = {2, 6, 13};

// Linear Equation 1.
    printf("Solution for system of Linear Equation 1.\n");
    gauss_jordan_elimination(a1_arr, b1_arr);

// Linear Equation 2.
    printf("\nSolution for system of Linear Equation 2.\n");
    gauss_jordan_elimination(a2_arr, b2_arr);

// Linear Equation 3.
    printf("\nSolution for system of Linear Equation 3.\n");
    gauss_jordan_elimination(a3_arr, b3_arr);

    return 0;
}
