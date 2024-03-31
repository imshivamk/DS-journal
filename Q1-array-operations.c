/*
1. Write C programs for the following
operations on Array.
(i) Creation (ii) insertion (iii) deletion (iv)
traversal
*/

#include <stdio.h>
#include <stdlib.h>

int array[50];
int n=0;

void create()
{
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("enter the arry elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Array created successfully!\n");
}

void insert()
{
    // 1 2 3 4 5
    // 1 2 6 3 4 5 i,e forward shifiting
    int p, x;
    printf("Enter the element to insert:\n");
    scanf("%d", &x);
    printf("Enter the position where to insert the element:\n");
    scanf("%d", &p);

    for (int i = n; i >= p - 1; i--)
    {
        array[i] = array[i - 1];
    }

    array[p - 1] = x;
    n++;
}

void deletion()
{
    int p;
    printf("enter the position of the element to delete:\n");
    scanf("%d", &p);

    // 1 2 3 4 backward shifitng
    // 1 3 4
    for(int i = p-1; i < n; i++)
    {
        array[i] = array[i+1];
    }
    n--;

}

void traversal()
{
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("1. create array\n2. insert an element\n3. delete an element\n4. traverse the array\n5. exit the program\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            deletion();
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}
