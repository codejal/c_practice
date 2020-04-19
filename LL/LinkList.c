#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
struct node
{
    int data;
    struct node *next;
};

struct node *first;

void create(int array[], int size)
{
    int i;
    struct node *last;
    struct node *temp;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = array[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
};

void display()
{
    int i;
    struct node *t;
    t = first;
    for (i = 0; i < 6; i++)
    {
        printf("%d ", t->data);
        t = t->next;
    }
};

void reverse()
{
    struct node *p = NULL, *q = NULL, *r = NULL;
    p = first;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    };
    first = q;
};

int main()
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    create(array, 6);
    display();
    reverse();
    printf("\n");
    display();
    printf("\n");
}