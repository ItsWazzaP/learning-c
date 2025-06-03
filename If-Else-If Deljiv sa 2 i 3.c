#include <stdio.h>

int main()
{
    int a;
    int modulo_2, modulo_3;

    printf("Unesite promenljivu A: ");
    scanf("%d", &a);

    modulo_2 = a % 2;
    modulo_3 = a % 3;

    if (modulo_2 == 0 && modulo_3 == 0)
    {
        printf("Broj A je deljiv i sa 2 i sa 3");
    }
    else if (modulo_2 == 0 && modulo_3 != 0)
    {
        printf("Broj A je deljiv samo sa 2");
    }
    else if (modulo_2 != 0 && modulo_3 == 0)
    {
        printf("Broj A je deljiv samo sa 3");
    }
    else
    {
        printf("Broj A nije deljiv ni sa 2 ni sa 3");
    }
    
    return 0;
}