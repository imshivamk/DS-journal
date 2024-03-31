
// 1) Binary search

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

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
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int binarysearch(int start, int end, int sk)
{
    sort();

    int mid = start+end/2;

    if(start>end)
    {
        return -1;
    }
    else if(array[mid]==sk)
    {
        return mid;
    }
    else if(array[mid] > sk)
    {
        end = mid - 1;
        binarysearch(start, end, sk);
    }
    else
    {
        start = mid + 1;
        binarysearch(start, end, sk);
    }

}

int main()
{
    create();

    int start=0, end=n-1;
    int sk;
    printf("Enter the search key:\n");
    scanf("%d", &sk);

    if(binarysearch(start, end, sk) == -1)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element found at index %d", binarysearch(start, end, sk));
    }


    return 0;
}