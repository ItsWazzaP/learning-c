/*
Surface calculator with an option to select what geometric body to calculate the surface for
Why? Why not!
I'll learn how to use a bit of math.h and just have overall more confidence with C
Also learn how to play around with functions

I'm probably gonna switch my main language from C# to C 'cause of school, but C is also a good language. C# will have to wait unfortunately

THIS PROGRAM IS TO BE UPGRADED.

List of features I want:
1. ✅ Complex calculations, e.g. if we only know the diagonal of a square/rectangle and whatnot
2. ✅ Every triangle calculations
3. GUI
4. ✅ Foolproof what I can
5. Learn how to use goto so the program doesn't exit immediately
6. Learn how to use structs to make variable stuff possibly less annoying
7. Figure out how to calculate surfaces of irregular N-gons (https://www.wikihow.com/Calculate-the-Area-of-a-Polygon)
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
double RadianConvert(double angle_deg) // Figured out how to use arguments and return
{                                      // Define a data type as argument. angle_deg gets replaced when the function gets called
    return angle_deg * (PI / 180);     // e.g. RadianConvert(square_angle) will use square_angle instead of angle_deg
}                                      // angle_deg is just a defined data type that's gonna be used

void Square() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double square_side, square_diameter, square_surface;
    int square_choice;

    printf("\nDo you know your square's side or diameter?\n1 - Side\n2 - Diameter\n\033[33mEnter your choice: \033[0m");
    scanf("%d", &square_choice);

    switch (square_choice)
    {
        case 1: // If Side
            printf("\n\033[33mEnter your square's side: \033[0m");
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
            printf("Enter your rectangle's base: ");
            scanf("%lf", &rectangle_base);
            printf("Enter your rectangle's height: ");
            scanf("%lf", &rectangle_height);
            /////
            if (rectangle_base <= 0 || rectangle_height <= 0) {
                ExitProgram(); }
            /////
            rectangle_surface = rectangle_base * rectangle_height;
            break;
        case 2: // If Diameter & Angle
            printf("Enter your rectangle's diameter: ");
            scanf("%lf", &rectangle_diameter);
            printf("Enter your rectangle's angle (degrees): ");
            scanf("%lf", &rectangle_angle);
            /////
            if (rectangle_diameter <= 0 || rectangle_angle <= 0 || rectangle_angle >= 90 || rectangle_angle <= 0) {
                ExitProgram(); }
            /////
            rectangle_angle = RadianConvert(rectangle_angle); // Converting to radians

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
    double triangle_side, triangle_side_a, triangle_side_b, triangle_hypotenuse, triangle_base, triangle_height, triangle_angle, triangle_heron_s, triangle_surface;
    int triangle_choice, know_all_triangle_sides;
    printf("\nWhat is your triangle type?\n\nBy sides:\n1 - Scalene (0 equal sides)\n2 - Isosceles (2 equal sides)\n3 - Equilateral (3 equal sides)\nBy angles:\n4 - Acute (all angles < 90 degrees)\n5 - Right (1 angle = 90 degrees)\n6 - Obtuse (1 angle > 90 degrees)\nEnter your choice: ");
    scanf("%d", &triangle_choice);
    printf("Do you know all your triangle's sides?\n1 - Yes\n2 - No\n3 - Sides (a & b) and the angle between them (SAS)\nEnter your choice: ");
    scanf("%d", &know_all_triangle_sides);

    // There's probably a more efficient way of doing this rather than nesting switch statements (I<3Switch), and when I figure it out I'll update this
    switch (know_all_triangle_sides)
    {
        case 1: // Yes
            printf("Enter your triangle's first side: ");
            scanf("%lf", &triangle_side_a);
            printf("Enter your triangle's second side: ");
            scanf("%lf", &triangle_side_b);
            printf("Enter your triangle's hypotenuse: ");
            scanf("%lf", &triangle_hypotenuse);
            /////
            if (triangle_side_a <= 0 || triangle_side_b <= 0 || triangle_hypotenuse <= 0) {
                ExitProgram(); }
            /////
            triangle_heron_s = (triangle_side_a + triangle_side_b + triangle_hypotenuse) / 2;
            triangle_surface = sqrt(triangle_heron_s * (triangle_heron_s - triangle_side_a) * (triangle_heron_s - triangle_side_b) * (triangle_heron_s - triangle_hypotenuse));

            printf("The surface of your triangle is %lf\n\n", triangle_surface);
            break;
        case 2: // No
            switch (triangle_choice)
            {
                case 1: // Scalene
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &triangle_base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &triangle_height);
                    /////
                    if (triangle_base <= 0 || triangle_height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (triangle_base * triangle_height) / 2;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 2: // Isosceles
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &triangle_base);
                    printf("Enter your triangle's (perpendicular) height: ");
                    scanf("%lf", &triangle_height);
                    /////
                    if (triangle_base <= 0 || triangle_height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (triangle_base * triangle_height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 3: // Equilateral
                    printf("Enter your triangle's sides: ");
                    scanf("%lf", &triangle_side);
                    /////
                    if (triangle_side <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (pow(triangle_side, 2) * sqrt(3)) / 4;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                /************** Here start the known angle type triangles **************/

                case 4: // Acute
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &triangle_base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &triangle_height);
                    /////
                    if (triangle_base <= 0 || triangle_height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (triangle_base * triangle_height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 5: // Right
                    printf("Enter your triangle's first side: ");
                    scanf("%lf", &triangle_side_a);
                    printf("Enter your triangle's second side: ");
                    scanf("%lf", &triangle_side_b);
                    /////
                    if (triangle_side_a <= 0 || triangle_side_b <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (triangle_side_a * triangle_side_b) / 2;

                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                case 6: // Obtuse
                    printf("Enter your triangle's base: ");
                    scanf("%lf", &triangle_base);
                    printf("Enter your triangle's height: ");
                    scanf("%lf", &triangle_height);
                    /////
                    if (triangle_base <= 0 || triangle_height <= 0) {
                        ExitProgram(); }
                    /////
                    triangle_surface = (triangle_base * triangle_height) / 2;
                    
                    printf("The surface of your triangle is %lf\n\n", triangle_surface);
                    break;

                default:
                    ExitProgram();
                    break;
            }
            break;
        case 3: // Side a & b and the angle between them (SAS)
            printf("Enter your triangle's first side: ");
            scanf("%lf", &triangle_side_a);
            printf("Enter your triangle's second side: ");
            scanf("%lf", &triangle_side_b);
            printf("Enter your triangle's angle (between a & b): ");
            scanf("%lf", &triangle_angle);
            /////
            if (triangle_side_a <= 0 || triangle_side_b <= 0 || triangle_angle <= 0 || triangle_angle >= 180) {
                ExitProgram(); }
            /////
            triangle_angle = RadianConvert(triangle_angle);
            triangle_surface = (triangle_side_a * triangle_side_b * sin(triangle_angle)) / 2;

            printf("The surface of your triangle is %lf\n\n", triangle_surface);
            break;
        default:
            ExitProgram();
            break;
    }
}
void Parallelogram() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double parallelogram_base, parallelogram_side, parallelogram_height, parallelogram_long_diagonal, parallelogram_short_diagonal, parallelogram_angle, parallelogram_surface;
    int parallelogram_choice;

    printf("\nWhat do you know about your parallelogram?\n1 - Base & height\n2 - Two diagonals and an angle\n3 - Base & side and an angle\nEnter your choice: ");
    scanf("%d", &parallelogram_choice);
    
    switch (parallelogram_choice)
    {
        case 1:
            printf("Enter your parallelogram's base: ");
            scanf("%lf", &parallelogram_base);
            printf("Enter your parallelogram's height: ");
            scanf("%lf", &parallelogram_height);
            /////
            if (parallelogram_base <= 0 || parallelogram_height <= 0) {
                ExitProgram(); }
            /////
            parallelogram_surface = parallelogram_base * parallelogram_height;

            printf("The surface of your parallelogram is %lf\n\n", parallelogram_surface);
            break;
        case 2:
            printf("Enter your parallelogram's long diagonal: ");
            scanf("%lf", &parallelogram_long_diagonal);
            printf("Enter your parallelogram's short diagonal: ");
            scanf("%lf", &parallelogram_short_diagonal);
            printf("Enter your parallelogram's angle (where the diagonals meet): ");
            scanf("%lf", &parallelogram_angle);
            /////
            if (parallelogram_long_diagonal <= 0 || parallelogram_short_diagonal <= 0 || parallelogram_angle >= 180 || parallelogram_angle <= 0) {
                ExitProgram(); }
            /////
            parallelogram_angle = RadianConvert(parallelogram_angle);
            parallelogram_surface = (parallelogram_long_diagonal * parallelogram_short_diagonal * sin(parallelogram_angle));

            printf("The surface of your parallelogram is %lf\n\n", parallelogram_surface);
            break;
        case 3:
            printf("Enter your parallelogram's base: ");
            scanf("%lf", &parallelogram_base);
            printf("Enter your parallelogram's side: ");
            scanf("%lf", &parallelogram_side);
            printf("Enter your parallelogram's angle (DAB or BCD): ");
            scanf("%lf", &parallelogram_angle);
            /////
            if (parallelogram_base <= 0 || parallelogram_side <= 0 || parallelogram_angle >= 180 || parallelogram_angle <= 0) {
                ExitProgram(); }
            /////
            parallelogram_angle = RadianConvert(parallelogram_angle);
            parallelogram_surface = parallelogram_base * parallelogram_side * sin(parallelogram_angle);

            printf("The surface of your parallelogram is %lf\n\n", parallelogram_surface);
            break;
        default:
            ExitProgram();
            break;
    }
}
void Rhombus() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double rhombus_side, rhombus_height, rhombus_first_diagonal, rhombus_second_diagonal, rhombus_angle, rhombus_surface;
    int rhombus_choice;

    printf("\nWhat do you know about your parallelogram?\n1 - Side & height\n2 - Diagonals\n3 - Side & angle\nEnter your choice: ");
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
            printf("Enter your rhombus' second diagonal: ");
            scanf("%lf", &rhombus_second_diagonal);
            /////
            if (rhombus_first_diagonal <= 0 || rhombus_second_diagonal <= 0) {
                ExitProgram(); }
            /////
            rhombus_surface = rhombus_first_diagonal * rhombus_second_diagonal;

            printf("The surface of your rhombus is %lf\n\n", rhombus_surface);
            break;
        case 3:
            printf("Enter your rhombus' side: ");
            scanf("%lf", &rhombus_side);
            printf("Enter your rhombus' angle: ");
            scanf("%lf", &rhombus_angle);
            /////
            if (rhombus_side <= 0 || rhombus_angle <= 0 || rhombus_angle >= 180) {
                ExitProgram(); }
            /////
            rhombus_angle = RadianConvert(rhombus_angle);
            rhombus_surface = rhombus_side * sin(rhombus_angle);

            printf("The surface of your rhombus is %lf\n\n", rhombus_surface);
            break;
        default:
            ExitProgram();
            break;
    }
}
void Kite() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double kite_side_a, kite_side_b, kite_first_diagonal, kite_second_diagonal, kite_angle, kite_surface;
    int kite_choice;

    printf("\nWhat do you know about your kite?\n1 - Sides & angle\n2 - Diagonals\nEnter your choice: ");
    scanf("%d", &kite_choice);

    switch (kite_choice)
    {
        case 1:
            printf("Enter your kite's first side: ");
            scanf("%lf", &kite_side_a);
            printf("Enter your kite's second side: ");
            scanf("%lf", &kite_side_b);
            printf("Enter your kite's angle (between sides a & b): ");
            scanf("%lf", &kite_angle);
            /////
            if (kite_side_a <= 0 || kite_side_b <= 0 || kite_angle <= 0 || kite_angle >= 180) {
                ExitProgram(); }
            /////
            kite_angle = RadianConvert(kite_angle);
            kite_surface = kite_side_a * kite_side_b * sin(kite_angle);

            printf("The surface of your kite is %lf\n\n", kite_surface);
            break;
        case 2:
            printf("Enter your kite's first diagonal: ");
            scanf("%lf", &kite_first_diagonal);
            printf("Enter your kite's second diagonal: ");
            scanf("%lf", &kite_second_diagonal);
            /////
            if (kite_first_diagonal <= 0 || kite_second_diagonal <= 0) {
                ExitProgram(); }
            /////
            kite_surface = (kite_first_diagonal * kite_second_diagonal) / 2;

            printf("The surface of your kite is %lf\n\n", kite_surface);
            break;
        default:
            ExitProgram();
            break;
    }
}
void Trapezoid() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double trapezoid_surface, trapezoid_base_a, trapezoid_base_b, trapezoid_height;
    int trapezoid_choice, know_bases_height;

    printf("\nWhat is your trapezoid type?\n1 - General\n2 - Scalene (0 equal legs)\n3 - Isosceles (2 equal legs)\n4 - Right (2 angles = 90 degrees)\nEnter your choice: ");
    scanf("%d", &trapezoid_choice);
    printf("Do you know your trapezoid's bases (a & b) and height?\n1 - Yes\n2 - No\nEnter your choice: ");
    scanf("&d", &know_bases_height);

    switch (know_bases_height)
    {
        case 1:
            printf("Enter your trapezoid's first base: ");
            scanf("%lf", &trapezoid_base_a);
            printf("Enter your trapezoid's second base: ");
            scanf("%lf", &trapezoid_base_b);
            printf("Enter your trapezoid's height: ");
            scanf("%lf", &trapezoid_height);
            /////
            if (trapezoid_base_a <= 0 || trapezoid_base_b <= 0 || trapezoid_height <= 0) {
                ExitProgram(); }
            /////
            trapezoid_surface = ((trapezoid_base_a + trapezoid_base_b) * trapezoid_height) / 2;

            printf("The surface of your trapezoid is %lf\n\n", trapezoid_surface);
        case 2:
            switch (trapezoid_choice)
            {
                case 2: // Scalene
                    break;
                case 3: // Isosceles
                    break;
                case 4: // Right
                    break;
                default:
                    ExitProgram();
                    break;
            }
        default:
            ExitProgram();
            break;
    }
}
void Pentagon() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double pentagon_surface;
    int pentagon_choice;

    printf("\nWhat do you know about your ?\n1 - Side & height\n2 - Diagonals\n3 - Side & angle\nEnter your choice: ");
    scanf("%d", &pentagon_choice);
}
void Hexagon() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double hexagon_surface;
    int hexagon_choice;

    printf("\nWhat do you know about your ?\n1 - Side & height\n2 - Diagonals\n3 - Side & angle\nEnter your choice: ");
    scanf("%d", &hexagon_choice);
}
void NGon() /*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/
{
    double ngon_surface;
    int ngon_choice;

    printf("\nWhat do you know about your ?\n1 - Side & height\n2 - Diagonals\n3 - Side & angle\nEnter your choice: ");
    scanf("%d", &ngon_choice);
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int main()
{
    int body;

    printf("Please use the metric system instead of the imperial for measurements!\nInput angles in degrees, not radians!\n\n");

    program_reset:
    /*
    Color codes (didn't even realize these existed loool):
        Red: \033[31m
        Green: \033[32m
        Blue: \033[34m
        Yellow: \033[33m
        Cyan: \033[36m
        Magenta: \033[35m
        White: \033[37m
        RESET COLORS: \033[0m
    */
        printf("1 - Square\n2 - Rectangle\n3 - Circle\n4 - Triangle\n5 - Parallelogram\n6 - Rhombus\n7 - Kite\n");
        printf("8 - Trapezoid\n9 - Pentagon\n10 - Hexagon\n11 - N-gon\n\n\033[31m0 - TERMINATE PROGRAM\033[0m\n");
        printf("\n\033[33mEnter what type of body you wanna calculate the surface for: \033[0m");
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
                Kite();
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
                printf("\n\n\n");
                if (body == 0)
                {
                    printf("You have successfully terminated the program.\n\n");
                    system("pause");
                    exit(EXIT_FAILURE);
                }
                goto program_reset;
                //ExitProgram();
                break;
        }
    //} while (done == 0);

    system("pause"); // Pauses the program so when you run the executable it doesn't exit immediately after it finishes
                     // Prints out the "Press any key to continue..." line
                     // No need for exit(EXIT_FAILURE) since the program isn't running in a loop I suppose
    return 0;
}