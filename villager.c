/*****************************************************************************************************
*File:      villager.c
*Purpose:   All code for villager movement.
*Version:   1.0 April 2, 2026 - Psuedo in word doc of how to build functions
*           1.1 April 4, 2026 - Dedicated to building this file (Began running all file to test game)
*           1.2 April 5, 2026 - FINISHED
*Resources: Help from Lab sessions & online GDB debugging
******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "villager.h"

int willow(void) // PRINT ART FUNCTION FOR WILLOW
{
  char willow_art[400];
  int i;
  FILE *f = fopen("willow.txt", "r");

  if (f == NULL)
  {
    printf("Could not open willow.txt\n"); // Error checking for if it can open file.
    return 1;
  }

  for (i = 0; i <= 7; i++)
  {
    if (fgets(willow_art, 400, f) != NULL)
    {
      printf("%s", willow_art);
    }
  }

  fclose(f);
  return 0;
}

int wombat(void) // PRINT ART FUNCTION FOR WOMBAT
{
  char wombat_art[400];
  int i;
  FILE *f = fopen("wombat.txt", "r");

  if (f == NULL)
  {
    printf("Could not open wombat.txt\n"); // Error checking for if it can open file.
    return 1;
  }

  for (i = 0; i <= 7; i++)
  {
    if (fgets(wombat_art, 400, f) != NULL)
    {
      printf("%s", wombat_art);
    }
  }

  fclose(f);
  return 0;
}

int charlie(void) // PRINT ART FUNCTION FOR CHARLIE
{
  char charlie_art[400];
  int i;
  FILE *f = fopen("charlie.txt", "r");

  if (f == NULL)
  {
    printf("Could not open charlie.txt\n"); // Error checking for if it can open file.
    return 1;
  }

  for (i = 0; i <= 7; i++)
  {
    if (fgets(charlie_art, 400, f) != NULL)
    {
      printf("%s", charlie_art);
    }
  }

  fclose(f);
  return 0;
}


void initializeVillagers(Villager v[], int count) // VILLAGERS "SYMBOLS" FOR MAP
{
  v[0].symbol = 'C'; // -> charlie
  v[0].tutorialOnly = 0;

  v[1].symbol = 'W'; // -> Wombat
  v[1].tutorialOnly = 0;

  v[2].symbol = 'M'; // Milo = only tutorial day 
  v[2].tutorialOnly = 1; 

  v[3].symbol = 'L'; // -> Willow (cant use 'W' and a capital 'I' would clash)
  v[3].tutorialOnly = 0;

  v[4].symbol = 'S';
  v[4].tutorialOnly = 0; // Merchant = S b/c $
}

void randomizeVillagers(Villager v[], int count, int rows, int cols) // randomization of villager locations
{
  int i, j, duplicate;

  for (i = 0; i < count; i++)
  {
    do
    {
      duplicate = 0;
      v[i].row = rand() % rows;
      v[i].col = rand() % cols;

      for (j = 0; j < i; j++)
      {
        if (v[i].row == v[j].row && v[i].col == v[j].col)
        {
          duplicate = 1;
        }
      }
    } while (duplicate);
  }
}

void placeVillagersOnMap(char world[][10], Villager v[], int count, int rows, int cols, int day) // places villagers on new randomized locations every day 
{
  int i, r, c;

  for (r = 0; r < rows; r++)
  {
    for (c = 0; c < cols; c++)
    {
      world[r][c] = '.';
    }
  }

  for (i = 0; i < count; i++)
  {
    if (v[i].tutorialOnly == 1 && day != 1)
    {
      continue;
    }
    world[v[i].row][v[i].col] = v[i].symbol;
  }
}

void talkToVillager(Villager v[], int count, int row, int col, int day)
{
  int i;

  for (i = 0; i < count; i++)
  {
    if (v[i].row == row && v[i].col == col)
    {
      if (v[i].tutorialOnly == 1 && day != 1) // You can not talk to anyone BUT Milo through the guided tutorial on day 1
      {
        printf("Nobody is here.\n");
        return;
      }

      if (v[i].symbol == 'C')
      {
        charlie(); // Charlie art
        printf("\n");
        printf("Charlie: Meow! You scared me newbie.\n");
        return;
      }
      else if (v[i].symbol == 'W')
      {
        wombat(); // Wombat art
        printf("\n");
        printf("Wombat: Don't forget to water your crops...and take them to Luna for some *extra* cash\n");
        return;
      }
      else if (v[i].symbol == 'M') // Only on day 1!
      {
        printf("Milo: Welcome to the world of cats!\n");
        return;
      }
      else if (v[i].symbol == 'L')
      {  
        willow(); // Willow art
        printf("\n");
        printf("Willow: Well, hello there farmer!! Keep farming and selling.\n");
        return;
      }
      else if (v[i].symbol == 'S') // Dialogue only for selling and buying 
      {
        printf("Luna: Welcome to my emporium.\n");
        return;
      }
    }
  } 

  printf("There is nobody here to talk to.\n"); // Must be on the same tile to talk to villager so make sure you look at where you are going!
}
