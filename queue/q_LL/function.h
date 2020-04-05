#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void push(void);
void pop(void);
void display(void);
void peek(void);