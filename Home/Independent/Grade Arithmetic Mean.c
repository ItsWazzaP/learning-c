// I wanna make a program that reads a text file with all the subjects and grades, so I don't have to retype subjects each time
// This program works, but I value MODULARITY in my programs. Let me be and stop spying on me

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float number_of_subjects, subject_grade, subject_grade_sum = 0;
    float subject_grade_mean;
    char subject_name[15];
    printf("Don't be a smartass and enter whole numbers here :}\n");
    printf("Enter the number of subjects you have: ");
    scanf("%f", &number_of_subjects);

    if (number_of_subjects >= 1)
    {
        for (int i = 1; i <= number_of_subjects; i++)
        {
            printf("\nEnter your subject: ");
            scanf("%s", &subject_name);

            printf("Enter your %s grade: ", subject_name);
            scanf("%f", &subject_grade);
            subject_grade_sum += subject_grade;
        }
        subject_grade_mean = subject_grade_sum / number_of_subjects;
        printf("\nYour subject grade's arithmetic mean is: %.2f", subject_grade_mean); // %.2f rounds the float to 2 decimals - don't forget that
    }
    else
    {
        printf("\nYou have entered an invalid number!\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    printf("\n\n"); // Too sleepy to figure out where to put it, and this'll do. Sybau
    system("pause");
}