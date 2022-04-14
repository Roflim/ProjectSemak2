#include <string.h>
#include <stdlib.h>
#include "raylib.h"

#define MAX_INPUT_CHARS     30

int HashCount(char* name) {
	const int k = 31, mod = 1e9 + 7;
	long long h = 0, m = 1;
	for (int i = 0; name[i] != '\0'; ++i) {
		char c = name[i];
		int x = (int)(c - 'a' + 1);
		h = (h + m * x) % mod;
		m = (m * k) % mod;
	}
	return(h);
}

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "HashUtility");

	char name[MAX_INPUT_CHARS + 1] = "\0";
	int letterCount = 0;

	Rectangle textBox = { screenWidth / 6.0f - 100, 180, 750, 50 };
	bool mouseOnText = false;

	int framesCounter = 0;
	long long HASH = 0;
	char HashChar[100] = { 0 };

	SetTargetFPS(30);
	while (!WindowShouldClose()) {
		if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
		else mouseOnText = false;
		if (mouseOnText) {
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			int key = GetCharPressed();
			while (key > 0) {
				if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
					name[letterCount] = (char)key;
					name[letterCount + 1] = '\0';
					letterCount++;
				}
				key = GetCharPressed();
			}
			if (IsKeyPressed(KEY_BACKSPACE)) {
				letterCount--;
				if (letterCount < 0) letterCount = 0;
				name[letterCount] = '\0';
			}

			_itoa_s(HASH, HashChar, 100, 16);
			if (IsKeyPressed(KEY_ENTER)) {
				HASH = HashCount(name);
			}
			DrawText(HashChar, 200, 340, 100, GRAY);
			
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnText) framesCounter++;
		else framesCounter = 0;
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);
		DrawRectangleRec(textBox, LIGHTGRAY);
		if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
		else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
		DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
		DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);
		if (mouseOnText) {
			if (letterCount < MAX_INPUT_CHARS) {
				if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
			}
			else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

bool IsAnyKeyPressed()
{
	bool keyPressed = false;
	int key = GetKeyPressed();

	if ((key >= 32) && (key <= 126)) keyPressed = true;

	return keyPressed;
}