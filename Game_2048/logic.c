#include "logic.h"
#include "Field.h"

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

int randNum(int numMax) {
	int num = 0;
	srand(time(NULL));
	num = (rand() % 10 + 1);
	if (num < numMax) {
		return (num);
	}
	else {
		return (-1);
	}
} //рандом до определенного числа nummax

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
			tmpNum1 = randNum(sizeMass);
		} while (tmpNum1 == (-1));
		for (int i = 0; i < sizeMass; i++) {
			if (GameField[tmpNum1][i] == 0)
				tmpNum2++;
		}
		tmpNum3 = tmpNum2;
		do {
			tmpNum2 = randNum(tmpNum3);
		} while (tmpNum2 == (-1));
		if (GameField[tmpNum1][tmpNum2] == 0) {
			int tmpNum4 = 0;
			if (ScoreOnNum(score) == 0) {
				tmpNum3 = getNumOnField[0];
			}
			else {
				do {
					tmpNum4 = (randNum(ScoreOnNum(score)));
				} while (tmpNum4 == (-1));
				tmpNum3 = getNumOnField[tmpNum4];
			}
			GameField[tmpNum1][tmpNum2] = tmpNum3;
		}//рандомное доб. числа если counter больше 10
		else {
			tmpNum2 = 0;
			do {
				tmpNum1 = randNum(counter);
			} while (tmpNum1 != (-1));
			for (int i = 0; i < sizeMass; i++) {
				for (int j = 0; j < sizeMass; j++) {
					if (GameField[i][j] == 0) {
						tmpNum2++;
						if (tmpNum1 == tmpNum2) {
							int tmpNum4 = 0;
							if (ScoreOnNum(score) == 0) {
								tmpNum3 = getNumOnField[0];
							}
							else {
								do {
									tmpNum4 = (randNum(ScoreOnNum(score)));
								} while (tmpNum4 == (-1));
								tmpNum3 = getNumOnField[tmpNum4];
							}
							GameField[i][j] = tmpNum3;
						}
					}
				}
			}
		}//рандомное доб. числа если counter меньше 10
	}
}

int shiftWASD(int** gameMass, int tmp){
	int tmpNum1 = 0;
	if (tmp == 1) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j >= 0; --j) {
				if (gameMass[j][i] != 0 && gameMass[j - 1][i] == 0) {
					tmpNum1 = gameMass[j][i];
					gameMass[j][i] = 0;
					gameMass[j - 1][i] += tmpNum1;
				}
			}
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j >= 0; --j) {
				if (gameMass[j][i] == gameMass[j - 1][i]) {
					tmpNum1 = gameMass[j][i];
					gameMass[j][i] = 0;
					gameMass[j - 1][i] += tmpNum1;
					--j;
				}
			}
		}

	}
	if (tmp == 2) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j >= 0; --j) {
				if (gameMass[i][j] != 0 && gameMass[i][j - 1] == 0) {
					tmpNum1 = gameMass[i][j];
					gameMass[i][j] = 0;
					gameMass[i][j - 1] += tmpNum1;
				}
			}

			for (int i = 0; i < 4; ++i) {
				for (int j = 3; j >= 0; --j) {
					if (gameMass[i][j] == gameMass[i][j - 1]) {
						tmpNum1 = gameMass[i][j];
						gameMass[i][j] = 0;
						gameMass[i][j - 1] += tmpNum1;
						--j;
					}
				}
			}
		}
	}
	if (tmp == 3) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j < 3; ++j) {
				if (gameMass[j][i] != 0 && gameMass[j+1][i] == 0) {
					tmpNum1 = gameMass[j][i];
					gameMass[j][i] = 0;
					gameMass[j + 1][i] += tmpNum1;
					++j;
				}
			}
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j < 3; ++j) {
				if (gameMass[j][i] == gameMass[j + 1][i]) {
					tmpNum1 = gameMass[j][i];
					gameMass[j][i] = 0;
					gameMass[j + 1][i] += tmpNum1;
					++j;
				}
			}
		}
	}
	if (tmp == 4) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j >= 0; --j) {
				if (gameMass[i][j] != 0 && gameMass[i][j + 1] == 0) {
					tmpNum1 = gameMass[i][j];
					gameMass[i][j] = 0;
					gameMass[i][j - 1] += tmpNum1;
				}
			}
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (gameMass[i][j] == gameMass[i][j + 1]) {
					tmpNum1 = gameMass[i][j];
					gameMass[i][j] = 0;
					gameMass[i][j + 1] += tmpNum1;
					++j;
				}
			}
		}
	}
}//сдвиг чисел