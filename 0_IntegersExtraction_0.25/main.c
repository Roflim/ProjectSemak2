#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main() {
	int g = 0;
	unsigned long long int num = 0;
	char c, tmp = NULL;
	char stringss[100] = { NULL }, number[20] = { NULL };
	puts("Enter please.");
	for (int i = 0, j = 0; j < 100; ++i){
		c = _getch();
		if (c == 26) break; //exit
		if (c == 13) { puts(""); if(isdigit(tmp))++j; } //enter
		else {
			if (isdigit(c)) { stringss[j] = c; ++j; }
			else if (isdigit(tmp)) ++j;
			tmp = c;
			_putch(c);
		}
	}
	puts("");
	for (int i = 0; i < 100; ++i) {
		if (isdigit(stringss[i])) {
			number[g] = stringss[i];
			++g;
		}
		else if (stringss[i] == '\0') {
			num = atoi(number);
			if (num > 2147483646) printf_s("Number is very big! I can't handle it!");
			for (int k = 0; k < 20; ++k) number[k] = '\0';
			if(num!=0 && num <= 2147483646) printf_s("%llu ", (num * num));
			g = 0;
			num = 0;
		}
	}
	puts("");
	system("pause");
	return 0;
}