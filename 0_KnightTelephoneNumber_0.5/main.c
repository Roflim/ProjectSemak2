#include <stdio.h>

int TelefonHorses(int Num, int count, int Numbers, int A) {
	if (A >= Num) {
		--Num;
		return count;
	}
	if (A <= Num) {
		if (Numbers == 1) {
			count = TelefonHorses(Num, count + 1, 6, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 8, ++A);
			--A;
		}
		if (Numbers == 2) {
			count = TelefonHorses(Num, count + 1, 9, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 7, ++A);
			--A;
		}
		if (Numbers == 3) {
			count = TelefonHorses(Num, count + 1, 4, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 8, ++A);
			--A;
		}
		if (Numbers == 4) {
			count = TelefonHorses(Num, count + 1, 3, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 9, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 0, ++A);
			--A;
		}
		if (Numbers == 5) {
			return count;
		}
		if (Numbers == 6) {
			count = TelefonHorses(Num, count + 1, 1, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 7, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 0, ++A);
			--A;
		}
		if (Numbers == 7) {
			count = TelefonHorses(Num, count + 1, 2, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 6, ++A);
			--A;
		}
		if (Numbers == 9) {
			count = TelefonHorses(Num, count + 1, 2, ++A);
			--A;
			count = TelefonHorses(Num, count + 1, 4, ++A);
			--A;
		}
		if (Numbers == 0) {
			if(count == 0){ return 0; }
			else {
				count = TelefonHorses(Num, count + 1, 4, ++A);
				--A;
				count = TelefonHorses(Num, count + 1, 6, ++A);
				--A;
			}
		}
		if (Numbers == 8) {
			if (count == 0) { return 0; }
			else {
				count = TelefonHorses(Num, count + 1, 1, ++A);
				--A;
				count = TelefonHorses(Num, count + 1, 3, ++A);
				--A;
			}
		}
	}
	else {
		return count;
	}
	return count;
}

int main() {
	int Num = 0, count = 0, countHorses = 0;
	printf_s("Enter number.\n");
	scanf_s("%d", &Num);
	for (int i = 1; i <= 9; ++i) {
		count = 0;
		count = TelefonHorses(Num, count, i, 0);
		countHorses += count;
	}
	printf_s("%d\n", countHorses);
	system("pause");
}