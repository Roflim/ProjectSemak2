#include <stdlib.h>

#define MaxSize 100

int SumInt(int* FirstMass, int* SeconMass) {
	int FirstCountMass = 0, SeconCountMass = 0, tmp = 0;
	for (int i = 0; FirstMass[i] != '\0'; ++i) ++FirstCountMass;
	for (int i = 0; SeconMass[i] != '\0'; ++i) ++SeconCountMass;
	for (int i = (FirstCountMass - 1), j = (SeconCountMass - 1); i >= 0; --i, --j) {
		tmp = FirstMass[i] + SeconMass[j] + tmp;
		if (tmp > 10) {
			tmp % 10			
		}
	}
}


int main() {
	int FirstCountMass = 15, SeconCountMass = 2;
	int* FirstMass = (int*)malloc(FirstCountMass * sizeof(int));
	int* SeconMass = (int*)malloc(SeconCountMass * sizeof(int));
	for (int i = 0; i < 14; ++i) {
		FirstMass[i] = 9;
	}
	FirstMass[14] = '\0';
	SeconMass[0] = 1;
	SeconMass[0] = '\0';


}