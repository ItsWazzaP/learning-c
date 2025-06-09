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
4. Foolproof what I can
5. Learn how to use goto so the program doesn't exit immediately
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
void ExitProgram() // Way too many places where this needed to be used, so I finally made it a separate function I can call
{
    printf("\nYou have entered an incorrect value! Exiting the program...\n\n");
    system("pause");
    exit(EXIT_FAILURE);
}

void Square() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
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
            /////
            if (square_side <= 0) {
                ExitProgram(); }
            /////
            break;
        case 2: // If Diameter
            printf("\nEnter your square's diameter: ");
            scanf("%lf", &square_diameter);
            /////
            if (square_diameter <= 0) {
                ExitProgram(); }
            /////
            square_side = square_diameter / sqrt(2);
            break;
        default:
            ExitProgram();
            break;
    }

    square_surface = pow(square_side, 2); // Raising square_side to the power of 2 (notes for myself in case I forget how it's read)
    printf("The surface of your square is %lf\n\n", square_surface);
}
void Rectangle() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
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
            /////
            if (rectangle_base <= 0 || rectangle_height <= 0) {
                ExitProgram(); }
            /////
            rectangle_surface = rectangle_base * rectangle_height;
            break;
        case 2: // If Diameter & Angle
            printf("Enter the diameter of your rectangle: ");
            scanf("%lf", &rectangle_diameter);
            printf("Enter the angle of your rectangle (degrees): ");
            scanf("%lf", &rectangle_angle);
            /////
            if (rectangle_diameter <= 0 || rectangle_angle <= 0 || rectangle_angle >= 90 || rectangle_angle <= 0) {
                ExitProgram(); }
            /////
            rectangle_angle = rectangle_angle * (PI / 180); // Converting to radians

            rectangle_base = rectangle_diameter * cos(rectangle_angle);
            rectangle_height = rectangle_diameter * sin(rectangle_angle);

            rectangle_surface = rectangle_base * rectangle_height;
            break;
        default:
            ExitProgram();
            break;
    }

    printf("The surface of your rectangle is %lf\n\n", rectangle_surface);
}
void Circle() /********************************************************/
{
    // Won't ask for the diameter, since radius = diameter / 2. Simple enough
    double circle_radius, circle_surface;

    printf("Enter your circle's radius (r): ");
    scanf("%lf", &circle_radius);
    /////
    if (circle_radius <= 0) {
        ExitProgram(); }
    /////
    circle_surface = PI * pow(circle_radius, 2);

    printf("The surface of your circle is %lf\n\n", circle_surface);
}
void Triangle() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    /*
        Types of triangles and their surface (area) formulas:

        * By sides:
        - Scalene (0 equal sides)
            triangle_surface = (base * height) / 2                          // Any triangle if you know height
        - Isosceles (2 equal sides)
            triangle_surface = (base * height) / 2                          // Still requires perpendicular height
        - Equilateral (3 equal sides)
            triangle_surface = (pow(side, 2) * sqrt(3)) / 4                 // Only works for equilateral

        * By angles:
        - Acute (all angles < 90°)
            triangle_surface = (base * height) / 2                          // Same general rule applies
        - Right (1 angle = 90°)
            triangle_surface = (side_a * side_b) / 2                        // a and b are the two legs (not the hypotenuse)
        - Obtuse (1 angle > 90°)
            triangle_surface = (base * height) / 2                          // Height must be from the obtuse angle’s vertex

        * Trigonometric formulas:
         When you know two sides and the included angle (SAS):
            triangle_surface = (side_a * side_b * sin(angle_c)) / 2         // angle_c is between sides a and b

        * Heron’s Formula (when you know all 3 sides):
            heron_s = (side_a + side_b + hypotenuse) / 2                    // semi-perimeter
            triangle_surface = sqrt(s * (s - side_a) * (s - side_b) * (s - hypotenuse))
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
            /////
            if (side_a <= 0 || side_b <= 0 || hypotenuse <= 0) {
                ExitProgram(); }
            /////
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
                    /////
                    if (base <= 0 || height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (base * height) / 2;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 2: // Isosceles
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's (perpendicular) height: ");
                    scanf("%lf", &height);
                    /////
                    if (base <= 0 || height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (base * height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 3: // Equilateral
                    printf("Enter your triangle's sides: ");
                    scanf("%lf", &side);
                    /////
                    if (side <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (pow(side, 2) * sqrt(3)) / 4;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                /************** Here start the known angle type triangles **************/

                case 4: // Acute
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &height);
                    /////
                    if (base <= 0 || height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (base * height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 5: // Right
                    printf("Enter your triangle's first side (a): ");
                    scanf("%lf", &side_a);
                    printf("Enter your triangle's second side (b): ");
                    scanf("%lf", &side_b);
                    /////
                    if (side_a <= 0 || side_b <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (side_a * side_b) / 2;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 6: // Obtuse
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &height);
                    /////
                    if (base <= 0 || height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (base * height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                default:
                    ExitProgram();
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
            /////
            if (side_a <= 0 || side_b <= 0 || angle_c <= 0 || angle_c >= 180) {
                ExitProgram(); }
            /////
            angle_c = angle_c * (PI / 180);
            triangle_surface = (side_a * side_b * sin(angle_c)) / 2;

            printf("The surface of your triangle is %lf\n\n", triangle_surface);
            break;
        default:
            ExitProgram();
            break;
    }
}
void Parallelogram() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double base, side, height, long_diagonal, short_diagonal, angle, parallelogram_surface;
    int parallelogram_choice;

    printf("\nWhat do you know about your parallelogram?\n1 - Base & height\n2 - Two diagonals and an angle\n3 - Base & side and an angle");
    scanf("%d", &parallelogram_choice);
    
    switch (parallelogram_choice)
    {
        case 1:
            printf("Enter your parallelogram's base: ");
            scanf("%lf", &base);
            printf("Enter your parallelogram's height: ");
            scanf("%lf", &height);
            /////
            if (base <= 0 || height <= 0) {
                ExitProgram(); }
            /////
            parallelogram_surface = base * height;

            printf("The surface of your parallelogram is %lf\n\n", parallelogram_surface);
            break;
        case 2:
            printf("Enter your parallelogram's long diagonal: ");
            scanf("%lf", &long_diagonal);
            printf("Enter your short diagonal: ");
            scanf("%lf", &short_diagonal);
            printf("Enter your angle (one of the angles where the diagonals meet): ");
            scanf("%lf", &angle);
            /////
            if (long_diagonal <= 0 || short_diagonal <= 0 || angle >= 180 || angle <= 0) {
                ExitProgram(); }
            /////
            angle = angle * (PI / 180);
            parallelogram_surface = (long_diagonal * short_diagonal * sin(angle));

            printf("The surface of your parallelogram is %lf\n\n", parallelogram_surface);
            break;
        case 3:
            printf("Enter your parallelogram's base: ");
            scanf("%lf", &base);
            printf("Enter your parallelogram's side: ");
            scanf("%lf", &side);
            printf("Enter your parallelogram's angle (DAB or BCD): ");
            scanf("%lf", &angle);
            /////
            if (base <= 0 || side <= 0 || angle >= 180 || angle <= 0) {
                ExitProgram(); }
            /////
            angle = angle * (PI / 180);
            parallelogram_surface = base * side * sin(angle);

            printf("The surface of your parallelogram is %lf\n\n", parallelogram_surface);
            break;
        default:
            ExitProgram();
            break;
    }
}
void Rhombus() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double rhombus_side, rhombus_height, rhombus_first_diagonal, rhombus_second_diagonal, angle, rhombus_surface;
    int rhombus_choice;

    printf("\nWhat do you know about your parallelogram?\n1 - Side & height\n2 - Diagonals\n3 - Side & angle");
    scanf("%d", &rhombus_choice);

    switch (rhombus_choice)
    {
        case 1:
            printf("Enter your rhombus' side: ");
            scanf("%lf", &rhombus_side);
            printf("Enter your rhombus' height: ");
            scanf("%lf", &rhombus_height);
            /////
            if (rhombus_side <= 0 || rhombus_height <= 0) {
                ExitProgram(); }
            /////
            rhombus_surface = rhombus_side * rhombus_height;

            printf("The surface of your rhombus is %lf\n\n", rhombus_surface);
            break;
        case 2:
            printf("Enter your rhombus' first diagonal: ");
            scanf("%lf", &rhombus_first_diagonal);
            printf("Enter your rhombus' first diagonal: ");
            scanf("%lf", &rhombus_second_diagonal);
            break;
        case 3:
            break;
        default:
            ExitProgram();
            break;
    }
}
void Deltoid() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double side_a, side_b, deltoid_surface;
}
void Trapezoid()
{
    double trapezoid_surface;
}
void Pentagon() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double pentagon_surface;
}
void Hexagon() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double hexagon_surface;
}
void NGon() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double ngon_surface;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int main()
{
    int body;

    printf("Please use the metric system instead of the imperial for measurements!\nInput angles in degrees, not radians!\n\n");
    printf("1 - Square\n2 - Rectangle\n3 - Circle\n4 - Triangle\n5 - Parallelogram\n6 - Rhombus\n7 - Deltoid\n8 - Pentagon\n9 - Hexagon\n10 - N-gon");
    printf("\nEnter what type of body you wanna calculate the surface for: ");
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
        case 5:
            Parallelogram();
            break;
        case 6:
            Rhombus();
            break;
        case 7:
            Deltoid();
            break;
        case 8:
            Trapezoid();
            break;
        case 9:
            Pentagon();
            break;
        case 10:
            Hexagon();
            break;
        case 11:
            NGon();
            break;
        default:
            ExitProgram();
            break;        
    }

    system("pause"); // Pauses the program so when you run the executable it doesn't exit immediately after it finishes
                     // Prints out the "Press any key to continue..." line
                     // No need for exit(EXIT_FAILURE) since the program isn't running in a loop I suppose
    return 0;
}