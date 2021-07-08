#include "lyubch.h"

int k = 0, num, num_g, num_k;

int main() {
	int num1;
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
		numbers(num1);
		switchh(str);
		grn(str);
		num1 = num_k;
		numbers(num1);
		num = num_k;
		switchh(str);
		kop(str);
	}
	printf("\n%s\n", str);
	return 0;
}
