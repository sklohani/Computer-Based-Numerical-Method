/*
1.  P(x) = x^3 – x^2 – x + 1 = 0; Initial approximation p0 = 0.5

2.  P(x) = x^4 − 3*x^3 + 3*x^2 − 3*x + 2; Initial approximation p0 = 0.5

3.  P(x) = x^3 − x − 4; Initial approximation p0 = 1.5
*/

#include <stdio.h>
#include <math.h>

float root(float p_k, float b_n, float c_n_1)
{
    return p_k - b_n/c_n_1;
}

int main()
{
    int i, k;
    float p_k, p_k_Plus_1, a[5], b[5], c[5], b_n, c_n_1, err = 0.000005;

    for(i = 1; i<=3; i++)
    {
            if(i == 1)
            {
                p_k_Plus_1 = 0.5; a[0] = 1; a[1] = -1; a[2] = -1; a[3] = 1;
                k = 0;
                do
                {
                    p_k = p_k_Plus_1;
                    k++;
                    b[0] = a[0];
                    for(int i=1;i<4;i++)
                    {
                        b[i] = a[i] + p_k*b[i-1];
                    }
                    c[0] = b[0];
                    for(int i=1;i<3;i++)
                    {
                        c[i] = b[i] + p_k*c[i-1];
                    }
                    b_n = b[3];
                    c_n_1 = c[2];

                    p_k_Plus_1 = root(p_k, b_n, c_n_1);
                }while(fabs(p_k - p_k_Plus_1) > err);

                printf("p_k+1 : %.6f, iteration : %d\n", p_k_Plus_1, k);

            }
            else if(i == 2)
            {
                p_k = 0.5; a[0] = 1; a[1] = -3; a[2] = 3; a[3] = -3; a[4] = 2;
                k = 0;
                do
                {
                    p_k = p_k_Plus_1;
                    k++;
                    b[0] = a[0];
                    for(int i=1;i<5;i++)
                    {
                        b[i] = a[i] + p_k*b[i-1];
                    }
                    c[0] = b[0];
                    for(int i=1;i<4;i++)
                    {
                        c[i] = b[i] + p_k*c[i-1];
                    }
                    b_n = b[4];
                    c_n_1 = c[3];

                    p_k_Plus_1 = root(p_k, b_n, c_n_1);
                }while(fabs(p_k - p_k_Plus_1) > err);

                printf("p_k+1 : %.6f, iteration : %d\n", p_k_Plus_1, k);
            }
            else if(i == 3)
            {
                p_k = 1.5; a[0] = 1; a[1] = 0; a[2] = -1; a[3] = -4;
                k = 0;
                do
                {
                    p_k = p_k_Plus_1;
                    k++;
                    b[0] = a[0];
                    for(int i=1;i<4;i++)
                    {
                        b[i] = a[i] + p_k*b[i-1];
                    }
                    c[0] = b[0];
                    for(int i=1;i<3;i++)
                    {
                        c[i] = b[i] + p_k*c[i-1];
                    }
                    b_n = b[3];
                    c_n_1 = c[2];

                    p_k_Plus_1 = root(p_k, b_n, c_n_1);
                }while(fabs(p_k - p_k_Plus_1) > err);

                printf("p_k+1 : %.6f, iteration : %d\n", p_k_Plus_1, k);
            }
    }
    return 0;
}
