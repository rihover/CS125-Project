/*******************************************************************************************
*File:      MAPcontrols.C
*Author:    Elizabeth Huffman & Rihanna Overbaugh
*Purpose:   Basically the main function for farming sim game 
*              - runs map controls
*              - has UI for choosing options for game
*Version:   1.0 March 26, 2026 - Puesdocode
*           1.1 March 31, 2026 - Basic code 
*           1.2 April 2, 2026 - Focused on the UI for movinf and opening maps 
*           1.3 April 4, 2026 - Finished code and began testing game. 
*           1.4 April 5, 2026 - Debugging
*Resources: Debugging in Online GDB and Moba, help with debugging void functions in ChatGPT
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MAPcontrols.h"
#include "villager.h"

#define mapRows 10
#define mapColumns 10

#define FARM 0
#define WORLD 1

void runMainGame(char playerName[], char farmName[],
                 int tomatoSeeds, int wildFlowerSeeds, int sugarCaneSeeds,
                 int radishSeeds, int potatoSeeds,
                 int shovel, int hoe, int waterCan,
                 int day)
{
    char farmMap[mapRows][mapColumns];
    char worldMap[mapRows][mapColumns];

    Villager villagers[NUM_VILLAGERS];

    int playerRow = 0;
    int playerCol = 0;
    int currentMap = FARM;
    int choice;
    int running = 1;

    int r, c;

    srand(time(NULL));

    /* Initialize maps */
    for (r = 0; r < mapRows; r++)
    {
        for (c = 0; c < mapColumns; c++)
        {
            farmMap[r][c] = '.';
            worldMap[r][c] = '.';
        }
    }

    /* Initialize villagers */
    initializeVillagers(villagers, NUM_VILLAGERS);
    randomizeVillagers(villagers, NUM_VILLAGERS, mapRows, mapColumns);
    placeVillagersOnMap(worldMap, villagers, NUM_VILLAGERS, mapRows, mapColumns, day);

    while (running)
    {
        printf("\n=== Day %d ===\n", day);
        printf("Player: %s | Farm: %s\n\n", playerName, farmName);

        /* Print map */
        for (r = 0; r < mapRows; r++)
        {
            for (c = 0; c < mapColumns; c++)
            {
                if (r == playerRow && c == playerCol)
                {
                    printf("P ");
                }
                else if (currentMap == FARM)
                {
                    printf("%c ", farmMap[r][c]);
                }
                else
                {
                    printf("%c ", worldMap[r][c]);
                }
            }
            printf("\n");
        }

        printf("\n");
        printf("1 Move\n");
        printf("2 Switch Map\n");
        printf("3 End Day\n");
        printf("4 Exit Game\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                playerRow = (playerRow + 1) % mapRows;
                break;

            case 2:
                if (currentMap == FARM)
                {
                    currentMap = WORLD;
                    printf("You traveled to the world.\n");
                }
                else
                {
                    currentMap = FARM;
                    printf("You returned to the farm.\n");
                }

                playerRow = 0;
                playerCol = 0;
                break;

            case 3:
                day++;

                randomizeVillagers(villagers, NUM_VILLAGERS, mapRows, mapColumns);
                placeVillagersOnMap(worldMap, villagers, NUM_VILLAGERS, mapRows, mapColumns, day);

                printf("A new day begins...\n");
                break;

            case 4:
                running = 0;
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return;
}
