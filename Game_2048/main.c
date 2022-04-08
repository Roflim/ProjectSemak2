#include "Field.h"
#include "logic.h"


int main() {
	int gameOver = 0;
	int screenWidth = scrWidt;
	int screenHeight = scrHeig;
	int fieldExl = screenWidth - 100;
	if (screenWidth > screenHeight) {
		return 0;
	}
	int gameScore = 0;
	int** GameField = NULL;
	GameField = GameMass(gameScore);

	InitWindow(screenWidth, screenHeight, "2048");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		if (gameOver == 1) {
			DrawText("GAME OVER", (screenWidth / 8), (screenHeight / 4), (fieldExl/7), RED);
		}
		if (IsKeyPressed(KEY_R)) {
			GameField = NULL;
			gameScore = 0;
			GameField = GameMass(gameScore);
		}
		CreateMyField(gameScore, screenWidth, screenHeight, fieldExl);
		if (IsKeyPressed(KEY_W)) {
			gameScore += shiftWASD(GameField, 1);
			gameOver = NewNumOnField(GameField, gameScore);
		}
		if (IsKeyPressed(KEY_A)) {
			gameScore += shiftWASD(GameField, 2);
			gameOver = NewNumOnField(GameField, gameScore);
		}
		if (IsKeyPressed(KEY_S)) {
			gameScore += shiftWASD(GameField, 3);
			gameOver = NewNumOnField(GameField, gameScore);
		}
		if (IsKeyPressed(KEY_D)) {
			gameScore += shiftWASD(GameField, 4);
			gameOver = NewNumOnField(GameField, gameScore);
		}
		outMass(GameField, screenWidth, screenHeight, fieldExl, gameScore);
	}
	CloseWindow();
	return 0;
}