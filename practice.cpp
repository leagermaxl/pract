#include "lyubch.h"

int k = 0, num, num_g, num_k;

int main() {
	int num1, y = 1;
	char str[200] = "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		printf("Введіть суму грошей: ");
		scanf("%d.%d", &num, &num_k);
		if ((num < 0 || num > 1000000000) || (num_k < 0 || num_k >= 100))
			printf("Непропустима сума.\n");
	} while ((num < 0 || num > 1000000000) || (num_k < 0 || num_k >= 100));
	if (num == 0 && num_k == 0)
		strcat(str, "нуль гривень нуль копійок");
	else {
		num1 = num;
		num_g = num;
		while (y) {
			num1 /= 10;
			k++;
			if (num1 == 0)
				y = 0;
		}
		while (k) {
			switch (k) {
			case 1: one(str); break;
			case 2: ten(str); break;
			case 3: hundred(str); break;
			case 4: thousand(str); break;
			case 5: ten_thousand(str); break;
			case 6: hundred_thousand(str); break;
			case 7: million(str); break;
			case 8: ten_million(str); break;
			case 9: hundred_million(str); break;
			}
		}
		grn(str);
		num1 = num_k;
		y = 1;
		while (y) {
			num1 /= 10;
			k++;
			if (num1 == 0)
				y = 0;
		}
		num = num_k;
		while (k) {
			switch (k) {
			case 1: one(str); break;
			case 2: ten(str); break;
			}
		}
		kop(str);
	}
	printf("\n%s\n", str);
	return 0;
}
