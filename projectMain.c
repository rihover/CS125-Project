/****************************************************
 * Authors: Rihanna Overbaugh and Elizabeth Huffman
 * File: projectMain.c
 * Version: 1.0 3/4/26 (created main)
            1.1 3/5/26 (added naming functions and tutorial)
            1.2 3/11/26 (added error handling for elixir choice) 
            1.3 3/12/26 (getting farm ascii to print, and debugging)  
            1.4 3/24/26 (Added plant seeds function) 
****************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#define BLUE "\033[34m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

char name[15];
char farm[20];

void farmart();
void plantSeeds();


char playerName(char name[])
{
  while (strlen(name) > 15) 
    { 
      printf("Too many characters try again! \n");
      printf("Enter your name (Maximum of 15 characters): \n");
      scanf("%s", name);
    }
  return name[15];
}

char farmName(char farm[])
{
  while (strlen(farm) > 20)
    {
      printf("Too many characters try again! \n");
      printf("Enter your farm name (Maximum of 20 characters): \n");
      scanf("%s", farm);
    }
  return farm[20];
}



int main()
{
  int tomatoSeeds;
  int wildFlowerSeeds;
  int radishSeeds; 
  int sugarCaneSeeds; 
  int potatoSeeds;
  int tools[3]; 
  int hoe; 
  int shovel; 
  int waterCan; 
  char elixir;
  
  
  // NAME
  printf("Welcome to The World of Cats! \n");
  printf("Enter your name (Maximum of 15 characters): \n");
  scanf("%s", name); 
  name[15] = playerName(name); 
  
  printf("Enter a farm name (Maximum of 20 characters): \n");
  scanf("%s", farm); 
  farm[20] = farmName(farm); 
  
  // TUTORIAL AND START OF GAME
  printf("Welcome to %s! Here is a look at your farm! \n", farm);
  printf(" \n \n \n");

  //farmart();
  
  printf("\n \n \n");
  printf("Today is your first day of owning a farm! I bet it feels good, lets start with the basics! \n"); 
  printf("To you started off let's get you some seeds. \n"); 
  printf("Wildflower seeds +1! \n");
  // Open the txt wildflower file here for ascii art. 
  wildFlowerSeeds = 1; 
  printf("Everytime you enter your farm you will have the option to plant your seeds! \n"); 
  printf("Here are some basic tools to start your farm! \n");
  printf("Water Can +1! \nShovel +1! \nHoe +1! \n"); 
  printf("These tools aren't going to stay forever, they will eventually break.\n");
  printf("When they do you'll have the option to go into town and buy new ones from the merchant or take it to the blacksmith. \n \n \n");
  
  // Uses for the tools 
  shovel = 25; 
  hoe = 25; 
  waterCan =25; 
  tools = [25 25 25];
  
  printf("Oh? You stepped on something...? \n"); 
  printf("You pick up a strange bottle, it has a strange label on it...? \n");
  printf(BLUE);
  printf("Meow \n \n");
  printf(RESET);
  printf("..? \n \n");
  printf("Do you decide to drink the elixir? (y for yes n for no): \n");
  scanf("%c", &elixir); 
  
  while (elixir != 'y' && elixir != 'n') { 
    printf("Incorrect input try again! \n");
    printf("Do you decide to drink the elixir? (y for yes n for no): \n");
    scanf("%c", &elixir);
  }
  printf("You open up the bottle to check it and suddenly... A CAT?! \n");
  printf("The bottle hits your mouth and you're forced to drink the elixir! \n");
  
  // Open txt file for cat here 
  printf(BLUE); 
  printf("Hello I am Milo! Welcome to the world of cats! \n"); 
  printf(RESET); 
  printf("The elixir must have given you the ability to hear cats talk?! \n");
  printf(BLUE); 
  printf("You must be quite surprised, I am a cat, WHO TALKS! \n"); 
  printf("Well that's what the elixir did to ya! \n"); 
  printf("Anywho, let's get this farm started! \n"); 
  printf("Let's try planting the seeds we currently have! \n");
  printf(RESET); 
  // plantSeeds();
  
  printf(BLUE) 
  printf("We sucessfully got seeds planted! Let's make our way into town to meet some new frieds! \n"); 
  printf("
  
  
  
  
    
return 0;
} 
