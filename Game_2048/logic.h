#include <string.h>
#include <stdlib.h>

#define sizeMass 4

int ScoreOnNum(int score);
int randNum(int numMax);
int GameMass(int score);
int NewNumOnField(int** GameField, int score);
int shiftWASD(int** gameMass, int tmp);