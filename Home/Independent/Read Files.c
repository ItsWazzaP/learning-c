// I need this so I can calculate the arithmetic mean for my grades
// and what better to do than to program it in C
// This file's gonna be my learning journey, so expect a whole ton of comments
// I'll mostly be writing stuff so I can understand it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float grade_arithmetic_mean, grade, number_of_subjects = 0, grade_sum = 0;

    FILE *parse_file = fopen("Subjects.txt", "r"); // Needs to be a pointer variable. fopen() is file open
    char subjects[255]; // Buffer - holds 1 line of the text document at a time

    if (parse_file == NULL) // Checking if the file exists. If it doesn't, pointer returns NULL
    {
        printf("File doesn't exist!\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    else
    { // sizeof() something in bytes, 
        while(fgets(subjects, sizeof(subjects), parse_file) != NULL) // Have to move fgets() into the loop, since after it's finished it returns NULL
        {
            char *colon = strrchr(subjects, ':'); // Find the ':' and leave the grade (String Reverse Char Search). Searches for the last occurence of that char
            
            if (colon != NULL)
            {
                grade = atof(colon + 1); // The "+ 1" tells it to go for " [grade_number]". atof() is ASCII to float
                grade_sum += grade; // Adds the grade as soon as it's detected to the total sum
                number_of_subjects += 1; // Basically a line counter

                printf("Subject: %-35.*s Grade: %.0f\n", (int)(colon - subjects), subjects, grade);
                // colon_ptr - subjects --- length of subject name before ':'
                //        (int)         --- cast to int for printing
                //       subjects       --- pointer to a subject name
                //        grade         --- number after the colon
                //       %-35.*s        --- idk i found this it just makes it look like a table
            }
            else
            {
                printf("Missing colon (':')!");
            }

            //printf("%s", subjects);
        }
    }

    fclose(parse_file); // Close any file - FILE variable, no pointer here. fclose() is file close

    grade_arithmetic_mean = grade_sum / number_of_subjects;

    printf("\n\nYour grade's arithmetic mean is: %.2f\n\n", grade_arithmetic_mean);

    system("pause");

    return 0;
}

// This was enjoyable. I think I'm gonna make more programs like this