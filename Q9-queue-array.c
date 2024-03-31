#include <stdio.h>
#include <stdlib.h>

int array[10];

int size = sizeof(array) / sizeof(array[0]);

int front = -1;
int rear = -1;
int count = 0;

void enqueue()
{
    rear++;
    printf("Enter the eleemnt to insert:\n");
    scanf("%d", &array[rear]);

    if (front == -1)
    {
        front++;
    }
}
void dequeue()
{

    front++; // 1 2 3 4

    if (front > rear)
    {
        printf("queue is empty!\n");
        front = -1;
        rear = -1;
    }

}
void display()
{
    if (rear == -1)
    {
        printf("queue is empty!\n");
    }
    else
    {
        printf("the queue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d, ", array[i]);
        }
    }

    // for(int i=0;i<=rear;i++)
    // {
    //     printf("%d, ", array[i]);
    // }
    printf("\n");
}
void isempty()
{
    if(rear==-1)
    {
        printf("queue is empty!\n");
    }
    else
    {
        printf("Queue is not empty!\n");

    }
}

void isfull()
{
    if(rear>=size)
    {
        printf("list is full!\n");
    }
    else
    {
        printf("list is not full!\n");
    }
}



int main()
{
    // FIFO
    // First in first out
    // 1 2 3 4 5
    // insert
    int ch;
    while (1)
    {
        printf("Enter choice:\n1. enqueue\n2. dequeue\n3. display\n4. is empty\n5. is full\n6. exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            isempty();
            break;
        case 5:
            isfull();
            break;
        case 6:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}