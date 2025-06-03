#include <stdio.h>

int main()
{
    int a;
    int modulo;

    printf("Unesite promenljivu A: ");
    scanf("%d", &a);

    modulo = a % 2;

    if (modulo == 0)
    {
        printf("Broj A je paran");
    }
    else
    {
        printf("Broj A je neparan");
    }
    return 0;
}