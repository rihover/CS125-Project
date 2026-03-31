#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAP_ROWS 8
#define MAP_COLS 8

#define MAX_NAME_LEN 30
#define NUM_CROPS 5
#define NUM_VILLAGERS 3

/* Function Prototypes */
/* Prints the title screen */
void printTitleScreen(void);

/* Prints the game instructions */
void printInstructions(void);

/* Initializes the farm grid and village map */
void initializeGame(char farm[MAP_ROWS][MAP_COLS], char world[MAP_ROWS][MAP_COLS]);

/* Displays the farm and world map */
void printWorld(char farm[MAP_ROWS][MAP_COLS], char world[MAP_ROWS][MAP_COLS], int playerRow, int playerCol);

/* Displays the current player stats */
void printStats(int day, int gold, int seeds, int harvested);

/* Handles planting on the farm */
void plantCrop(char farm[MAP_ROWS][MAP_COLS], int *seeds);

/* Handles watering crops */
void waterCrop(char farm[MAP_ROWS][MAP_COLS]);

/* Advances crops to the next day */
void nextDay(char farm[MAP_ROWS][MAP_COLS], int *gold, int *harvested);

/* Checks if the player meets a villager */
void checkVillagerEncounter(char world[MAP_ROWS][MAP_COLS], int playerRow, int playerCol);

/* Prints a dialogue popup box */
void dialoguePopup(const char *speaker, const char *message);

/* Moves the player */
void movePlayer(char input, int *playerRow, int *playerCol);

/* Clears input buffer */
void clearInputBuffer(void);

/* Gets crop symbol based on growth stage */
char growCrop(char currentStage);

