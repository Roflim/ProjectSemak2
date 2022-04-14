#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#define screenWidth 800
#define screenHeight 600

int main() {
	int result = -1256;
	char data[20] = { NULL };
	_itoa_s(result, data, 20, 10);
	InitWindow(screenWidth, screenHeight, "Calculator");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawText(data, 0, (screenHeight / 3), 20, ORANGE);
		DrawRectangle(0, 0, screenWidth, (screenHeight / 3), BLACK);
		DrawText(data, 0, (screenHeight / 3), 20, ORANGE);


		EndDrawing();
	}
	CloseWindow();
	return 0;
}