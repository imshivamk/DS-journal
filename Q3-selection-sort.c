#include <stdio.h>
#include <stdlib.h>
int array[20], n;

void sort()
{
    int i, j, temp;
    for(i=0;i<n-1;i++)
    {
        for(j = i+1; j < n ; j++)
        {
            if(array[j] < array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
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