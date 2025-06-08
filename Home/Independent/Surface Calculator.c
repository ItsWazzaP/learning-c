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
    int square_choice;

    printf("\nDo you know your square's side or diameter?\n1 - Side\n2 - Diameter\nEnter your choice: ");
    scanf("%d", &square_choice);

    switch (square_choice)
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
    int rectangle_choice;

    printf("\nDo you know your square's sides or diameter & angle?\n1 - Sides\n2 - Diameter & Angle\nEnter your choice: ");
    scanf("%d", &rectangle_choice);

    switch (rectangle_choice)
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

            rectangle_angle = rectangle_angle * (PI / 180); // Converting to radians

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
    /*
        Types of triangles and their surface (area) formulas:

        * By sides:

        - Scalene (0 equal sides)
            S = (base * height) / 2                // Any triangle if you know height

        - Isosceles (2 equal sides)
            S = (base * height) / 2                // Still requires perpendicular height

        - Equilateral (3 equal sides)
            S = (pow(side, 2) * sqrt(3)) / 4       // Only works for equilateral

        * By angles:

        - Acute (all angles < 90°)
            S = (base * height) / 2                // Same general rule applies

        - Right (1 angle = 90°)
            S = (side_a * side_b) / 2              // a and b are the two legs (not the hypotenuse)

        - Obtuse (1 angle > 90°)
            S = (base * height) / 2                // Height must be from the obtuse angle’s vertex

        * Trigonometric formulas:

         When you know two sides and the included angle (SAS):
            S = (side_a * side_b * sin(angle_c)) / 2         // angle_c is between sides a and b

        * Heron’s Formula (when you know all 3 sides):
            s = (side_a + side_b + hypotenuse) / 2                    // semi-perimeter
            S = sqrt(s * (s - side_a) * (s - side_b) * (s - hypotenuse))
    */
    double side, side_a, side_b, hypotenuse, base, angle_a, angle_b, angle_c, height, heron_s, triangle_surface;
    int triangle_choice, know_all_triangle_sides;
    printf("\nWhat is your triangle type?\n\nBy sides:\n1 - Scalene (0 equal sides)\n2 - Isosceles (2 equal sides)\n3 - Equilateral (3 equal sides)\nBy angles:\n4 - Acute (all angles < 90 degrees)\n5 - Right (1 angle = 90 degrees)\n6 - Obtuse (1 angle > 90 degrees)\nEnter your choice: ");
    scanf("%d", &triangle_choice);
    printf("Do you know all your triangle's sides?\n1 - Yes\n2 - No\n3 - Sides (a & b) and the angle between them (SAS)\nEnter your choice: ");
    scanf("%d", &know_all_triangle_sides);

    // There's probably a more efficient way of doing this rather than nesting switch statements (I<3Switch), and when I figure it out I'll update this
    switch (know_all_triangle_sides)
    {
        case 1: // Yes
            printf("Enter your first side (a): ");
            scanf("%lf", &side_a);
            printf("Enter your second side (b): ");
            scanf("%lf", &side_b);
            printf("Enter your hypotenuse (c): ");
            scanf("%lf", &hypotenuse);

            heron_s = (side_a + side_b + hypotenuse) / 2;
            triangle_surface = sqrt(heron_s * (heron_s - side_a) * (heron_s - side_b) * (heron_s - hypotenuse));

            printf("The surface of your triangle is %lf\n\n", triangle_surface);
            break;
        case 2: // No
            switch (triangle_choice)
            {
                case 1: // Scalene
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &height);

                    triangle_surface = (base * height) / 2;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;
                case 2: // Isosceles
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's (perpendicular) height: ");
                    scanf("%lf", &height);

                    triangle_surface = (base * height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;
                case 3: // Equilateral
                    printf("Enter your triangle's sides: ");
                    scanf("%lf", &side);

                    triangle_surface = (pow(side, 2) * sqrt(3)) / 4;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                /************** Here start the known angle type triangles **************/

                case 4: // Acute
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &height);

                    triangle_surface = (base * height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;
                case 5: // Right
                    printf("Enter your triangle's first side (a): ");
                    scanf("%lf", &side_a);
                    printf("Enter your triangle's second side (b): ");
                    scanf("%lf", &side_b);

                    triangle_surface = (side_a * side_b) / 2;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;
                case 6: // Obtuse
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &height);

                    triangle_surface = (base * height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;
                default:
                    printf("You entered a wrong value.\nThe values are listed above (1-6)");
                    break;
            }
            break;
        case 3: // Side a & b and the angle between them (SAS)
            printf("Enter your triangle's first side (a): ");
            scanf("%lf", &side_a);
            printf("Enter your triangle's second side (b): ");
            scanf("%lf", &side_b);
            printf("Enter your angle (between a & b): ");
            scanf("%lf", &angle_c);

            angle_c = angle_c * (PI / 180);
            triangle_surface = (side_a * side_b * sin(angle_c)) / 2;

            printf("The surface of your triangle is %lf\n\n", triangle_surface);
            break;
    }

    return 0;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int main()
{
    int body;

    printf("Please use the metric system instead of the imperial for measurements!\n\n");
    printf("1 - Square\n2 - Rectangle\n3 - Circle\n4 - Triangle\nEnter what type of body you wanna calculate the surface for: ");
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