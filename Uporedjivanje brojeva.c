#include <stdio.h>

int main()
{
    float x1, x2, x3;
    printf("Unesite prvi broj: \n");
    scanf("%f", &x1);
    
    printf("Unesite drugi broj: \n");
    scanf("%f", &x2);
    
    printf("Unesite treci broj: \n");
    scanf("%f", &x3);

    printf("%f \n", x1);
    printf("%f \n", x2);
    printf("%f \n", x3);
    
    if (x1 > x2)
    {
        if (x1 > x3)
            printf("Najveci broj je: %.2f", x1);
        else
            printf("Najveci broj je: %.2f", x3);
    }
    else
    {
        if (x2 > x3)
            printf("Najveci broj je: %.2f", x2);
        else
            printf("Najveci broj je: %.2f", x3);
    }
    
    return 0;
}