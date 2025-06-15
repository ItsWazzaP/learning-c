// I'll try to make a factorial calculator using a FOR-loop

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    long long int factorial;

    printf("Please note that any number above 20! will be displayed incorrectly due to the 64-bit Signed Integer Limit!!!\n\n");
    printf("Enter the number you want to calculate the factorial for: ");
    scanf("%d", &number);

    factorial = 1;

    if (number >= 0)
    {
        for (int i = 1; i <= number; i++) // Set i to 1. For each i that is less than number, increment i by 1
        {
            factorial *= i; // I tried to multiply this with "number", which messed it up. Just use the for loop "i"
        }
        printf("The factorial of %d is %lld\n\n\n", number, factorial);
    }
    else
    {
        printf("Entered number (%d) isn't valid\n\n\n", number);
    }

    system("pause");
}