#include <stdio.h>

int main()
{
    float number;
    printf("Unesi broj: ");
    scanf("%f", &number);

    if (number < 0)
    {
        printf("Broj je manji od nule");
    }
    else if (number == 0)
    {
        printf("Broj je nula");
    }
    else
    {
        printf("Broj je veci od nule");
    }
}