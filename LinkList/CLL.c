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
    struct node *last, *temp;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = array[0];
    first->next = first;
    last = first;
    for (i = 1; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = array[i];
        last->next = temp;
        temp->next = first; //linking circularly
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

int main()
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    create(array, 6);
    display();
    printf("\n");
}