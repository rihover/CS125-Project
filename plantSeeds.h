#pragma once

typedef struct {
    int tomato;
    int wildFlower;
    int radish;
    int sugarCane;
    int potato;
} Planted;

void plantSeeds(int *tomatoSeeds, int *wildFlowerSeeds, int *radishSeeds, int *sugarCaneSeeds, int *potatoSeeds);
char plantSeed_error(char plant);
