#include "Field.h"
#include "logic.h"


int main() {
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
		CreateMyField(gameScore, screenWidth, screenHeight, fieldExl);
		if (IsKeyPressed(KEY_W)) {
			DrawText("W", 100, 100, 50, BLACK);
			shiftWASD(GameField, 1);
			NewNumOnField(GameField, gameScore);
		}
		if (IsKeyPressed(KEY_A)) {
			DrawText("A", 100, 100, 50, BLACK);
			shiftWASD(GameField, 2);
			NewNumOnField(GameField, gameScore);
		}
		if (IsKeyPressed(KEY_S)) {
			DrawText("S", 100, 100, 50, BLACK);
			shiftWASD(GameField, 3);
			NewNumOnField(GameField, gameScore);
		}
		if (IsKeyPressed(KEY_D)) {
			DrawText("D", 100, 100, 50, BLACK);
			shiftWASD(GameField, 4);
			NewNumOnField(GameField, gameScore);
		}
		outMass(GameField, screenWidth, screenHeight, fieldExl);
	}
	CloseWindow();
	return 0;
}