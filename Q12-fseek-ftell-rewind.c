// 12. Write C programs to implement
// working of following Random access
// functions:
// fseek(), ftell() and rewind()

/*The fseek() function in C programming is used to move the
 file pointer associated with a file to a specific position.*/

/* ftell() is then used to retrieve the current position of the file pointer */

// rewind() to move the file pointer back to the beginning of the file.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[50];
    FILE *ptr;
    printf("enter a the file to create:\n");
    scanf("%s", &filename);

    ptr = fopen(filename, "w");
    if (ptr == NULL)
        printf("error while opening the file\n");
    else
    {
        char ch;
        printf("enter the file contents:\n(ctrl+Z to end)\n");
        while ((ch = getchar()) != EOF)
        {
            putc(ch, ptr);
        }
        fclose(ptr);
        printf("file written successfully\n");
    }


    // reading the file
    long posi;
    char ch;
    printf("enter the file to open:\n");
    scanf("%s", &filename);

    ptr = fopen(filename, "r");


    if (ptr == NULL)
        printf("error while opening the file\n");
    else
    {
        printf("\n\nContents after rewind:\n");

        while ((ch = fgetc(ptr)) != EOF)
        {
            printf("%c", ch);
        }
        
        // fseek takes 3 arrguments
        // 1. FILE pointer/ file stream
        // 2. long offset i.e the number of bytes to move a file pointer
        /* 3.int origin i.e the reference point for offset
                SEEK_SET = start
                SEEK_CUR = current
                SEEK_END = end of the file
        */
        fseek(ptr, 0, SEEK_END);
        printf("the pointer has moved to the end\n");
    }

    // current position of the pointer
    posi = ftell(ptr);
    printf("the size of the file:%ld\n", posi);


    // to read the file again from the starting, use rewind
    // rewind moves the pointer to the beining of the file

    rewind(ptr);
    if (ptr == NULL)
        printf("error while opening the file\n");
    else
    {
        printf("\n\nContents after rewind:\n");

        while ((ch = fgetc(ptr)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(ptr);

    return 0;
}