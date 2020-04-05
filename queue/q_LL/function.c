#include "function.h"
struct node *head = NULL;
struct node *last = NULL;
int count = 0;
void push(void)
{
    int temp;
    printf("enter number to enter = ");
    scanf("%d", &temp);
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (count == 0)
    {
        t->data = temp;
        t->next = NULL;
        head = t;
        last = head;
        count = 1;
    }
    if (count == 1)
    {
        t->data = temp;
        t->next = NULL;
        last->next = t;
        last = t;
    }
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
        printf("%d ,", p->data);
        p = p->next;
    }
};

void peek(void)
{
    printf("%d", head->data);
};