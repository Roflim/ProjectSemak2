#include "logic.h"
#include "Field.h"
#include <stdio.h>

int ScoreOnNum(int score) {
	if (score < 300)
		return 0;
	if (score < 600)
		return 1;
	if (score < 800)
		return 2;
	if (score < 1000)
		return 3;
	if (score < 1300)
		return 4;
	if (score < 2000)
		return 5;
	if (score < 2500)
		return 6;
	if (score < 4000)
		return 7;
	if (score < 5000)
		return 8;
} //расчет цифр исходя изходя из score

int GameMass(int score) {
	int** gameField = (int**)calloc(sizeMass, sizeof(int*));
	for (int i = 0; i < sizeMass; i++) {
		gameField[i] = (int*)calloc(sizeMass, sizeof(int));
	}
	NewNumOnField(gameField, score);
	NewNumOnField(gameField, score);
	return(gameField);
}//создание двумерного массива для данных

int NewNumOnField(int** GameField, int score) {
	int getNumOnField[] = { 2,4,8,16,32,64,128,256 };
	int counter = 0;
	int tmpNum1 = 0;
	int tmpNum2 = 0;
	int tmpNum3 = 0;
	for (int i = 0; i < sizeMass; i++) {
		for (int j = 0; j < sizeMass; j++) {
			if (GameField[i][j] == 0)
				counter++;
		}
	}//счет свободных мест

	if (counter > 9) {
		do {
			tmpNum1 = GetRandomValue(0, sizeMass - 1);
			for (int i = 0; i < sizeMass; i++) {
				if (GameField[tmpNum1][i] == 0)
					tmpNum2++;
			}
		} while (tmpNum2 == 0);
		tmpNum3 = tmpNum2;
		tmpNum2 = GetRandomValue(0, tmpNum3 - 1);
		if (GameField[tmpNum1][tmpNum2] == 0) {
			GameField[tmpNum1][tmpNum2] = getNumOnField[GetRandomValue(0, ScoreOnNum(score))];
		}
	}//рандомное доб. числа если counter больше 10
	else {
		tmpNum2 = 0;
		tmpNum1 = GetRandomValue(0, counter);
		for (int i = 0; i < sizeMass; i++) {
			for (int j = 0; j < sizeMass; j++) {
				if (GameField[i][j] == 0) {
					tmpNum2++;
					if (tmpNum1 == tmpNum2) {
						GameField[i][j] = getNumOnField[GetRandomValue(0, ScoreOnNum(score))];
					}
				}
			}
		}
	}//рандомное доб. числа если counter меньше 10

}

int shiftWASD(int** gameMass, int tmp) {
	int tmpNum1 = 0;
	int score = 0;
	if (tmp == 1) {
		for (int j = 0; j < (sizeMass); ++j) {
			do {
				tmpNum1 = 0;
				for (int i = 0; i < (sizeMass - 1); ++i) {
					if (gameMass[i][j] == 0 && gameMass[i + 1][j] != 0) {
						tmpNum1 = 1;
					}
					if (gameMass[i][j] == 0 && gameMass[i + 1][j] != 0) {
						gameMass[i][j] = gameMass[i + 1][j];
						gameMass[i + 1][j] = 0;
					}
				}
			} while (tmpNum1 == 1);
		}
		for (int j = 0; j < (sizeMass); ++j) {
			for (int i = 0; i < (sizeMass - 1); ++i) {
				if (gameMass[i][j] != 0) {
					if (gameMass[i][j] == gameMass[i + 1][j]) {
						gameMass[i][j] += gameMass[i + 1][j];
						score += gameMass[i + 1][j];
						gameMass[i + 1][j] = 0;
						--i;
					}
				}
			}
		}
	}
	if (tmp == 2) {
		for (int i = 0; i < sizeMass; ++i) {
			do {
				tmpNum1 = 0;
				for (int j = 0; j < (sizeMass - 1); ++j) {
					if (gameMass[i][j] == 0 && gameMass[i][j + 1] != 0) {
						tmpNum1 = 1;
					}
					if (gameMass[i][j] == 0 && gameMass[i][j + 1] != 0) {
						gameMass[i][j] = gameMass[i][j + 1];
						gameMass[i][j + 1] = 0;
					}
				}

			} while (tmpNum1 == 1);
		}
		for (int i = 0; i < sizeMass; ++i) {
			for (int j = 0; j < (sizeMass - 1); ++j) {
				if (gameMass[i][j] != 0) {
					if (gameMass[i][j] == gameMass[i][j + 1]) {
						gameMass[i][j] += gameMass[i][j + 1];
						score += gameMass[i][j + 1];
						gameMass[i][j + 1] = 0;
						--j;
					}
				}
			}
		}
	}
	if (tmp == 3) {
		for (int j = 0; j < sizeMass; ++j) {
			do {
				tmpNum1 = 0;
				for (int i = (sizeMass - 1); i > 0; --i) {
					if (gameMass[i][j] == 0 && gameMass[i - 1][j] != 0) {
						tmpNum1 = 1;
					}
					if (gameMass[i][j] == 0 && gameMass[i - 1][j] != 0) {
						gameMass[i][j] = gameMass[i - 1][j];
						gameMass[i - 1][j] = 0;
					}
				}
			} while (tmpNum1 == 1);
		}
		for (int j = 0; j < sizeMass; ++j) {
			for (int i = (sizeMass - 1); i > 0; --i) {
				if (gameMass[i][j] != 0) {
					if (gameMass[i][j] == gameMass[i - 1][j]) {
						gameMass[i][j] += gameMass[i - 1][j];
						score += gameMass[i - 1][j];
						gameMass[i - 1][j] = 0;
						++i;
					}
				}
			}
		}
	}
	if (tmp == 4) {
		for (int i = 0; i < sizeMass; ++i) {
			do {
				tmpNum1 = 0;
				for (int j = (sizeMass - 1); j > 0; --j) {
					if (gameMass[i][j] == 0 && gameMass[i][j - 1] != 0) {
						tmpNum1 = 1;
					}
					if (gameMass[i][j] == 0 && gameMass[i][j - 1] != 0) {
						gameMass[i][j] = gameMass[i][j - 1];
						gameMass[i][j - 1] = 0;
					}
				}
			} while (tmpNum1 == 1);
		}
		for (int i = 0; i < sizeMass; ++i) {
			for (int j = (sizeMass - 1); j > 0; --j) {
				if (gameMass[i][j] != 0) {
					if (gameMass[i][j] == gameMass[i][j - 1]) {
						gameMass[i][j] += gameMass[i][j - 1];
						score += gameMass[i][j - 1];
						gameMass[i][j - 1] = 0;
						++j;
					}
				}
			}
		}
	}
	return (score);
}//сдвиг чисел