/***********************************************************
 * File Name: merchant.c
 * Authors: Rihanna Overbaugh and Eilzabeth Huffman
 * Version: 1.0 4/1/26
************************************************************/
#include <stdio.h> 
#include "merchant.h" 

#define RESET "\033[0m"
#define YELLOW "\033[33m"

void merchant()
{ 
  int buy_sell;
  int buyseeds;

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
    if 
