// Surface calculator with an option to select what geometric body to calculate the surface for
// Why? Why not!
// I'll learn how to use a bit of math.h and just have overall more confidence with C
// I'm probably gonna switch my main language from C# to C 'cause of school, but C is also a good language. C# will have to wait unfortunately

// THIS PROGRAM IS TO BE UPGRADED.
/*
List of features I want:
1. Complex calculations, e.g. if we only know the diagonal of a square/rectangle and whatnot.
2. GUI
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/********************************
REMINDERS:
%d - int
%f - float
%lf - double (long float)
%c - char
%s - string (array of characters)
********************************/

int Square()
{
    double square_side, square_surface;

    printf("Enter your square's side: ");
    scanf("%lf", &square_side);

    square_surface = pow(square_side, 2);

    printf("The surface of your square is %lf", square_surface);

    return 0;
}
////////////////////////////////////////////////////////
int Rectangle()
{
    double rectangle_side_one, rectangle_side_two, rectangle_surface;

    printf("Enter the first side of your rectangle: ");
    scanf("%lf", &rectangle_side_one);
    printf("Enter the second side of your rectangle: ");
    scanf("%lf", &rectangle_side_two);

    rectangle_surface = rectangle_side_one * rectangle_side_two;

    printf("The surface of your rectangle is %lf", rectangle_surface);
}
////////////////////////////////////////////////////////
int Circle()
{
    double circle_radius, circle_surface;

    printf("Enter your circle's radius (r): ");
    scanf("%lf", &circle_radius);

    circle_surface = PI * pow(circle_radius, 2);

    printf("The surface of your circle is %lf", circle_surface);

    return 0;
}
////////////////////////////////////////////////////////
int Triangle()
{
    return 0;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int main()
{
    int body;

    printf("1. Square\n2. Rectangle\n3. Circle\n4. Triangle\nEnter what type of body you wanna calculate the surface for: ");
    scanf("%d", &body);

    switch (body)
    {
        case 1:
            Square();
            break;
        case 2:
            Rectangle();
            break;
        case 3:
            Circle();
            break;
        case 4:
            Triangle();
            break;
        default:
            printf("You entered a wrong value.\nThe values are listed above (1-4)");
            break;        
    }

    return 0;
}