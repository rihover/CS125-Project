/****************************************************
 * Authors: Rihanna Overbaugh and Elizabeth Huffman
 * File: projectMain.c
 * Version: 1.0 3/4/26 (created main)
            1.1 3/5/26 (added naming functions and tutorial) 
****************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>

char playerName(*name)
{
  while strlen(name) > 15 
    { 
      printf("Too many characters try again! \n");
      printf("Enter your name (Maximum of 15 characters): \n");
      scanf("%s", name);
    }
}

char farmName(*farm)
{
  while strlen(farm) > 20 
    {
      printf("Too many characters try again! \n");
      printf("Enter your name (Maximum of 15 characters): \n");
      scanf("%s", name);
    }
}



int main()
{
  char *name[15];
  char *farm[20];
  int tomatoSeeds;
  int wildFlowerSeeds;
  int radishSeeds; 
  int sugarCaneSeeds; 
  int potatoSeeds;
  int hoe; 
  int shovel; 
  int waterCan; 
  
  printf("Welcome to ______ \n");
  printf("Enter your name (Maximum of 15 characters): \n");
  scanf("%s", name); 
  playerName() // Have to fix how the function and where it is called.
  
  printf("Enter a farm name (Maximum of 20 characters): \n");
  scanf("%s", farm); 
  farmName() // HAve to fix where it is called
  
  // TUTORIAL AND START OF GAME
  printf("Welcome to %s! Here is a look at your farm! \n", farm);
  // Open the txt file here.
  printf("Today is your first day of owning a farm! I bet it feels good, lets start with the basics! \n"); 
  printf("To you started off let's get you some seeds. \n"); 
  printf("Wildflower seeds +1! \n");
  // Open the txt wildflower file here for ascii art. 
  wildFlowerSeeds = 1; 
  printf("Everytime you enter your farm you will have the option to plant your seeds! \n"); 
  printf("Here are some basic tools to start your farm! \n");
  printf("Water Can +1! \nShovel +1! \nHoe +1! \n"); 
  printf("These tools aren't going to stay forever, they will eventually break.\n");
  printf("When they do you'll have the option to go into town and buy new ones from the merchant or take it to the blacksmith. \n");
  
  
  
  
  
