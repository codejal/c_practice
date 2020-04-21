#include "chair.h"
int main()
{
    int count = 1, dice_roll;
    char ch[30];
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
    winner();
}