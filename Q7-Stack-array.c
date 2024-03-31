#include<stdio.h>
#include<stdlib.h>

int array[10];
int size = sizeof(array)/sizeof(array[0]);


int top = -1; // t is TOP


void push()
{
    top++;
    printf("Enter value tp insert:\n");
    scanf("%d", &array[top]);
}

void pop()
{
    top--;
}

void peek()
{
    printf("The top: %d\n", array[top]);
}

void display()
{
    printf("the list is:\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d\n", array[i]);
    }
}
void isempty()
{
    if(top==-1)
    {
        printf("empty!\n");
    }
    else
    {
        printf("Not empty!\n");
    }
}
void isfull()
{
    if(top>=size)
    {
        printf("FULL!\n");
    }
    else
    {
        printf("not full!\n");
    }
}

int main()
{   int ch;
    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.display\n5.isempty\n6.isfull\n7.exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            isempty();
            break;
            case 6:
            isfull();
            break;
            case 7:
            exit(0);
            default:
            printf("inavlid input!");
        }

    }
    return 0;
}