#include <stdio.h>
#include "merchant.h"

#define RESET "\033[0m"
#define YELLOW "\033[33m"

void merchant(int *CATcoins,
              int *tomatoSeeds, int *wildFlowerSeeds, int *sugarCaneSeeds,
              int *radishSeeds, int *potatoSeeds,
              int *tomato, int *wildFlower, int *radish,
              int *sugarCane, int *potato)
{
    int buy_sell;
    int buyChoice;
    char continuebuy = 'y';
    char continuesell = 'y';
    char sell;

    printf(YELLOW);
    printf("Welcome to Luna's Emporium!\n");
    printf("You have %d CAT coins.\n", *CATcoins);
    printf("Would you like to buy or sell?\n");
    printf("1. Buy\n");
    printf("2. Sell\n");
    scanf("%d", &buy_sell);

    while (buy_sell != 1 && buy_sell != 2)
    {
        printf("Incorrect input. Try again.\n");
        printf("1. Buy\n");
        printf("2. Sell\n");
        scanf("%d", &buy_sell);
    }

    if (buy_sell == 1)
    {
        while (continuebuy == 'y' || continuebuy == 'Y')
        {
            printf("\nOptions to buy:\n");
            printf("1. Wild Flower Seeds (5 CAT coins)\n");
            printf("2. Tomato Seeds (10 CAT coins)\n");
            printf("3. Radish Seeds (15 CAT coins)\n");
            printf("4. Sugar Cane Seeds (20 CAT coins)\n");
            printf("5. Potato Seeds (10 CAT coins)\n");
            printf("Enter your choice: ");
            scanf("%d", &buyChoice);

            if (buyChoice == 1)
            {
                if (*CATcoins < 5)
                {
                    printf("Not enough CAT coins.\n");
                }
                else
                {
                    printf("Wild Flower Seeds purchase successful.\n");
                    (*wildFlowerSeeds)++;
                    *CATcoins -= 5;
                }
            }
            else if (buyChoice == 2)
            {
                if (*CATcoins < 10)
                {
                    printf("Not enough CAT coins.\n");
                }
                else
                {
                    printf("Tomato Seeds purchase successful.\n");
                    (*tomatoSeeds)++;
                    *CATcoins -= 10;
                }
            }
            else if (buyChoice == 3)
            {
                if (*CATcoins < 15)
                {
                    printf("Not enough CAT coins.\n");
                }
                else
                {
                    printf("Radish Seeds purchase successful.\n");
                    (*radishSeeds)++;
                    *CATcoins -= 15;
                }
            }
            else if (buyChoice == 4)
            {
                if (*CATcoins < 20)
                {
                    printf("Not enough CAT coins.\n");
                }
                else
                {
                    printf("Sugar Cane Seeds purchase successful.\n");
                    (*sugarCaneSeeds)++;
                    *CATcoins -= 20;
                }
            }
            else if (buyChoice == 5)
            {
                if (*CATcoins < 10)
                {
                    printf("Not enough CAT coins.\n");
                }
                else
                {
                    printf("Potato Seeds purchase successful.\n");
                    (*potatoSeeds)++;
                    *CATcoins -= 10;
                }
            }
            else
            {
                printf("Invalid choice.\n");
            }

            printf("You now have %d CAT coins.\n", *CATcoins);
            printf("Would you like to continue buying? (y/n): ");
            scanf(" %c", &continuebuy);
        }
    }
    else
    {
        while (continuesell == 'y' || continuesell == 'Y')
        {
            if (*wildFlower > 0)
            {
                printf("Would you like to sell a Wild Flower for 5 CAT coins? (y/n): ");
                scanf(" %c", &sell);
                if (sell == 'y' || sell == 'Y')
                {
                    (*wildFlower)--;
                    *CATcoins += 5;
                    printf("Wild Flower sold!\n");
                }
            }

            if (*tomato > 0)
            {
                printf("Would you like to sell a Tomato for 10 CAT coins? (y/n): ");
                scanf(" %c", &sell);
                if (sell == 'y' || sell == 'Y')
                {
                    (*tomato)--;
                    *CATcoins += 10;
                    printf("Tomato sold!\n");
                }
            }

            if (*radish > 0)
            {
                printf("Would you like to sell a Radish for 15 CAT coins? (y/n): ");
                scanf(" %c", &sell);
                if (sell == 'y' || sell == 'Y')
                {
                    (*radish)--;
                    *CATcoins += 15;
                    printf("Radish sold!\n");
                }
            }

            if (*sugarCane > 0)
            {
                printf("Would you like to sell a Sugar Cane for 20 CAT coins? (y/n): ");
                scanf(" %c", &sell);
                if (sell == 'y' || sell == 'Y')
                {
                    (*sugarCane)--;
                    *CATcoins += 20;
                    printf("Sugar Cane sold!\n");
                }
            }

            if (*potato > 0)
            {
                printf("Would you like to sell a Potato for 10 CAT coins? (y/n): ");
                scanf(" %c", &sell);
                if (sell == 'y' || sell == 'Y')
                {
                    (*potato)--;
                    *CATcoins += 10;
                    printf("Potato sold!\n");
                }
            }

            printf("You now have %d CAT coins.\n", *CATcoins);
            printf("Would you like to sell again? (y/n): ");
            scanf(" %c", &continuesell);
        }
    }

    printf(RESET);
}