/* Main */
int main(void)
{
    char farm[MAP_ROWS][MAP_COLS];
    char world[MAP_ROWS][MAP_COLS];

    int day = 1;
    int gold = 20;
    int seeds = 5;
    int harvested = 0;

    int playerRow = 0;
    int playerCol = 0;

    int running = 1;
    int choice;
    char moveChoice;

    printTitleScreen();
    printInstructions();
    initializeGame(farm, world);

    while (running)
    {
        printWorld(farm, world, playerRow, playerCol);
        printStats(day, gold, seeds, harvested);

        printf("\nChoose an action:\n");
        printf("1. Plant crop\n");
        printf("2. Water crop\n");
        printf("3. Next day\n");
        printf("4. Move around village\n");
        printf("5. Buy seed ($3)\n");
        printf("0. Quit game\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            printf("Invalid input.\n");
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                plantCrop(farm, &seeds);
                break;

            case 2:
                waterCrop(farm);
                break;

            case 3:
                nextDay(farm, &gold, &harvested);
                day++;
                break;

            case 4:
                printf("Move with W A S D: ");
                scanf(" %c", &moveChoice);
                clearInputBuffer();

                moveChoice = (char)tolower(moveChoice);
                movePlayer(moveChoice, &playerRow, &playerCol);
                checkVillagerEncounter(world, playerRow, playerCol);
                break;

            case 5:
                if (gold >= 3)
                {
                    gold -= 3;
                    seeds++;
                    printf("You bought 1 seed.\n");
                }
                else
                {
                    printf("Not enough gold.\n");
                }
                break;

            case 0:
                running = 0;
                printf("Thanks for playing!\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}

/* Prints the title screen */
void printTitleScreen(void)
{
    printf("=========================================\n");
    printf("         FARMING SIMULATOR GAME\n");
    printf("=========================================\n");
}

/* Prints the instructions */
void printInstructions(void)
{
    printf("\nInstructions:\n");
    printf("- Plant seeds in empty farm plots.\n");
    printf("- Water planted crops so they can grow.\n");
    printf("- Advance to the next day to grow crops.\n");
    printf("- Fully grown crops are harvested automatically for gold.\n");
    printf("- Move around the village and meet villagers.\n");
    printf("- Talking to villagers shows dialogue pop-up boxes.\n\n");
}

/* Initializes the farm and world */
void initializeGame(char farm[MAP_ROWS][MAP_COLS], char world[MAP_ROWS][MAP_COLS])
{
    int row, col;

    for (row = 0; row < MAP_ROWS; row++)
    {
        for (col = 0; col < MAP_COLS; col++)
        {
            farm[row][col] = '.';
            world[row][col] = '.';
        }
    }

    /* Place villagers on the world map */
    world[2][3] = 'A';  /* Anna */
    world[5][1] = 'B';  /* Ben */
    world[6][6] = 'C';  /* Clara */
}

/* Prints the world and farm */
void printWorld(char farm[MAP_ROWS][MAP_COLS], char world[MAP_ROWS][MAP_COLS], int playerRow, int playerCol)
{
    int row, col;

    printf("\n========== FARM ==========\n");
    printf("Legend: . = Empty, s = Seed, w = Watered, G = Grown\n\n");

    for (row = 0; row < MAP_ROWS; row++)
    {
        for (col = 0; col < MAP_COLS; col++)
        {
            printf("%c ", farm[row][col]);
        }
        printf("\n");
    }

    printf("\n========= VILLAGE =========\n");
    printf("Legend: P = Player, A/B/C = Villagers, . = Empty\n\n");

    for (row = 0; row < MAP_ROWS; row++)
    {
        for (col = 0; col < MAP_COLS; col++)
        {
            if (row == playerRow && col == playerCol)
            {
                printf("P ");
            }
            else
            {
                printf("%c ", world[row][col]);
            }
        }
        printf("\n");
    }
}

/* Prints player stats */
void printStats(int day, int gold, int seeds, int harvested)
{
    printf("\nDay: %d\n", day);
    printf("Gold: %d\n", gold);
    printf("Seeds: %d\n", seeds);
    printf("Harvested Crops: %d\n", harvested);
}

/* Plants a crop in a chosen location */
void plantCrop(char farm[MAP_ROWS][MAP_COLS], int *seeds)
{
    int row, col;

    if (*seeds <= 0)
    {
        printf("You have no seeds left.\n");
        return;
    }

    printf("Enter row to plant (0-%d): ", MAP_ROWS - 1);
    scanf("%d", &row);
    printf("Enter col to plant (0-%d): ", MAP_COLS - 1);
    scanf("%d", &col);
    clearInputBuffer();

    if (row < 0 || row >= MAP_ROWS || col < 0 || col >= MAP_COLS)
    {
        printf("Invalid location.\n");
        return;
    }

    if (farm[row][col] == '.')
    {
        farm[row][col] = 's';
        (*seeds)--;
        printf("You planted a seed.\n");
    }
    else
    {
        printf("That plot is not empty.\n");
    }
}

/* Waters a crop */
void waterCrop(char farm[MAP_ROWS][MAP_COLS])
{
    int row, col;

    printf("Enter row to water (0-%d): ", MAP_ROWS - 1);
    scanf("%d", &row);
    printf("Enter col to water (0-%d): ", MAP_COLS - 1);
    scanf("%d", &col);
    clearInputBuffer();

    if (row < 0 || row >= MAP_ROWS || col < 0 || col >= MAP_COLS)
    {
        printf("Invalid location.\n");
        return;
    }

    if (farm[row][col] == 's')
    {
        farm[row][col] = 'w';
        printf("You watered the crop.\n");
    }
    else
    {
        printf("There is no dry seed there to water.\n");
    }
}

/* Advances all crops by one day */
void nextDay(char farm[MAP_ROWS][MAP_COLS], int *gold, int *harvested)
{
    int row, col;

    printf("\nA new day begins...\n");

    for (row = 0; row < MAP_ROWS; row++)
    {
        for (col = 0; col < MAP_COLS; col++)
        {
            if (farm[row][col] == 'w')
            {
                farm[row][col] = 'G';
            }
            else if (farm[row][col] == 'G')
            {
                farm[row][col] = '.';
                *gold += 10;
                (*harvested)++;
                printf("A crop was harvested for $10.\n");
            }
        }
    }
}

/* Checks if player stepped onto a villager */
void checkVillagerEncounter(char world[MAP_ROWS][MAP_COLS], int playerRow, int playerCol)
{
    char tile = world[playerRow][playerCol];

    if (tile == 'A')
    {
        dialoguePopup("Anna", "Good morning! The tomatoes grow best when watered every day.");
    }
    else if (tile == 'B')
    {
        dialoguePopup("Ben", "I trade seeds for gold. Farming takes patience, friend.");
    }
    else if (tile == 'C')
    {
        dialoguePopup("Clara", "The village feels brighter when the fields are full.");
    }
}

/* Prints a dialogue popup */
void dialoguePopup(const char *speaker, const char *message)
{
    printf("\n+----------------------------------------+\n");
    printf("| Dialogue                               |\n");
    printf("+----------------------------------------+\n");
    printf("| %s\n", speaker);
    printf("| \"%s\"\n", message);
    printf("+----------------------------------------+\n");
}

/* Moves the player on the village map */
void movePlayer(char input, int *playerRow, int *playerCol)
{
    if (input == 'w' && *playerRow > 0)
    {
        (*playerRow)--;
    }
    else if (input == 's' && *playerRow < MAP_ROWS - 1)
    {
        (*playerRow)++;
    }
    else if (input == 'a' && *playerCol > 0)
    {
        (*playerCol)--;
    }
    else if (input == 'd' && *playerCol < MAP_COLS - 1)
    {
        (*playerCol)++;
    }
    else
    {
        printf("You cannot move there.\n");
    }
}

/* Clears leftover input */
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
