// 17. Write a program to read strings from a
// file and display them on screen.

#include<stdio.h>
#include<stdlib.h>

const int max = 1000;

int main()
{

    FILE *ptr;
    
    // for this program to run, the file should already exist
    // in the same folder as the program
    char filename[50];
    printf("enter the file to read:\n");
    scanf("%s", &filename);

    ptr = fopen(filename, "r");
    if(ptr==NULL)
    {
        printf("Error\n");
    }
    else
    {
        char str[max];
        while(fgets(str, max, ptr)!=NULL)
        {
            printf("%s\n", str);
        }
    }
    fclose(ptr);

    return 0;
}