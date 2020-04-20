#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(void)
{
    int temp;
    printf("enter number to enter = ");
    scanf("%d", &temp);
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = temp;
    t->next = head;
    head = t;
};

void pop(void)
{
    if (head == NULL)
        printf("stack is empty \n");
    else
    {
        printf("the poped element is %d\n", head->data);
        head = head->next;
    }
};

void display(void)
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
};

void peek(void)
{
    printf("%d", head->data);
};

int main()
{
    int choice;
    printf("Select choice\n");
    printf("1) push     1  \n");
    printf("2) pop      2 \n");
    printf("3) peek     3  \n");
    printf("4) display  4  \n");
    printf("5) Exit     5  \n");
    scanf("%d", &choice);
    while (choice != 5)
    {
        switch (choice)
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
            break;
        }

        printf("\n--What next--\n");
        printf("1) push     1  \n");
        printf("2) pop      2 \n");
        printf("3) peek     3  \n");
        printf("4) display  4  \n");
        printf("5) Exit     5  \n");
        printf("      ");
        scanf("%d", &choice);
    }
    printf("\nGOODBYE\n\n");
}