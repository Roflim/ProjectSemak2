#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int compare(const void* val1, const void* val2) {
	const char** tmpstr1 = (char**)val1;
	const char** tmpstr2 = (char**)val2;
	return((strlen(*tmpstr1)) - (strlen(*tmpstr2)));
}

int main() {
	setlocale(0, "Russian");
	int counter = 0;
	int NumString = 0;
	int* tmpMassCount = NULL;
	int* BookMassCount = NULL;
	char input = '1';
	char** BookMass = NULL;
	FILE* Book = NULL;

	fopen_s(&Book, "book.txt", "r");
	if (Book == NULL) {
		perror("Fail");
		system("pause");
		return 0;
	}

	while (!feof(Book)) {
		input = fgetc(Book);
		++NumString;
		if (input == '\n') { 
			++counter;
			tmpMassCount = (int*)realloc(BookMassCount, (counter ) * sizeof(int));
			if (tmpMassCount != NULL) {
				BookMassCount = tmpMassCount;
				BookMassCount[counter - 1] = NumString;
				NumString = 0;
			}
			else {
				free(BookMassCount);
				free(tmpMassCount);
				printf("Memory allocation error.\nCritical error.\n");
				system("pause");
				return 0;
			}
		}
		else if (input == '\0') break;
	}
	rewind(Book);

	BookMass = (char**)malloc((counter) * sizeof(char*));
	for (int i = 0; i < counter; ++i) {
		BookMass[i] = (char*)malloc(BookMassCount[i] * sizeof(char));
		for (int j = 0; j < BookMassCount[i]; ++j) {
			BookMass[i][j] = 0;
		}
	}

	for (int i = 0; i < counter; ++i) {
		for (int j = 0; j < BookMassCount[i]; ++j) {
			BookMass[i][j] = fgetc(Book);
		}
	}
	
	fclose(Book);
	free(BookMassCount);
	qsort(BookMass, (counter), sizeof(char*), compare);
	
	for (int i = 0; i < counter; ++i) {
		for (int j = 0; BookMass[i][j]!='\n'; ++j) {
			printf("%c", BookMass[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < counter; ++i) {
		free(BookMass[i]);
	}
	free(BookMass);
	

	system("pause");
	return 0;
}