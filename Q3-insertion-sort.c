#include<stdio.h>
#include<stdlib.h>
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
void traversal()
{
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort()
{
    int i,j, temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    create();
    sort();
    traversal();
    return 0;
}