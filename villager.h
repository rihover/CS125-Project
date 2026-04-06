/************************************************************************************************************* 
*File:      villager.h 
*Author:    Elizabeth Huffman & Rihanna Overbaugh
*Purpose:   header file recquired for project 
*             - helps villager movement (randommizes everyday)
*Version:   1.0 Mar 31, 2026 - Created the file
*           1.1 April 2, 2026 - Began buidling, ran into trouble 
*Resources: Ran it through ChatGPT and asked for help because of errors, had just initialized functions wrong. (the villager and tutorial headers gave us the most trouble)
*           FOR ALL HEADERS:
*             - (https://www.youtube.com/watch?v=oe11Dhw9dOg) -> Understanding header files in c by theurbanpenguin
**************************************************************************************************************/
#ifndef VILLAGER_H
#define VILLAGER_H

#define NUM_VILLAGERS 5 // 5 villagers includes 3 normal villagers, milo (only in tutorial), and luna the merchant

typedef struct
{
  int row;
  int col;
  char symbol;
  int tutorialOnly;
} Villager;

void initializeVillagers(Villager v[], int count);
void randomizeVillagers(Villager v[], int count, int rows, int cols);
void placeVillagersOnMap(char world[][10], Villager v[], int count, int rows, int cols, int day);
void talkToVillager(Villager v[], int count, int row, int col, int day);

#endif
