// 14. Write a C program to count characters(ch),
// spaces(" "), tabs(\t) and new lines(\n) in a file.

#include <stdio.h>
#include <stdlib.h>

int count = 0;
int main()
{
    int chars = 0, spaces = 0, tabs = 0, newline = 0;
    FILE *ptr;
    char filename[50];
    printf("enter the file to open:\n");
    scanf("%s", &filename);

    // for this program to run, the file should already exist
    // in the same folder as the program
    
    ptr = fopen(filename, "r");
    if (ptr == NULL)
    {
        printf("error while opening the file\n");
    }
    else
    {
        char ch;
        while((ch=getc(ptr))!=EOF)
        {
            count++;
            if(ch=='\n') newline++;
            else if(ch=='\t') tabs++;
            else if(ch==' ') spaces++;
            else chars++;
        }

        printf("the number of total characters in the file is:\n%d\n", count);
        printf("type wise distribution:\n");
        printf("the number of characters: %d\n", chars);
        printf("the number of spaces: %d\n", spaces);
        printf("the number of tabs: %d\n", tabs);
        printf("the number of new-line characters: %d\n", newline);

    }
    fclose(ptr);
    return 0;
}