/***********************************************************
 * File Name: merchant.c
 * Authors: Rihanna Overbaugh and Eilzabeth Huffman
 * Version: 1.0 4/1/26
************************************************************/
#include <stdio.h> 
#include "merchant.h" 

#define RESET "\033[0m"
#define YELLOW "\033[33m"

int sell_errorcheck()
{
    while ((sell != 'y') && (sell != 'n'))
    {
        printf("Incorrect input try again! \n");
        printf("Would you like to sell? (y or n) \n");
        scanf(" %c", &sell);
    }
    return 0;
}


void merchant()
{ 
  int buy_sell;
  int buyseeds;
  char continuebuy = 'y';
  char sell;
  char continuesell = 'y';

  printf(YELLOW); 
  printf("Welcome to Luna's emporium! Would you like to Buy items or sell? ( 1 to purchase, 2 to sell): \n");
  scanf("%d", buy_sell);
  while ((buy_sell != 1) && (buy_sell != 2))
  {
    printf("Incorrect input try again!");
    printf("Would you like to Buy items or sell? ( 1 to purchase, 2 to sell): \n");
    scanf("%d", buy_sell);
  }
  if (buy_sell == 1) 
  {
    printf("Options to buy (Enter the corresponding number):\n1: Wild Flower Seeds (5 CAT coins) \n2: Tomato Seeds (10 CAT coins) \n3:Radish Seeds (15 CAT coins) \n4: Sugar Cane Seeds (20 CAT coins) \n5: Potato Seeds (10 CAT coins) \n")
    scanf("%d", &buyseeds);
    while (continuebuy = 'y')
    {
        if (buyseeds == 1) 
        {
            if (CATcoins < 5)
            {
                printf("Not enough CAT coins \n");
            }
            else if (CATcoins >= 10) 
            {
                printf("Wild Flower Seeds Purchase Sucessful \n");
                (*wildFlowerSeeds)++;
                CATcoins - 5;
            }
        }
        else if (buyseeds == 2)
        {
            if (CATcoins < 10)
            {
                printf("Not enough CAT coins \n");
            }
            else if (CATcoins >= 10) 
            {
                printf("Tomato Seeds Purchase Sucessful \n");
                (*tomatoSeeds)++;
                CATcoins - 10
            }
        }
        else if (buyseeds == 3)
        {
            if (CATcoins < 15)
            {
                printf("Not enough CAT coins \n");
            }
            else if (CATcoins >= 15) 
            {
                printf("Radish Seeds Purchase Sucessful \n");
                (*radishSeeds)++;
                CATcoins - 15
            }
        }
        else if (buyseeds == 4) 
        {
            if (CATcoins < 20)
            {
                printf("Not enough CAT coins \n");
            }
            else if (CATcoins >= 20)
            {
                printf("Sugar Cane Seeds Purchase Sucessful \n");
                (*sugarCaneSeeds)++;
                CATcoins - 20;
            }
        }
        else if (buyseeds == 5)
        {
            if (CATcoins < 10)
            {
                printf("Not enough CAT coins \n"); 
            }
            else if (CATcoins >= 10)
            {
                printf("Potato Seeds Purchanse Sucessfull \n");
                (*potatoSeeds)++;
                CATcoins - 10;
            }
        }
        printf("Would you like to continue? ('y' for yes, 'n' for no) \n");
        scanf(" %c", &continuebuy);
    }
  }
  if (buy_sell == 2)
  { 
    while (continuesell == 'y')
    {
        if (WildFlower > 0)
        {
            printf("Would you like to sell Wild Flowers? (y or n): \n");
            scanf(" %c", &sell);
            sell_errorcheck();
            if (sell == 'y')
            {
            printf("Wild Flowers Sold! \n");
            wildFlower--;
            }
        }
        if (Tomato > 0)
        {
            printf("Would you like to sell Tomatoes?: \n");
            scanf(" %c", &sell);
            sell_errorcheck();
            if (sell == 'y')
            {
                printf("Tomatoes Sold! \n");
                Tomatoes--;
            }
        }
        if (Radish > 0)
        {
            printf("Would you like to sell Radishes?: \n");
            scanf(" %c", &sell);
            sell_errorcheck();
            if (sell == 'y')
            {
                printf("Radishes Sold! \n");
                Radishes--;
            }
        }
        if (SugarCane > 0)
        {
            printf("Would you like to sell Sugar Cane?: \n");
            scanf(" %c", &sell);
            sell_errorcheck();
            if (sell == 'y')
            {
                printf("Sugar Cane Sold! \n");
                SugarCane--;
            }
        }
        if (Potatoes > 0)
        {
            printf("Would you like to sell Potatoes? \n");
            scanf(" %c", &sell)
            sell_errorcheck();
            if (sell == 'y')
            {
                printf("Potatoes Sold! \n")
                Potatoes--;
            }
        }
        printf("Would you like to sell again?(y or n): \n");
        scanf(" %c", &continuesell);
    }
  }
  printf(RESET);
}
