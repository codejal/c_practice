#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create(int array[], int size)
{
    int i;
    struct node *last, *temp;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = array[0];
    head->next = NULL;
    head->prev = NULL;
    last = head;
    for (i = 1; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = array[i];
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display()
{
    struct node *p;
    p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != NULL);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    create(array, 8);
    display();
    printf("\n");
}