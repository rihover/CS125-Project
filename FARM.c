/****************************************************
* Authors: Rihanna Overbaugh and Elizabeth Huffman
* File: FARM.c
* Version: 1.0 3/5/26 (Started reading in player view of farm)
****************************************************/

#include<stdio.h>

int main()
{
char farm_house[400];
int i;
FILE* f=fopen("FARM.txt","r");
for (i=0; i<=7; i++)
{
fgets(farm_house, 400, f);
printf("%s", farm_house);
}
return 0;
}