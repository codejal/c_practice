#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, max;
    scanf("%d", &max);
    int array[max];
    printf("Select choice");
    printf("1) push");
    printf("2) pop");
    printf("3) peek");
    printf("4) display");
    printf("5) Exit");
    scanf("%d", &choice);
    while (choice)
    {
        printf("Select choice");
        printf("1) push");
        printf("2) pop");
        printf("3) peek");
        printf("4) display");
        printf("5) Exit");

        switch (choice)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
        printf("Enter the choice");
        scanf("%d", &choice);
    }
}