#include <stdio.h>

int main()
{
    float x, y, R;
    char zn;
    
    printf("Unesite float x ");
    scanf("%f", &x);
    
    printf("\nUnesite float y ");
    scanf("%f", &y);
    
    printf("\nUnesite char zn ");
    scanf("%s", &zn);
    
    switch (zn)
    {
        case '+':
         R = x + y;
         break;
        
        case '-':
         R = x - y;
         break;
        
        case '*':
         R = x * y;
         break;
        
        case '/':
         if (y == 0) {
             printf("Nije dozvoljeno deljenje nulom");
             //break;
         }
         else {
             R = x / y;
             printf("\n\nR = %f", R);
             //break;
         }
         break;
    }
    
    return 0;
}