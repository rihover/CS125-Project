/*****************************************************************************************************
*File:      villagers.c
*Purpose:   All code for villager movement.
*Version:   1.0 April 2, 2026 - Psuedo in word doc of how to build functions
*           1.1 April 4, 2026 - Dedicated to building this file (Began running all file to test game)
*Resources: 
******************************************************************************************************/
#include <stdlib.h>
#include "villagers.h"

void initializeVillagers(Villager villagers[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        villagers[i].row = 0;
        villagers[i].col = 0;
        villagers[i].symbol = 'V';
    }
}

void randomizeVillagers(Villager villagers[], int count, int maxRows, int maxCols)
{
    int i, j;
    int duplicate;

    for (i = 0; i < count; i++)
    {
        do
        {
            duplicate = 0;
            villagers[i].row = rand() % maxRows;
            villagers[i].col = rand() % maxCols;

            for (j = 0; j < i; j++)
            {
                if (villagers[i].row == villagers[j].row &&
                    villagers[i].col == villagers[j].col)
                {
                    duplicate = 1;
                }
            }
        } while (duplicate);
    }
}

void clearWorldMap(char world[][10], int maxRows, int maxCols)
{
    int row, col;

    for (row = 0; row < maxRows; row++)
    {
        for (col = 0; col < maxCols; col++)
        {
            world[row][col] = '.';
        }
    }
}

void placeVillagersOnMap(char world[][10], Villager villagers[], int count, int maxRows, int maxCols)
{
    int i;

    clearWorldMap(world, maxRows, maxCols);

    for (i = 0; i < count; i++)
    {
        world[villagers[i].row][villagers[i].col] = villagers[i].symbol;
    }
}
