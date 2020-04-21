#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct chair
{
    struct chair *leftChair;
    char player[30];
    struct chair *rightChair;
};
struct chair *head = NULL, *last = NULL;

void sit_on_chair(char ch[])
{
    struct chair *temp;
    temp = (struct chair *)malloc(sizeof(struct chair));
    strcpy(temp->player, ch);
    temp->rightChair = head;
    last->rightChair = temp;
    temp->leftChair = last;
    head->leftChair = temp;
    last = temp;
};

void sit_on_chair0(char ch[])
{
    head = (struct chair *)malloc(sizeof(struct chair));
    strcpy(head->player, ch);
    last = head;
};

int Dice(void)
{
    int i = 1 + rand() % 6;
    return i;
};

void remove_even(int dice_roll)
{
    struct chair *remove = NULL;
    remove = (struct chair *)malloc(sizeof(struct chair));
    remove = head;
    for (int i = 1; i < dice_roll; i++)
        remove = remove->rightChair;

    if (remove == head)
    {
        head = head->rightChair;
        remove->rightChair->leftChair = remove->leftChair;
        remove->leftChair->rightChair = remove->rightChair;
        printf("player %s loosed\n", remove->player);
    }
    else
    {
        remove->rightChair->leftChair = remove->leftChair;
        remove->leftChair->rightChair = remove->rightChair;
        printf("player %s loosed\n", remove->player);
    }
};

void remove_odd(int dice_roll)
{
    struct chair *remove = NULL;
    remove = (struct chair *)malloc(sizeof(struct chair));
    remove = head;
    for (int i = 1; i <= dice_roll; i++)
        remove = remove->leftChair;
    if (remove == head)
    {
        head = head->rightChair;
        remove->rightChair->leftChair = remove->leftChair;
        remove->leftChair->rightChair = remove->rightChair;
        printf("player %s loosed\n", remove->player);
    }
    else
    {
        remove->rightChair->leftChair = remove->leftChair;
        remove->leftChair->rightChair = remove->rightChair;
        printf("player %s loosed\n", remove->player);
    }
};

int main()
{
    int count = 1, dice_roll;
    char ch[30];
    int checkmark = 1;
    FILE *fp;
    fp = fopen("player.txt", "r");
    fscanf(fp, "%s", ch);
    sit_on_chair0(ch);
    printf("Giving chair to %s \n", ch);
    while (fscanf(fp, "%s", ch) != EOF)
    {
        sit_on_chair(ch);
        printf("Giving chair to %s \n", ch);
        count++;
    }
    fclose(fp);
    printf("\n%d PLAYERS ARE ON SEAT\nLETS BEGIN THE GAME \n\n", count);

    for (int i = 1; i <= 19; i++)
    {
        dice_roll = Dice();
        printf("You got %d on the dice ", dice_roll);
        if (dice_roll % 2 == 0)
        {
            remove_even(dice_roll);
        }
        else
        {
            remove_odd(dice_roll);
        }
    }
    printf("\n\n%s IS OUR WINNER", head->player);
}