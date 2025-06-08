// I'll try to make a factorial calculator using a FOR-loop

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, factorial;

    printf("Enter the number you want to calculate the factorial for: ");
    scanf("%d", &number);

    factorial = 1;

    if (number >= 0)
    {
        for (int i = 1; i <= number; i++) // Set i to 1. For each i that is less than number, increment i by 1
        {
            factorial *= i; // I tried to multiply this with "number", which messed it up. Just use the for loop "i"
        }
        printf("The factorial of %d is %d\n", number, factorial);
    }
    else
    {
        printf("Entered number (%d) isn't valid", number);
    }

    system("pause");
}