/*
Surface calculator with an option to select what geometric body to calculate the surface for
Why? Why not!
I'll learn how to use a bit of math.h and just have overall more confidence with C
Also learn how to play around with functions

I'm probably gonna switch my main language from C# to C 'cause of school, but C is also a good language. C# will have to wait unfortunately

THIS PROGRAM IS TO BE UPGRADED.

List of features I want:
1. Complex calculations, e.g. if we only know the diagonal of a square/rectangle and whatnot.
2. Every triangle calculations
3. GUI
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Use this so the .exe's Terminal window doesn't close after the program has finished

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
    double square_side, square_diameter, square_surface;
    int know_square_side;

    printf("\nDo you know your square's side or diameter?\n1 - Side\n2 - Diameter\n");
    scanf("%d", &know_square_side);

    switch (know_square_side)
    {
        case 1: // If Side
            printf("\nEnter your square's side: ");
            scanf("%lf", &square_side);
            break;
        case 2: // If Diameter
            printf("\nEnter your square's diameter: ");
            scanf("%lf", &square_diameter);
            square_side = square_diameter / sqrt(2);
            break;
        default:
            printf("You have entered an incorrect value!");
            break;
    }

    square_surface = pow(square_side, 2); // Raising square_side to the power of 2 (notes for myself in case I forget how it's read)
    printf("The surface of your square is %lf\n\n", square_surface);

    return 0;
}


////////////////////////////////////////////////////////


int Rectangle()
{
    double rectangle_base, rectangle_height, rectangle_diameter, rectangle_angle, rectangle_surface;
    int know_rectangle_side;

    printf("\nDo you know your square's sides or diameter & angle?\n1 - Sides\n2 - Diameter & Angle\n");
    scanf("%d", &know_rectangle_side);

    switch (know_rectangle_side)
    {
        case 1: // If Sides
            printf("Enter the base of your rectangle: ");
            scanf("%lf", &rectangle_base);
            printf("Enter the height of your rectangle: ");
            scanf("%lf", &rectangle_height);

            rectangle_surface = rectangle_base * rectangle_height;
            break;
        case 2: // If Diameter & Angle
            printf("Enter the diameter of your rectangle: ");
            scanf("%lf", &rectangle_diameter);
            printf("Enter the angle of your rectangle (degrees): ");
            scanf("%lf", &rectangle_angle);

            rectangle_angle = rectangle_angle * PI / 180; // Converting to radians

            rectangle_base = rectangle_diameter * cos(rectangle_angle);
            rectangle_height = rectangle_diameter * sin(rectangle_angle);

            rectangle_surface = rectangle_base * rectangle_height;
            break;
        default:
            printf("You have entered an incorrect value!");
            break;
    }

    printf("The surface of your rectangle is %lf\n\n", rectangle_surface);

    return 0;
}


////////////////////////////////////////////////////////


int Circle()
{
    // Won't ask for the diameter, since radius = diameter / 2. Simple enough
    double circle_radius, circle_surface;

    printf("Enter your circle's radius (r): ");
    scanf("%lf", &circle_radius);

    circle_surface = PI * pow(circle_radius, 2);

    printf("The surface of your circle is %lf\n\n", circle_surface);

    return 0;
}
////////////////////////////////////////////////////////
int Triangle()
{
    // TO-DO
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

    system("pause"); // Pauses the program so when you run the executable it doesn't exit immediately after it finishes
                     // Prints out the "Press any key to continue..." line

    return 0;
}