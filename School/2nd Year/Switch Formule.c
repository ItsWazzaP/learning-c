#include <stdio.h>

int main()
{
    int k;
    float x, y;
    
    printf("Unesite float x ");
    scanf("%f", &x);
    
    printf("\nUnesite integer k ");
    scanf("%d", &k);
    
    switch (k)
    {
        case 0:
         y = x + 1;
         break;
    
        case 1:
         y = x + 2;
         break;
    
        case 2:
        case 3:
        case 4:
         y = x + 3;
         break;
    
        default:
         y = x + 4;
         break;
    }
    printf("%f", y);
    
    return 0;
}