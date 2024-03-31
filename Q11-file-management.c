// 11. Write C programs to implement
// working of following file management
// functions:
// fprintf (), fscanf(), getc(), putc (),
// getw(), putw ()

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *ptr1;

    // 1. fprintf - to write to a file
    ptr1 = fopen("first.txt", "w");
    if(ptr1==NULL)
    {
        printf("error opening the file\n");
    }
    else
    {
        fprintf(ptr1, "Helloeveryone\n");
    }
    fclose(ptr1);

    // 2. fscanf - to scan single line string, integer, char etc
    ptr1 = fopen("first.txt", "r");
    char str[20];
    fscanf(ptr1, "%s", &str);
    // printf - print to console
    printf("the content from first.txt :\n");
    printf("%s\n", str);
    fclose(ptr1);



    // 3. PUTC - write to the file, character by charcter
    FILE *ptr2 = fopen("second.txt", "w");
    if(ptr2==NULL)
    {
        printf("error opening the file\n");
    }
    else
    {
        char ch;
        printf("enter content for second.txt\n(ctrl+Z to terminate)\n");
        while((ch=getchar())!=EOF)
        {
            putc(ch, ptr2);
        }
    }
    fclose(ptr2);
    // 4. GETC - READ THE FILE, CHARATER BY CHARACTER
    ptr2 = fopen("second.txt", "r");
    if(ptr2==NULL)
    {
        printf("error opening the file\n");
    }
    else
    {
        char ch;
        while((ch=getc(ptr2))!=EOF)
        {
            // print the contents of the file to console
            printf("%c", ch);
        }
    }
    fclose(ptr2);





    // 5. PUTW - WRITE INTEGERS TO THE FILE
    FILE *ptr3 = fopen("third.txt", "w"); // returns file descripter
    int size, num, i;
    if(ptr3==NULL)
    {
        printf("error opening the file\n");
    }
    else
    {
        printf("how many numbers:\n");
        scanf("%d", &size);
        for(i=1;i<=size;i++)
        {
            scanf("%d", &num);
            putw(num, ptr3);
        }
        fclose(ptr3);
    }
    // 6. GETW
    fopen("third.txt", "r");
    if(ptr3==NULL)
    {
        printf("error opening the file\n");
    }
    else
    {
        for(int i=1;i<=size;i++)
        {
            num = getw(ptr3);
            printf("%d\n", num);
        }
        fclose(ptr3);
    }





    return 0;
}