#include "Field.h"

int CreateMyField(int gameScore, int screenWidth, int screenHeight, int fieldExl) {
	char strGameScore[5] = { 0 };
	_itoa_s(gameScore, strGameScore, 5, 10);
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
	EndDrawing();
}

int outMass(int** Mass, int screenWidth, int screenHeight, int fieldExl) {
	char strGame[5] = { 0 };
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int tmp = 0;
			tmp = Mass[i][j];
			_itoa_s(tmp, strGame, 5, 10);
			DrawText(
				strGame,
				(((screenWidth - fieldExl) / 2)+(fieldExl/14)+((fieldExl/4)*j)),
				((screenHeight - (fieldExl + ((screenWidth - fieldExl) / 2))+((fieldExl / 12) + ((fieldExl / 4) * i)))),
				(fieldExl/20),
				BLACK);
		}
	}
}