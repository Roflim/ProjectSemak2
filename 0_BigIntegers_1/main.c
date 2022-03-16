#include <stdlib.h>
#include <stdio.h>

struct BigInt { int* Mass; int CountMass; };

int SumInt(int* FirstMass, int* SeconMass, int FirstCountMass, int SeconCountMass) {
	int tmp = 0, tmpSecon = 0;
	for (int i = (FirstCountMass - 1), j = (SeconCountMass - 1); i >= 0; --i) {
		if (j >= 0) { tmpSecon = SeconMass[j]; --j; }
		else tmpSecon = 0;
		tmp = FirstMass[i] + tmpSecon + tmp;
		if (tmp >= 10) {
			FirstMass[i] = tmp % 10;
			tmp = tmp / 10;
		}
	}
}


int main() {
	struct BigInt First, Secon;
	First.CountMass = 15; Secon.CountMass = 1;
	int* FirstMass = (int*)malloc(First.CountMass * sizeof(int));
	for (int i = 0; i < First.CountMass; ++i) {
		FirstMass[i] = '\0';
	}
	int* SeconMass = (int*)malloc(First.CountMass * sizeof(int));
	for (int i = 0; i < Secon.CountMass; ++i) {
		SeconMass[i] = '\0';
	}

	for (int i = 0; i < First.CountMass; ++i) {
		FirstMass[i] = 9;
	}
	SeconMass[0] = 1;
	for (int i = 0; i < First.CountMass; ++i) {
		printf("%d", FirstMass[i]);
	}
	printf("\n");
	for (int i = 0; i < Secon.CountMass; ++i) {
		printf("%d", SeconMass[i]);
	}
	printf("\n");
	SumInt(FirstMass, SeconMass, First.CountMass, Secon.CountMass);
	for (int i = 0; i < First.CountMass; ++i) {
		printf("%d", FirstMass[i]);
	}
	printf("\n");
	for (int i = 0; i < Secon.CountMass; ++i) {
		printf("%d", SeconMass[i]);
	}
	printf("\n");
}