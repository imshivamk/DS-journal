// 5. Write a C program to count number of
// items present in a singly linked list.



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *end = NULL;

void count()
{
    int count = 0;
    struct node* temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("the number of nodes in the list : %d\n", count);
}

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
            head = newnode;
            end = newnode;
        }
        else
        {
            newnode->next = NULL;

            end->next = newnode;
            end = newnode;
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

        current->next = newnode;
        newnode->next = temp;
    }
}

void deletion()
{
    int p;
    printf("Enter which position to delete:\n");
    scanf("%d", &p);

    struct node *temp = head;
    struct node *current;

    for (int i = 1; i < p; i++)
    {
        current = temp;    // n-1'th
        temp = temp->next; // n'th
    }


    current->next = temp->next;
    free(temp);
}


int main()
{
    head = NULL;
    end = NULL;
    // initially the list is empty
    int ch;
    while (1)
    {
        printf("1.create\n2.insert\n3.delete\n4.traverse\n5.count\n6.exit\n");
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
            count();
            break;
        case 6: exit(0);
            break;

        default:
            printf("invalid input\n");
            break;
        }
    }

    return 0;
}