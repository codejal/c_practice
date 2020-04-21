#include "chair.h"

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

void winner(void)
{
    printf("\n%s IS OUR WINNER", head->player);
}