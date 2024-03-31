// 6. Write a C program to implement operations on a
// doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *end = NULL;

void create()
{
    int size;
    printf("enter size\n");
    scanf("%d", &size);

    for (int i = 1; i <= size; i++)
    {
        struct node *newnode;                                 // declare
        newnode = (struct node *)malloc(sizeof(struct node)); // allocate
        int val;
        printf("Enter data:\n");
        scanf("%d", &val);

        newnode->data = val;

        if (head == NULL)
        {
            newnode->next = NULL;
            newnode->prev = NULL;

            head = newnode;
            end = newnode;
        }
        else
        {
            newnode->next = NULL;
            newnode->prev = end;

            end->next = newnode;

            end = newnode;
        }
    }
}

void insert()
{
    int p;
    printf("Enter where to insert:\n");
    scanf("%d", &p);

    struct node *temp = head;
    struct node *current;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);

    if (p == 1)
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;

        head = newnode;
    }
    else
    {
        // start the loop from 1 , coz if started from zero, for the last node, the temp next will be null
        // and all hell will break loose
        for (int i = 1; i < p; i++)
        {
            current = temp;    // n-1'th
            temp = temp->next; // n'th
        }

        if(temp == NULL)
        {
            current->next = newnode;
            newnode->prev = current;
            newnode->next = NULL;

        }
        else
        {
            // any other scenaio
            current->next = newnode;
            temp->prev = newnode;
            newnode->prev = current;
            newnode->next = temp;
        }
    }
}

void deletion()
{
    int p;
    printf("Enter which position to delete:\n");
    scanf("%d", &p);

    struct node *temp = head;
    struct node *current;

    if (p == 1)
    {
        // delete the first node
        head = temp->next; // the second node becomes the head node
        temp->next->prev = NULL;

        free(temp);
    }
    else
    {
        for (int i = 1; i < p; i++)
        {
            current = temp;    // n-1'th
            temp = temp->next; // n'th
        }

        if(temp->next == NULL)
        {
            // deleting the last node!!
            current->next = NULL;
            free(temp);
        }
        else
        {
            current->next = temp->next;
            temp->next->prev = current;

            free(temp);
        }
    }
}

void traversal()
{
    printf("the list:\n");

    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d,", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void backward()
{
    printf("the list in backwards order:\n");

    struct node *temp;
    temp = end;
    while (temp != NULL)
    {
        printf("%d,", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    end = NULL;
    // initially the list is empty
    int ch;
    while (1)
    {
        printf("1.create\n2.insert\n3.delete\n4.traverse\n5.BACKWARD\n6.exit\n");
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
            traversal();
            break;
        case 5:
            backward();
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("invalid input\n");
            break;
        }
    }

    return 0;
}