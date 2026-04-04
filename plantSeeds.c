/*****************************************************
 * Authors: Rihanna Overbaugh and Elizabeth Huffman
 * File Name: plantSeeds.c
 * Version: 1.0 3/5/26 (created file)
            1.1 3/12/26 (if statements)
            1.2 3/24/26 (integrating with main)
            1.4 3/31/26 (debugging)
            1.5 4/1/26 (more debugging) 
            1.6 4/4/26 (made seeds pointers and the planted structure) 
*****************************************************/
#include <stdio.h>
#include "plantSeeds.h"

char plant;
Planted planted;

char plantSeed_error(char plant)
{ 
  while ((plant != 'n') && (plant != 'y')) 
  { 
    printf("Let's try again, would you like to plant? y or n: \n");
    scanf(" %c", &plant);
  } 
  return plant;
 }  

void plantSeeds(int *tomatoSeeds, int *wildFlowerSeeds, int *radishSeeds, int *sugarCaneSeeds, int *potatoSeeds) 
{
  if (*tomatoSeeds > 0)
  {
    printf("Would you like to plant tomatoes? y or n: \n");
    scanf(" %c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Tomato seeds planted! \n"); 
      planted.tomato++;
      (*tomatoSeeds--);
    }
    else if (plant == 'n')
    { 
      printf("Tomato seeds not planted! \n");
    }
  }
  if (*wildFlowerSeeds > 0)
  {
    printf("Would you like to plant Wild Flowers? y or n: \n");
    scanf(" %c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Wild Flower seeds planted! \n"); 
      planted.wildFlower++;
      (*wildFlowerSeeds--);
    }
    else if (plant == 'n')
    { 
      printf("Wild Flower seeds not planted! \n");
    }
  }
  if (*radishSeeds > 0)
  {
    printf("Would you like to plant radishes? y or n: \n");
    scanf(" %c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Radish seeds planted! \n"); 
      planted.radish++;
      (*radishSeeds--);
    }
    else if (plant == 'n')
    { 
      printf("Radish seeds not planted! \n");
    }
  }
  if (*sugarCaneSeeds > 0)
  {
    printf("Would you like to plant Sugar Cane? y or n: \n");
    scanf(" %c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Sugar Cane seeds planted! \n"); 
      planted.sugarCane++;
      (*sugarCaneSeeds--);
    }
    else if (plant == 'n')
    { 
      printf("Sugar Cane seeds not planted! \n");
    }
  }
  if (*potatoSeeds > 0)
  { 
    printf("Would you like to plant Potatoes? y or n: \n");
    scanf(" %c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Potato seeds planted! \n"); 
      planted.potato++;
      (*potatoSeeds--);
    }
    else if (plant == 'n')
    { 
      printf("Potato seeds not planted! \n");
    }
  }
}
