#include <stdio.h>
#include <stdlib.h>
int array[20], n;

void sort()
{
    int i, j, temp;
    for(i=1;i<n;i++)
    {
       temp = array[i];
       for(j=i; j>0 && array[j-1]>temp; j--)
       {
            array[j] = array[j-1]; // move the element by one position
       }
       // after j--, where j reduces by one
       array[j] = temp;
    }
}



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
    create();
    sort();
    traversal();
    return 0;
}
