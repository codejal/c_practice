/*it checks the expression for parenthesis are matching or not*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = -1;
char array[10], arr[10];
void push(void)
{
    top++;
    arr[top] = '(';
};

void pop(void)
{
    top = top - 1;
};

int main()
{
    printf("enter expression = ");
    scanf("%s", &array);
    int i = 0;
    while (array[i] != '\0')
    {
        if (array[i] == '(')
            push();
        if (array[i] == ')')
            pop();
        i++;
    }
    if (top == -1)
        printf("good");
    else
        printf("bad");
}