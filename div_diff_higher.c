#include <stdio.h>
#include <math.h>

int main()
{
    float x, x0, x1, x2, f0, dfx1, dfx2, dfx3, p_x;
    float df1[3];
    float df2[2];
    float df3;

    float arr[2][5] = {{0, 1, 3, 4}, {-12, 0, 12, 24}};

//Table for Divided Difference
    for(int i = 0; i<3; i++)
    {
        df1[i] = (arr[1][i+1] - arr[1][i])/(arr[0][i+1] - arr[0][i]);
    }
    for(int i = 0; i<2; i++)
    {
        df2[i] = (df1[i+1] - df1[i])/(arr[0][i+2] - arr[0][i]);
    }
    df3 = (df2[1] - df2[0])/(arr[0][3] - arr[0][0]);

    x = 0.2; x0 = arr[0][0]; x1 = arr[0][1]; x2 = arr[0][2];
    f0 = arr[1][0]; dfx1 = df1[0]; dfx2 = df2[0]; dfx3 = df3;

    p_x = f0 + (x - x0)*dfx1 + (x - x0)*(x - x1)*dfx2 + (x - x0)*(x - x1)*(x - x2)*dfx3;
    printf("f(%f) = %f", x, p_x);

    return 0;
}
