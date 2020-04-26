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

        printf("\n--What next--\n");
        printf("1) push     1  \n");
        printf("2) pop      2 \n");
        printf("3) peek     3  \n");
        printf("4) display  4  \n");
        printf("5) Exit     5  \n");
        printf("      ");
        scanf("%d", &choice);
    }
    printf("\nGOODBYE\n\n");
}