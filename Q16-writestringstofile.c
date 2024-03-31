// 16. Write a C program to receive strings
// from keyboard and write them to a file.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int max = 1000; // for maximum characters in fgets

int main()
{
    FILE *ptr;
    char filename[50];
    printf("to store the file by:\n");
    scanf("%s", &filename);

    ptr = fopen(filename, "w");

    if(ptr == NULL)
    {
        printf("error opening\n");
    }
    else
    {
        char str[max];
        printf("enter the strings:\n(enter `EXIT` to terminiate)\n");
        while(1)
        {
            fgets(str, max, stdin);
            if(strcmp(str, "EXIT\n")==0) break;
            else
            {
                fputs(str, ptr);
            }
        }
    }

    fclose(ptr);
    printf("strings written to the file successfully\n");
    return 0;
}