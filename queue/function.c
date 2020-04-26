int top = 0, last = -1;
int queue[10];
void push(void)
{
    int x;
    printf("enter nuymber to push = ");
    scanf("%d", &x);
    printf("\n");
    last++;
    queue[last] = x;
}

int pop(void)
{
    printf(" Popwd element= %d\n", queue[last]);
    last = last - 1;
    return queue[last];
}

void peek(void)
{
    int index;
    printf("Enter the index to peek = ");
    scanf("%d", &index);
    printf("%d", queue[index + 1]);
}

void display(void)
{
    int i;
    printf("Number entered is order are =  ");
    for (i = 0; i <= last; i++)
    {
        printf("%d ,", queue[last]);
    }
    printf("\n");
}