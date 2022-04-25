#include <stdio.h>
int i, j;
float det(float arr[3][3]);
void feed(float arr[3][3], float array[3][4], int a);
int main()
{
    float x, y, z, dx, dy, dz, d;
    float arr[3][3], array[3][4];
    printf("enter the coff. of all 3 equation in following formate\n\
    3x+5y+6z=4 then enter 3 5 6 -4 .\npress enter then coff of next equation\n");
    for (i = 0; i < 3; i++)
        scanf("%f%f%f%f", &array[i][0], &array[i][1], &array[i][2], &array[i][3]);
    // fedding values to arr for determinant of d
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            arr[i][j] = array[i][j];
    d = det(arr);
    // printf("%f",d);
    if (d) // if non zero solution exist
    {
        feed(arr, array, 0);
        dx = det(arr);
        feed(arr, array, 1);
        dy = det(arr);
        feed(arr, array, 2);
        dz = det(arr);
        x = dx / d;
        y = dy / d;
        z = dz / d;
        printf("The system of equation have unique solution\n");
        printf("The solution of system of equation is:\nx=%f\ty=%f\tz=%f\n", x, y, z);
    }
    else
    {
        feed(arr, array, 0);
        dx = det(arr);
        feed(arr, array, 1);
        dy = det(arr);
        feed(arr, array, 2);
        dz = det(arr);
        if (dx == dy == dz == 0)
        {
            printf("The system of equation have infinitly many solutions\n");
        }
        else
            printf("The system of equation have No solution\n");
    }
}
float det(float arr[3][3])
{
    float D = 0;
    D += arr[0][0] * (arr[1][1] * arr[2][2] - arr[2][1] * arr[1][2]);
    D -= arr[0][1] * (arr[1][0] * arr[2][2] - arr[2][0] * arr[1][2]);
    D += arr[0][2] * (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1]);
    return D;
}
void feed(float arr[3][3], float array[3][4], int a)
{
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
        {
            if (j == a)
            {
                arr[i][j] = array[i][3];
            }
            else
                arr[i][j] = array[i][j];
        }
}
