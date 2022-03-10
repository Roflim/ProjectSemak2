#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include <stdio.h>
#include <string.h>

int main() {
	int punct = 0, supp = 0, slow = 0, digid = 0, pas_len = 0, count = 0, res = 0;
	char c;
	puts("Specify the password length. Only numbers.");
	scanf_s("%d", &pas_len);
	char* password = (char*)malloc((pas_len + 1) * sizeof(int));
	for (int i = 0; i < pas_len; ++i) password[i] = 0;
	puts("Enter password. Only English, please.");
	for (int i = 0; i < pas_len; ++i)
	{
		c = _getch();
		if (c == 27) {
			exit(0);
		}
		if (c == 13) {
			break;
		}
		if (c == 8) {
			_putch('\b'); _putch(' ');  _putch('\b');
			if (i >= 0) i = i - 2;
		}
		else {
			password[i] = c;
			_putch('*');
		}

	}
	password[pas_len] = '\0';
	count = strlen(password);
	puts("\r\n\n");
	for (int i = 0; i < pas_len; ++i) {
		if (ispunct(password[i])) punct = 1;
		if (isupper(password[i])) supp = 1;
		if (islower(password[i])) slow = 1;
		if (isdigit(password[i])) digid = 1;
	}
	puts(password);
	res = punct + supp + slow + digid;
	if (count < 8) {
		if (res == 0) puts("There are no allowed characters in the password.");
		if (res == 1) puts("Very simple.");
		if (res >= 2) puts("Middle.");
	}
	else {
		if (res <= 3) puts("Difficult.");
		if (res == 4) puts("Can you repeat?\nAs long as you don't forget.\nVery complicated)");
	}
	system("pause");
	return 0;
}