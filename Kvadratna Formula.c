#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float x1, x2, D;
    
    printf("Unesite koeficijenat a: ");
    scanf("%f", &a);
    
    printf("Unesite koeficijenat b: ");
    scanf("%f", &b);
    
    printf("Unesite koeficijenat c: ");
    scanf("%f", &c);
    
    D = pow(b,2) - 4 * a * c; //b^(2)
    
    if (D > 0)
    {
        x1 = ((-1) * b + sqrt(D)) / (2 * a);
        x2 = ((-1) * b - sqrt(D)) / (2 * a);
        printf("Resenja jednacine su: \nx1 = %0.2f \nx2 = %0.2f", x1, x2);
    }
    else if (D == 0)
    {
        x1 = x2 = ((-1) * b) / (2 * a);
        printf("Resenje jednacine je realno: \nx1 = x2 = %0.2f", x1);
    }
    else
    {
        printf("Resenja jednacine nisu realna!");
    }
    printf("\n");
}
