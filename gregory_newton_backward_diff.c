#include <stdio.h>
#include <math.h>

float backward(float u, float f_n, float d_fn, float d2_fn, float d3_fn, float d4_fn)
{
    float p_x = f_n + u*d_fn + (u*(u+1)/2)*d2_fn + (u*(u+1)*(u+2)/(3*2))*d3_fn + (u*(u+1)*(u+2)*(u+3)/(4*3*2))*d4_fn;

    return p_x;
}

int main()
{
    float x, x_n, d_fn, d2_fn, d3_fn, d4_fn, d5_fn, d6_fn, f_n, h, u, p_x;
    int i, j;
    float values1[2][5] = {{0.10, 0.15, 0.20, 0.25, 0.30}, {0.1003, 0.1511, 0.2027, 0.2553, 0.3093}};
    float d_f[4];
    float d2_f[3];
    float d3_f[2];

    //Difference Table
    for(i=1; i<=4; i++)
    {
        d_f[i-1] = values1[1][i] - values1[1][i-1];
    }
    for(i=1; i<=3; i++)
    {
        d2_f[i-1] = d_f[i] - d_f[i-1];
    }
    for(i=1;i<=2;i++)
    {
        d3_f[i-1] = d2_f[i] - d2_f[i-1];
    }
    d4_fn = d3_f[1] - d3_f[0];

    //Printing Difference Table
    for(i=0; i<4; i++)
    {
        printf("%f ", d_f[i]);
        if(i<3)
            printf("%f ", d2_f[i]);
        if(i<2)
            printf("%f ", d3_f[i]);
        if(i<1)
            printf("%f ", d4_fn);
        printf("\n");
    }

    //Function value at x = 0.26
    x = 0.26; x_n = values1[0][4]; f_n = values1[1][4];
    h = values1[0][1] - values1[0][0];
    u = (x - x_n)/h;
    d_fn = d_f[3]; d2_fn = d2_f[2]; d3_fn = d3_f[1];


    p_x = backward(u, f_n, d_fn, d2_fn, d3_fn, d4_fn);

    printf("f(%f) = %f\n", x, p_x);

    return 0;
}
