/*****************************************************
 * Authors: Rihanna Overbaugh and Elizabeth Huffman
 * File Name: plantSeeds.c
 * Version: 1.0 3/5/26 
            1.1 3/12/26
            1.2 3/24/26
            1.3 4/2/26
*****************************************************/
#include <stdio.h>
#include "plantSeeds.h"

char plant;

int plantSeed_error(char plant)
{ 
  while ((plant =! 'n') && (plant =! 'y')) 
  { 
    printf("Let's try again, would you like to plant? y or n: \n");
    scanf("%c", &plant);
  } 
  return plant;
 }  

int plantSeeds(int tomatoSeeds, int wildFlowerSeeds, int radishSeeds, int sugarCaneSeeds, int potatoSeeds) 
{
  int tomato, wildFlower, radish, sugarCane, potato; 
  
  if (tomatoSeeds > 0)
  {
    printf("Would you like to plant tomatoes? y or n: \n");
    scanf("%c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Tomato seeds planted! \n"); 
      tomato++; 
    }
    else if (plant == 'n')
    { 
      printf("Tomato seeds not planted! \n");
    }
  }
  if (wildFlowerSeeds > 0)
  {
    printf("Would you like to plant Wild Flowers? y or n: \n");
    scanf("%c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Wild Flower seeds planted! \n"); 
      wildFlower++; 
    }
    else if (plant == 'n')
    { 
      printf("Wild Flower seeds not planted! \n");
    }
  }
  if (radishSeeds > 0)
  {
    printf("Would you like to plant radishes? y or n: \n");
    scanf("%c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Radish seeds planted! \n"); 
      radish++; 
    }
    else if (plant == 'n')
    { 
      printf("Radish seeds not planted! \n");
    }
  }
  if (sugarCaneSeeds > 0)
  {
    printf("Would you like to plant Sugar Cane? y or n: \n");
    scanf("%c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Sugar Cane seeds planted! \n"); 
      sugarCane++; 
    }
    else if (plant == 'n')
    { 
      printf("Sugar Cane seeds not planted! \n");
    }
  }
  if (potatoSeeds > 0)
  { 
    printf("Would you like to plant Potatoes? y or n: \n");
    scanf("%c", &plant);
    plant = plantSeed_error(plant);
    if (plant == 'y') 
    {
      printf("Potato seeds planted! \n"); 
      potato++; 
    }
    else if (plant == 'n')
    { 
      printf("Potato seeds not planted! \n");
    }
  }
  return tomato,potato,wildFlower,sugarCane,radish; 
}
