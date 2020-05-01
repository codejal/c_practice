#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *root = NULL;
int elements[100] = {-1};

struct node *create_root(int elements[])
{
}

int main()
{
    //creating tree
    int size, i, temp;
    printf("Enter number of elements in your tree ");
    scanf("%d", &size);
    for (i = 1; i < size; i++)
    {
        printf("Enter number of elements in your tree ");
        scanf("%d", &temp);
        elements[i] = temp;
    }
    create_root(elements);
}