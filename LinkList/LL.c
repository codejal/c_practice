/*linked list - have insert at given index, reverse the LL, display the LL*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *first;
struct node *last;
void create(int array[], int size)
{
    int i;

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

void display(int size)
{
    int i;
    struct node *t;
    t = first;
    for (i = 0; i < size; i++)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
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
    }
    last = first; //very important that the last pointer is also changed or
    first = q;    //else it will create problem in other functions
};

void insert(int x, int position, int size)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if (position == 0)
    {
        temp->next = first;
        first = temp;
    }

    if (position == size)
    {
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    if (position != 0 && position != size)
    {
        struct node *z;
        z = (struct node *)malloc(sizeof(struct node));
        z = first;
        for (int i = 1; i < position; i++)
        {
            z = z->next;
        }
        temp->next = z->next;
        z->next = temp;
    }
};

int main()
{
    int array[6] = {1, 2, 3, 4, 5, 6}, size = 6;
    create(array, 6);
    display(size++);

    insert(999, 0, 6);
    display(size++);

    insert(110, 2, size);
    display(size++);

    reverse();

    insert(110, 2, size);
    display(size++);
    reverse();

    insert(1000, size, size);
    display(size++);
}