#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);


    if(front == NULL)
    {
        newnode->next = NULL;
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        newnode->next = NULL;
        rear = newnode;
    }


}

void display()
{
    struct node *temp = front;
    printf("The queue is:\n");
    while(temp!=NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;

    }
    printf("\n");


}

void dequeue()
{
    if(front==NULL)
    {
        printf("the queue is empty:\n");
    }
    else
    {
        struct node *temp;
        // 1 2 3
        temp = front; // 1

        if(temp->next==NULL)
        {
            rear = NULL;
        }

        front = front->next; // front = 2
        free(temp); // 2 3

    }
}

int main()
{

    int ch;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n\4.exit\n");
        scanf("%d", &ch);
        switch(ch)
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
            exit(0);
            break;
            default:
            printf("wrong input!\n");
        }
    }

    return 0;
}