#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(0, "Russian");
	int counter = 0;
	int NumCount = 0;
	int NumString = 0;
	int* BookMassCount = NULL;
	char input = '1';
	char* tmpString = NULL;
	char** tmpText = NULL;
	char** BookMass = NULL;
	FILE* Book = NULL;
	fpos_t pos = NULL;

	fopen_s(&Book, "book.txt", "r");
	if (Book == NULL) {
		perror("Fail");
	}

	while (!feof(Book)){
		input = fgetwc(Book);
		if (input == '\n') ++counter;
		else if (input == '\0') break;
	}
	rewind(Book);


	do {
		NumString = 0;
		input = '1';
		NumCount++;
		fgetpos(Book, &pos);
		for (; input != '\n'; ++NumString)
			input = fgetc(Book);
		fsetpos(Book, &pos);
		tmpText = (char**)realloc(BookMass, NumCount * sizeof(char*));
		if (tmpText != NULL) {
			BookMass = tmpText;
			BookMass[NumCount - 1] = (char*)malloc(NumString * sizeof(char));
			for (int i = 0; i < NumString; ++i)
				BookMass[NumCount - 1][i] = fgetc(Book);
		}
		else {
			for (int i = 0; i < NumCount; ++i)
				free(BookMass[i]);
			free(BookMass);
		}

	} while (NumCount<=counter);
	system("pause");
}