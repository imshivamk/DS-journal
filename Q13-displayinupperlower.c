// 13. Write a C program to display contents
// of a file in uppercase and lowercase
// letters.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    FILE *ptr;
    char filename[50];
    printf("enter the file to enter:\n");
    scanf("%s", &filename);

    // for this program to run, the file should already exist
    // in the same folder as the program 
    ptr = fopen(filename, "r");

    if(ptr==NULL) printf("there was an error when trying to open the file\n");
    else
    {
        char ch;
        printf("the file contents in uppercase casing:\n");
        while((ch=getc(ptr))!=EOF)
        {
            printf("%c", toupper(ch));
        }
        printf("\n");
        printf("the file contents in lowercase casing:\n");
        while((ch=getc(ptr))!=EOF)
        {
            printf("%c", tolower(ch));
        }

    }

    fclose(ptr);
    return 0;
}