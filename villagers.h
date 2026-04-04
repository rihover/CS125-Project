/************************************************************************************************************* 
*File:      villagers.h 
*Author:    Elizabeth Huffman & Rihanna Overbaugh
*Purpose:   header file recquired for project (we actually have three lol)
*             - helps villager movement (randommizes everyday)
*Version:   1.0 Mar 31, 2026 - Created the file
*           1.1 April 2, 2026 - Began buidling, ran into trouble 
*Resources: Ran it through ChatGPT and asked for help because of errors, had just initialized functions wrong.
*             - Watched YouTube video posted with header file lecture () to remember how to build one.
**************************************************************************************************************/
#ifndef VILLAGER_H
#define VILLAGER_H

#define NUM_VILLAGERS 5

typedef struct
{
    int row;
    int col;
    char symbol;
} Villager;

void initializeVillagers(Villager villagers[], int count);
void randomizeVillagers(Villager villagers[], int count, int maxRows, int maxCols);
void placeVillagersOnMap(char world[][10], Villager villagers[], int count, int maxRows, int maxCols);
void clearWorldMap(char world[][10], int maxRows, int maxCols);

#endif
