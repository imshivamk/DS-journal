#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
};

struct node *top = NULL;

void push()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    {
        printf("Enter the data:\n");
        scanf("%d", &newnode->data);

        if (top == NULL)
        {
            newnode->prev = NULL;
            top = newnode;
        }
        else
        {
            newnode->prev = top; // store the previous top in the prev part of the newnode
            top = newnode;       // update the top aas the ADDRESS TO THE NEWNDODE
        }
    }
}

void display()
{
    struct node *temp = top;
    printf("The stack is:\n");
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void peep()
{
    struct node *temp = top;
    printf("The top is:\n");
    printf("%d\n", temp->data);
}
void pop()
{
    struct node *temp = top;
    top = top->prev;
    free(temp);
}
int main()
{

    int ch;
    while (1)
    {
        printf("1.push\n2.pop\n3.peek\n4.display\5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("wrong input!\n");
        }
    }
    return 0;
}