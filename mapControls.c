/************************************************************************** 
*File:      MAPcontrols.C
*Author:    Elizabeth Huffman & Rihanna Overbaugh
*Purpose:   Basically the main function for farming sim game 
*              - runs map controls
*              - has UI for choosing options for game
*Version:   1.0 Mar 26, 2026 - Puesdocode
*           1.1 Mar 31, 2026 - Basic code 
*           1.2 Mar 2, 2026 - Focused on the UI for movinf and opening maps 
*           1.3 Mar 4, 2026 - Finished code and began testing game. 
*Resources: Debugging in Online GDB and
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "villagers.h"

#define mapRows 10
#define mapColumns 10

#define FARM_MAP  0
#define WORLD_MAP 1

#define BLUE  "\033[34m"
#define RESET "\033[0m"
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

void initializeMap(char map[mapRows][mapColumns]);
void printCurrentMap(char farmMap[mapRows][mapColumns], char worldMap[mapRows][mapColumns],
                     int currentMap, int playerRow, int playerCol);
void printMenu(int currentMap);
void plantCrop(char farmMap[mapRows][mapColumns], int playerRow, int playerCol);
void waterCrop(char farmMap[mapRows][mapColumns], int playerRow, int playerCol);
void movePlayer(int *playerRow, int *playerCol);
void endDay(char farmMap[mapRows][mapColumns], char worldMap[mapRows][mapColumns],
            Villager villagers[], int count, int day);
void switchMaps(int *currentMap, int *playerRow, int *playerCol);

int main(void)
{
    char farmMap[mapRows][mapColumns];
    char worldMap[mapRows][mapColumns];
    Villager villagers[NUM_VILLAGERS];

    int playerRow = 0;
    int playerCol = 0;
    int currentMap = FARM_MAP;
    int choice;
    int running = 1;
    int day = 1;

    srand(time(NULL));

    initializeMap(farmMap);
    initializeMap(worldMap);

    initializeVillagers(villagers, NUM_VILLAGERS);

    /* villagers should only begin on day 2 and only on world map */
    if (day >= 2)
    {
        randomizeVillagers(villagers, NUM_VILLAGERS, mapRows, mapColumns);
        placeVillagersOnMap(worldMap, villagers, NUM_VILLAGERS, mapRows, mapColumns);
    }

    while (running)
    {
        printf("\nDay %d\n", day);
        printCurrentMap(farmMap, worldMap, currentMap, playerRow, playerCol);
        printMenu(currentMap);

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (currentMap == FARM_MAP)
                    plantCrop(farmMap, playerRow, playerCol);
                else
                    printf("You can only plant on the farm map.\n");
                break;

            case 2:
                if (currentMap == FARM_MAP)
                    waterCrop(farmMap, playerRow, playerCol);
                else
                    printf("You can only water crops on the farm map.\n");
                break;

            case 3:
                movePlayer(&playerRow, &playerCol);
                break;

            case 4:
                switchMaps(&currentMap, &playerRow, &playerCol);
                break;

            case 5:
                day++;
                endDay(farmMap, worldMap, villagers, NUM_VILLAGERS, day);
                break;

            case 6:
                running = 0;
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void initializeMap(char map[mapRows][mapColumns])
{
    int row, col;

    for (row = 0; row < mapRows; row++)
    {
        for (col = 0; col < mapColumns; col++)
        {
            map[row][col] = '.';
        }
    }
}

void printCurrentMap(char farmMap[mapRows][mapColumns], char worldMap[mapRows][mapColumns],
                     int currentMap, int playerRow, int playerCol)
{
    int row, col;

    if (currentMap == FARM_MAP)
        printf(GREEN "\nFARM MAP\n" RESET);
    else
        printf(YELLOW "\nWORLD MAP\n" RESET);

    printf("   ");
    for (col = 0; col < mapColumns; col++)
    {
        printf("%d ", col);
    }
    printf("\n");

    for (row = 0; row < mapRows; row++)
    {
        printf("%d  ", row);
        for (col = 0; col < mapColumns; col++)
        {
            if (row == playerRow && col == playerCol)
            {
                printf(BLUE "P " RESET);
            }
            else if (currentMap == FARM_MAP)
            {
                if (farmMap[row][col] == 'C')
                    printf(GREEN "C " RESET);
                else if (farmMap[row][col] == 'W')
                    printf(BLUE "W " RESET);
                else if (farmMap[row][col] == 'H')
                    printf(YELLOW "H " RESET);
                else
                    printf(". ");
            }
            else
            {
                if (worldMap[row][col] == 'V')
                    printf(RED "V " RESET);
                else if (worldMap[row][col] == 'M')
                    printf(YELLOW "M " RESET);
                else
                    printf(". ");
            }
        }
        printf("\n");
    }
}

void printMenu(int currentMap)
{
    printf("\n1. Plant crop\n");
    printf("2. Water crop\n");
    printf("3. Move player\n");
    printf("4. Switch maps\n");
    printf("5. End day\n");
    printf("6. Exit game\n");

    if (currentMap == FARM_MAP)
        printf("You are on the farm map.\n");
    else
        printf("You are on the world map.\n");
}

void plantCrop(char farmMap[mapRows][mapColumns], int playerRow, int playerCol)
{
    if (farmMap[playerRow][playerCol] == '.')
    {
        farmMap[playerRow][playerCol] = 'C';
        printf("You planted a crop.\n");
    }
    else
    {
        printf("You cannot plant here.\n");
    }
}

void waterCrop(char farmMap[mapRows][mapColumns], int playerRow, int playerCol)
{
    if (farmMap[playerRow][playerCol] == 'C')
    {
        farmMap[playerRow][playerCol] = 'W';
        printf("You watered the crop.\n");
    }
    else if (farmMap[playerRow][playerCol] == 'W')
    {
        printf("This crop is already watered.\n");
    }
    else
    {
        printf("There is no crop here.\n");
    }
}

void movePlayer(int *playerRow, int *playerCol)
{
    char move;

    printf("Move with W A S D: ");
    scanf(" %c", &move);

    if ((move == 'w' || move == 'W') && *playerRow > 0)
        (*playerRow)--;
    else if ((move == 's' || move == 'S') && *playerRow < mapRows - 1)
        (*playerRow)++;
    else if ((move == 'a' || move == 'A') && *playerCol > 0)
        (*playerCol)--;
    else if ((move == 'd' || move == 'D') && *playerCol < mapColumns - 1)
        (*playerCol)++;
    else
        printf("Invalid move.\n");
}

void switchMaps(int *currentMap, int *playerRow, int *playerCol)
{
    if (*currentMap == FARM_MAP)
    {
        *currentMap = WORLD_MAP;
        printf("You traveled to the world map.\n");
    }
    else
    {
        *currentMap = FARM_MAP;
        printf("You traveled back to the farm map.\n");
    }

    *playerRow = 0;
    *playerCol = 0;
}

void endDay(char farmMap[mapRows][mapColumns], char worldMap[mapRows][mapColumns],
            Villager villagers[], int count, int day)
{
    int row, col;

    for (row = 0; row < mapRows; row++)
    {
        for (col = 0; col < mapColumns; col++)
        {
            if (farmMap[row][col] == 'W')
            {
                farmMap[row][col] = 'H';
            }
        }
    }

    if (day >= 2)
    {
        randomizeVillagers(villagers, count, mapRows, mapColumns);
        placeVillagersOnMap(worldMap, villagers, count, mapRows, mapColumns);
    }

    printf("Day ended.\n");
}
