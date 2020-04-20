#include <stdio.h>
#include <stdlib.h>
int max = 10;
int array[10];
int top = -1;
void push(void)
{
    if (top == max - 1)
        printf("Stack is full no more can be added\n");
    else
    {
        int temp;
        printf("enter data to enter");
        scanf("%d", &temp);
        top = top + 1;
        array[top] = temp;
    }
};

void pop(void)
{
    if (top == -1)
    {
        printf("stack empty nothing to pop\n");
    }
    else
    {
        printf("poped element = %d\n", array[top]);
        top = top - 1;
    }
};

void display(void)
{
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
};

void peek(void)
{
    int temp;
    printf("enter index to peek if first index is 1 = ");
    scanf("%d", &temp);
    printf("Element on index %d is %d ", temp, array[temp - 1]);
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
        printf("--What next--\n");
        printf("1) push     1  \n");
        printf("2) pop      2 \n");
        printf("3) peek     3  \n");
        printf("4) display  4  \n");
        printf("5) Exit     5  \n");
        scanf("%d", &choice);
    }
    printf("\nGOODBYE\n");
}