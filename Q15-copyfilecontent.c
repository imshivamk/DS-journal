// 15. Write a C program to copy the contents
// of one file to another file.

#include<stdio.h>
#include<stdlib.h>
const int max = 1000;
int main()
{
    FILE *source, *target; // source and target are the fiel pointers which point to the files
    char sourcefile[50], targetfile[50];

    printf("enter the source file-name:\n");
    scanf("%s", &sourcefile);
    printf("enter the target file-name:\n");
    scanf("%s", &targetfile);

    source = fopen(sourcefile, "r");
    target = fopen(targetfile, "w");

    if(source==NULL || target==NULL)
    {
        printf("error while opening the file");
    }
    else
    {
        char str[max];
        while (fgets(str, max, source)!=NULL)
        {
            fputs(str, target);
        }
        printf("the content from %s has been copied to %s\n", sourcefile, targetfile);

    }


    fclose(source);
    fclose(target);
    return 0;
}