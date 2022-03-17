#include <stdlib.h>
#include <stdio.h>

struct BigInt { int* Mass; int CountMass; };

int SumInt(int* FirstMass, int* SeconMass, int FirstCountMass, int SeconCountMass) {
	int tmp = 0, tmpSecon = 0;
	int* SummaMass = (int*)malloc((FirstCountMass + SeconCountMass) * sizeof(int));
	for (int i = 0; i < (FirstCountMass + SeconCountMass); ++i) {
		SummaMass[i] = '\0';
	}
	for (int i = (FirstCountMass - 1), j = (SeconCountMass - 1); i >= 0; --i) {
		if (j >= 0) { tmpSecon = SeconMass[j]; --j; }
		else tmpSecon = 0;
		tmp = FirstMass[i] + tmpSecon + tmp;
		if (tmp >= 10) {
			SummaMass[i + SeconCountMass] = tmp % 10;
			tmp = tmp / 10;
		}
	}
	return SummaMass;
}


int main() {
	struct BigInt First, Secon, Summa;
	First.CountMass = 15; Secon.CountMass = 1;
	First.Mass = (int*)malloc(First.CountMass * sizeof(int));
	for (int i = 0; i < First.CountMass; ++i) {
		First.Mass[i] = '\0';
	}
	Secon.Mass = (int*)malloc(First.CountMass * sizeof(int));
	for (int i = 0; i < Secon.CountMass; ++i) {
		Secon.Mass[i] = '\0';
	}

	for (int i = 0; i < First.CountMass; ++i) {
		First.Mass[i] = 9;
	}
	Secon.Mass[0] = 1;
	for (int i = 0; i < First.CountMass; ++i) {
		printf("%d", First.Mass[i]);
	}
	printf("\n");
	for (int i = 0; i < Secon.CountMass; ++i) {
		printf("%d", Secon.Mass[i]);
	}
	printf("\n");

	Summa.Mass = SumInt(First.Mass, Secon.Mass, First.CountMass, Secon.CountMass);

	for (int i = 0; i < First.CountMass; ++i) {
		printf("%d", First.Mass[i]);
	}
	printf("\n");
	for (int i = 0; i < Secon.CountMass; ++i) {
		printf("%d", Secon.Mass[i]);
	}
	for (int i = 0; i < First.CountMass + Secon.CountMass; ++i) {
		printf("%d", Summa.Mass[i]);
	}
	printf("\n");
}