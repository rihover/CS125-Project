/****************************************************
 * Authors: Rihanna Overbaugh and Elizabeth Huffman
 * File: projectMain.c
 * Version: 1.0 3/4/26 (created main)
            1.1 3/5/26 (added naming functions) 
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
  
  printf("Welcome to ________ \n");
  printf("Enter your name (Maximum of 15 characters): \n");
  scanf("%s", name); 
  playerName() // Have to fix how the function and where it is called.
  
  printf("Enter a farm name (Maximum of 20 characters): \n");
  scanf("%s", farm); 
  farmName() // HAve to fix where it is called
  
  printf("Today is your first day of owning a farm! I bet it feels good, lets start with the basics! \n"); 
  printf("To you started off let's get you some seeds. \n"); 
  printf("Tomato seeds +1! \n"); 
  tomatoSeeds = 1; 
  
  
  
  
  
