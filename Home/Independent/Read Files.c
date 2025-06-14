// I need this so I can calculate the arithmetic mean for my grades
// and what better to do than to program it in C
// This file's gonna be my learning journey, so expect a whole ton of comments
// I'll mostly be writing stuff so I can understand it

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *parse_file = fopen("Subjects.txt", "r"); // Needs to be a pointer variable
    char subjects[255]; // Buffer - holds 1 line of the text document at a time. Set to 30 bytes as a minimum for this case

    if (parse_file == NULL) // Checking if the file exists. If it doesn't, pointer returns NULL
    {
        printf("File doesn't exist!\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    else
    {
        while(fgets(subjects, 255, parse_file) != NULL) // Have to move fgets() into the loop, since after it's finished it returns NULL
        {
            //fgets(subjects, 30, parse_file); // Read a single file 
            printf("%s", subjects);
        }
    }

    fclose(parse_file); // Close any file - FILE variable, no pointer here
    system("pause");

    return 0;
}