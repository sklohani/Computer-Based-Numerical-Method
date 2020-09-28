/*
1.  P(x) = x^3 − 11*x^2 + 32*x – 22;  Initial approximations as p0 = 0.1, q0 = 0.1

2.  P(x) = x^3 − x – 3;   Initial approximations as p0 = 0.1, q0 = 0.1

3.  P(x) = x^4 − 3*x^3 + 3*x^2 − 3*x + 2;  Initial approximations as p0 = 0.1, q0 = 0.1
*/

#include <stdio.h>
#include <math.h>

float root_p(float p_k, float b_n, float b_n_1, float c_n_1, float c_n_2, float c_n_3)
{
    return p_k - ((b_n*c_n_3 - b_n_1*c_n_2)/(c_n_2*c_n_2 - c_n_3*(c_n_1-b_n_1)));
}

float root_q(float q_k, float b_n, float b_n_1, float c_n_1, float c_n_2, float c_n_3)
{
    return q_k - ((b_n_1*(c_n_1-b_n_1)-b_n*c_n_2)/(c_n_2*c_n_2 - c_n_3*(c_n_1-b_n_1)));
}

int main()
{
    int i, k;
    float p_k, p_k_Plus_1, q_k, q_k_Plus_1, a[5], b[5], c[5], b_n, b_n_1, c_n_1, c_n_2, c_n_3, err = 0.000005;

    for(i = 1; i<=3; i++)
    {
            if(i == 1)
            {
                p_k_Plus_1 = 0.1; q_k_Plus_1 = 0.1; a[0] = 1; a[1] = -11; a[2] = 32; a[3] = -22;
                k = 0;
                do
                {
                    p_k = p_k_Plus_1;
                    q_k = q_k_Plus_1;
                    k++;
                    b[0] = a[0];
                    b[1] = a[1]-p_k*b[0];
                    for(int j=2;j<4;j++)
                    {
                        b[j] = a[j] - p_k*b[j-1] - q_k*b[j-2];
                    }
                    c[0] = b[0];
                    c[1] = b[1]-p_k*c[0];
                    for(int j=2;j<3;j++)
                    {
                        c[j] = b[j] - p_k*c[j-1] - q_k*c[j-2];
                    }
                    b_n = b[3]; b_n_1 = b[2]; c_n_1 = c[2]; c_n_2 = c[1]; c_n_3 = c[0];

                    p_k_Plus_1 = root_p(p_k, b_n, b_n_1, c_n_1, c_n_2, c_n_3);
                    q_k_Plus_1 = root_q(q_k, b_n, b_n_1, c_n_1, c_n_2, c_n_3);
                }while(fabs(p_k - p_k_Plus_1) > err && fabs(q_k - q_k_Plus_1) > err);

                printf("p_k+1 : %.6f, q_k+1 : %.6f, iteration : %d\n", p_k_Plus_1, q_k_Plus_1, k);
            }
            else if(i == 2)
            {
                p_k_Plus_1 = 0.1; q_k_Plus_1 = 0.1; a[0] = 1; a[1] = 0; a[2] = -1; a[3] = -3;
                k = 0;
                do
                {
                    p_k = p_k_Plus_1;
                    q_k = q_k_Plus_1;
                    k++;
                    b[0] = a[0];
                    b[1] = a[1]-p_k*b[0];
                    for(int j=2;j<4;j++)
                    {
                        b[j] = a[j] - p_k*b[j-1] - q_k*b[j-2];
                    }
                    c[0] = b[0];
                    c[1] = b[1]-p_k*c[0];
                    for(int j=2;j<3;j++)
                    {
                        c[j] = b[j] - p_k*c[j-1] - q_k*c[j-2];
                    }
                    b_n = b[3]; b_n_1 = b[2]; c_n_1 = c[2]; c_n_2 = c[1]; c_n_3 = c[0];

                    p_k_Plus_1 = root_p(p_k, b_n, b_n_1, c_n_1, c_n_2, c_n_3);
                    q_k_Plus_1 = root_q(q_k, b_n, b_n_1, c_n_1, c_n_2, c_n_3);
                }while(fabs(p_k - p_k_Plus_1) > err && fabs(q_k - q_k_Plus_1) > err);

                printf("p_k+1 : %.6f, q_k+1 : %.6f, iteration : %d\n", p_k_Plus_1, q_k_Plus_1, k);
            }
            else if(i == 3)
            {
                p_k_Plus_1 = 0.1; q_k_Plus_1 = 0.1; a[0] = 1; a[1] = -3; a[2] = 3; a[3] = -3; a[4] = 2;
                k = 0;
                do
                {
                    p_k = p_k_Plus_1;
                    q_k = q_k_Plus_1;
                    k++;
                    b[0] = a[0];
                    b[1] = a[1]-p_k*b[0];
                    for(int j=2;j<5;j++)
                    {
                        b[j] = a[j] - p_k*b[j-1] - q_k*b[j-2];
                    }
                    c[0] = b[0];
                    c[1] = b[1]-p_k*c[0];
                    for(int j=2;j<4;j++)
                    {
                        c[j] = b[j] - p_k*c[j-1] - q_k*c[j-2];
                    }
                    b_n = b[4]; b_n_1 = b[3]; c_n_1 = c[3]; c_n_2 = c[2]; c_n_3 = c[1];

                    p_k_Plus_1 = root_p(p_k, b_n, b_n_1, c_n_1, c_n_2, c_n_3);
                    q_k_Plus_1 = root_q(q_k, b_n, b_n_1, c_n_1, c_n_2, c_n_3);
                }while(fabs(p_k - p_k_Plus_1) > err && fabs(q_k - q_k_Plus_1) > err);

                printf("p_k+1 : %.6f, q_k+1 : %.6f, iteration : %d\n", p_k_Plus_1, q_k_Plus_1, k);
            }
    }
    return 0;
}
