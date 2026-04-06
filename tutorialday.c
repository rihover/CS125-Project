/*******************************************************************************************************************
*File:      tutorialday.c
*Purpose:   header file for tutorial day (day 1).
*Version:   1.0 - started as our main function at beginning of project, after finishing up this file, we had to split it off to only be the first day
*           1.1 April 4, 2026 - finishing up mainGame function.
*           1.2 April 5, 2026 - FINISHED
*Resources: Ran it through ChatGPT and asked for help because of errors, had just initialized functions wrong.
*           FOR ALL HEADERS: 
*             - (https://www.youtube.com/watch?v=oe11Dhw9dOg) -> Understanding header files in c by theurbanpenguin
********************************************************************************************************************/
#include <stdio.h>
#include "tutorialday.h"
#include "plantSeeds.h"

#define BLUE "\033[34m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

int farmart(void) // PRINTING FARM HOUSE FUNCTION
{
  char farm_house[400];
  int i;
  FILE *f = fopen("farm_art.txt", "r");

  if (f == NULL)
  {
    printf("Could not open farm_art.txt\n");
    return 1;
  }

  for (i = 0; i <= 7; i++)
  {
    if (fgets(farm_house, 400, f) != NULL)
    {
      printf("%s", farm_house);
    }
  }

  fclose(f);
  return 0;
}

int wildFlowerart(void) // PRINTING FLOWER SEEDS FUNCTION
{
  char flowerSeeds[400];
  int i;
  FILE *f = fopen("flower_art.txt", "r");

  if (f == NULL)
  {
    printf("Could not open flower_art.txt\n");
    return 1;
  }

  for (i = 0; i <= 14; i++)
  {
    if (fgets(flowerSeeds, 400, f) != NULL)
    {
      printf("%s", flowerSeeds);
    }
  }

  fclose(f);
  return 0;
}

int miloart(void)
{
    char milo[400];
    int i;
    FILE *f = fopen("milo.txt", "r");

    if (f == NULL)
    {
        printf("Could not open milo.txt\n");
        return 1;
    }

    for (i = 0; i <= 5; i++)
    {
        if (fgets(milo, 400, f) != NULL)
        {
            printf("%s", milo);
        }
    }

    fclose(f);
    return 0;
}

void runTutorialDay(char playerName[],char farmName[],int *tomatoSeeds,int *wildFlowerSeeds,int *sugarCaneSeeds,int *radishSeeds,int *potatoSeeds,int *shovel,int *hoe,int *waterCan)
{
  char elixir;
  char cont;

  printf("Welcome to The World of Cats!\n");

  printf("Enter your name (Maximum of 15 characters): \n");
  scanf("%15s", playerName);

  printf("Enter a farm name (Maximum of 20 characters): \n");
  scanf("%20s", farmName);

  printf("Welcome to %s! Here is a look at your farm!\n", farmName);
  printf("\n\n\n");

  farmart(); // PRINT FARM ART

  printf("\n\n\n");
  printf("Today is your first day of owning a farm! I bet it feels good, lets start with the basics!\n");
  printf("To get you started off let's get you some seeds.\n");
  printf("Wildflower seeds +1!\n");
  printf("\n\n\n");

  wildFlowerart(); // PRINT WILDFLOWERS
  printf("\n\n\n");

  *wildFlowerSeeds = 1;

  printf("Every time you enter your farm you will have the option to plant your seeds!\n");
  printf("Here are some basic tools to start your farm!\n");
  printf("Water Can +1!\nShovel +1!\nHoe +1!\n");
  printf("These tools aren't going to stay forever, they will eventually break.\n");
  printf("When they do you'll have the option to go into town and buy new ones from the merchant or take it to the blacksmith.\n\n\n");

  *shovel = 25;
  *hoe = 25;
  *waterCan = 25;

  printf("Oh? You stepped on something...?\n");
  printf("You pick up a strange bottle, it has a strange label on it...?\n");
  printf(BLUE "Meow\n\n" RESET);
  printf("..?\n\n");
  printf("Do you decide to drink the elixir? (y for yes n for no): \n");
  scanf(" %c", &elixir);

  while (elixir != 'y' && elixir != 'n')
  {
    printf("Incorrect input try again!\n");
    printf("Do you decide to drink the elixir? (y for yes n for no): \n");
    scanf(" %c", &elixir);
  }

  printf("You open up the bottle to check it and suddenly... A CAT?!\n");
  printf("The bottle hits your mouth and you're forced to drink the elixir!\n");
  printf("\n\n\n");

  miloart(); // PRINT MILO ART 

  printf("\n\n\n");
  printf(BLUE "Hello I am Milo! Welcome to the world of cats!\n\n" RESET);
  printf("The elixir must have given you the ability to hear cats talk?!\n\n");
  printf(BLUE "You must be quite surprised, I am a cat, WHO TALKS!\n");
  printf("Well that's what the elixir did to ya!\n");
  printf("Anywho, let's get this farm started!\n");
  printf("Let's try planting the seeds we currently have!\n" RESET);

  plantSeeds(tomatoSeeds, wildFlowerSeeds, sugarCaneSeeds, radishSeeds, potatoSeeds);

  printf(BLUE "We successfully got seeds planted! Let's make our way into town to meet some new friends!\n" RESET);
  printf("\nReady to head into town and begin Day 2? (y to continue): ");
  scanf(" %c", &cont);

  while (cont != 'y' && cont != 'Y')
  {
    printf("You hesitate... but there's nothing else to do here.\n");
    printf("Press 'y' to continue: ");
    scanf(" %c", &cont);
  }

  printf("\nYou leave your farm and head toward town...\n");
}
