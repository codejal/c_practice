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

void sit_on_chair(char ch[]);
void sit_on_chair0(char ch[]);
int Dice(void);
void remove_even(int dice_roll);
void remove_odd(int dice_roll);
void winner(void);
