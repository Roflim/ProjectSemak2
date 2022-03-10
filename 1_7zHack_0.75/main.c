#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define name7zip "7zG.exe"

int main() {
	time_t start, end;
	int specG = 0, specJ = 0;
	char* password = (char*)malloc(27 * sizeof(char));
	char* pass = { "7z x secret.7z -p01011991" };
	for (int i = 0; i < 26; ++i)
		password[i] = pass[i];
	time(&start);
	for (int i = 48; i <= 49; ++i) {
		password[19] = i;
		if (i == 49) { specJ = 50; }
		else { specJ = 57; }
		for (int j = 48; j <= specJ; ++j) {
			if (j != 48)
				password[20] = j;
			for (int k = 48; k <= 51; ++k) {
				password[17] = k;
				if (k == 51) { specG = 49; }
				else { specG = 57; }
				for (int g = 48; g <= specG; ++g) {
					password[18] = g;
					if (system(password) == 0) {
						time(&end);
						printf("WORK TIME = %lf\n", difftime(end, start));
						printf_s("PASSWORD: %d%d%d%d1991\n", (k - 48), (g - 48), (i - 48), (j - 48));
						system("pause");
						return 0;
					}
				}
			}
		}
	}
	printf_s("I don't know password(((\n");
	system("pause");
	return 0;
}