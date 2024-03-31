// 2. Write C programs for implementing the
// following searching techniques.
// 1) Linear search
// 2) Binary search

#include <stdio.h>
int array[20], n;

void create()
{
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

int linearsearch(int sk)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == sk)
        {
            count++;
            printf("element found at index %d\n", i);
        }
    }

    if (count == 0)
    {
        printf("Element not found in the array!!!\n");
    }
    else
    {
        printf("Element found %d times in the array!\n", count);
    }
}

int main()
{
    create();

    int sk;
    printf("Enter the search key:\n");
    scanf("%d", &sk);

    linearsearch(sk);

    return 0;
}