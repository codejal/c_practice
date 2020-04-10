#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = top;
    top = t;
};
int main()
{
    push(20);
    printf("%d", top->data);
    return 0;
}
