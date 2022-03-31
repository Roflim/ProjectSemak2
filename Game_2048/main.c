#include <raylib.h>
#include <stdlib.h>

#define scrWidt 600;
#define scrHeig 800;
#define field 500;


int main() {
	int screenWidth = scrWidt;
	int screenHeight = scrHeig;
	int fieldExl = field;
	int gameScore = 50;
	char strGameScore[4] = { 0 };
	_itoa_s(gameScore, strGameScore, 4, 10);

	InitWindow(screenWidth, screenHeight, "MY Tetris");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground((Color) { 255, 239, 181, 1 });

		DrawText("2048", screenWidth / 70, screenHeight / 70, screenHeight / 10, BLACK);

		DrawRectangleLines(
			((screenWidth - fieldExl) / 2),
			(screenHeight - (fieldExl + ((screenWidth - fieldExl) / 2))),
			fieldExl,
			fieldExl,
			BLACK);
		DrawRectangleLines(
			(((screenWidth - fieldExl) / 2) + (fieldExl / 4)),
			(screenHeight - (fieldExl + ((screenWidth - fieldExl) / 2))),
			(fieldExl / 4),
			fieldExl,
			BLACK);
		DrawRectangleLines(
			(((screenWidth - fieldExl) / 2) + (fieldExl / 2)),
			(screenHeight - (fieldExl + ((screenWidth - fieldExl) / 2))),
			(fieldExl / 4),
			fieldExl,
			BLACK);
		DrawRectangleLines(
			((screenWidth - fieldExl) / 2),
			(screenHeight - (-(fieldExl / 4) + fieldExl + ((screenWidth - fieldExl) / 2))),
			fieldExl,
			(fieldExl / 4),
			BLACK);
		DrawRectangleLines(
			((screenWidth - fieldExl) / 2),
			(screenHeight - (-(fieldExl / 2) + fieldExl + ((screenWidth - fieldExl) / 2))),
			fieldExl,
			(fieldExl / 4),
			BLACK);

		DrawRectangleLines(
			(screenWidth / 3 * 2),
			(screenHeight / 70),
			(fieldExl / 3.5),
			(fieldExl / 3.5),
			BLACK);

		DrawText(
			"SCORE",
			((screenWidth / 3 * 2) + 35 % (screenWidth / 3 * 2)),
			((screenHeight / 70) + 10 % (screenWidth / 3 * 2)),
			screenHeight / 40,
			ORANGE);
		DrawText(
			strGameScore,
			((screenWidth / 3 * 2) + 30 % (screenWidth / 3 * 2)),
			((screenHeight / 70) + 40 % (screenWidth / 3 * 2)),
			screenHeight / 20,
			ORANGE);


		//DrawRectangle(100, 100, 100, 300, RED);
		//DrawCircle(400, 300, 64, ORANGE);
		//DrawTriangle((Vector2) { 50, 0 }, (Vector2) { 0, 100 }, (Vector2) { 100, 100 }, YELLOW);



		EndDrawing();
	}
	CloseWindow();
	return 0;
}