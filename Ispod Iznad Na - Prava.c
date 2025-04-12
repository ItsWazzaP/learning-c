#include <stdio.h>

int main()
{
    int x1, y1, k, n;
    
    //////
    printf("Unesite koordinate tacke: \n");
    
    printf("x1 = ");
    scanf("%d", &x1);
    
    printf("y1 = ");
    scanf("%d", &y1);
    //////
    
    //////
    printf("\n\n");
    printf("Unesite koeficijente prave: \n");
    
    printf("k = ");
    scanf("%d", &k);
    
    printf("n = ");
    scanf("%d", &n);
    //////
    
    //////
    if (y1 > x1 * k + n)
    {
        printf("Tacka se nalazi IZNAD prave.");
    }
    else
    {
        if (y1 < x1 * k + n)
        {
            printf("Tacka se nalazi ISPOD prave.");
        }
        else
        {
            printf("Tacka se nalazi NA pravoj.");
        }
    }
    
    return 0;
}