#include "lyubch.h"

void one(char* str) {
	int x;
	char* words[] = { "одна ","дві ","три ","чотири ","п'ять ","шість ","сім ","вісім ","дев'ять " };
	char* words_m[] = { "один ","два ","три ","чотири ","п'ять ","шість ","сім ","вісім ","дев'ять " };
	if (num == 0);
	else if (k >= 7)
		strcat(str, words_m[num - 1]);
	else
		strcat(str, words[num - 1]);
	if (k == 1)
		k = k - 1;
	return;
}

void ten(char* str) {
	char* words[] = { "десять ","одинадцять ","дванадцять ","тринадцять ","чотирнадцять ","п'ятнадцять ","шістнадцять ","сімнадцять ","вісімнадцять ","дев'ятнадцять " };
	char* tens[] = { "двадцять ","тридцять ","сорок ","п'ятдесят ","шістдесят ","сімдесят ","вісімдесят ","дев'яносто " };
	int num1;
	if (num >= 10 && num <= 19) {
		num = num % 10;
		strcat(str, words[num]);
		if (k == 2)
			k = k - 2;
	}
	else {
		num1 = num / 10;
		num = num % 10;
		if (num1 == 0 || num1 == 1);
		else
			strcat(str, tens[num1 - 2]);
		if (k == 2)
			k = k - 1;
	}
	return;
}

void hundred(char* str) {
	int num1;
	char* words[] = { "сто ","двісті ","триста ","чотириста ","п'ятсот ","шістсот ","сімсот ","вісімсот ","дев'ятсот " };
	num1 = num / 100;
	num = num % 100;
	if (num1 == 0);
	else
		strcat(str, words[num1 - 1]);
	if (k == 3)
		numbers(num);
	return;
};

void thousand(char* str) {
	int num1, num2;
	char* words[] = { "тисяча ","тисячі ","тисяч " };
	num1 = num / 1000;
	num = num % 1000;
	if (num1 == 1)
		strcat(str, words[0]);
	else {
		num2 = num;
		num = num1;
		one(str);
		if (num1 >= 2 && num1 <= 4)
			strcat(str, words[1]);
		if (num1 >= 5 && num1 <= 9)
			strcat(str, words[2]);
		num = num2;
	}
	if (k == 4)
		numbers(num);
	return;
}

void ten_thousand(char* str) {
	int num1, num2, num3;
	char* words[] = { "тисяча ","тисячі ","тисяч " };
	num1 = num / 1000;
	num3 = num1 % 10;
	num = num % 1000;
	num2 = num;
	num = num1;
	if ((num1 >= 10 && num1 <= 19)) {
		ten(str);
		strcat(str, words[2]);
	}
	else {
		num1 = num1 / 10;
		ten(str);
		one(str);
		if (num3 == 1)
			strcat(str, words[0]);
		if (num3 >= 2 && num3 <= 4)
			strcat(str, words[1]);
		if (num3 >= 5 && num3 <= 9)
			strcat(str, words[2]);
	}
	num = num2;
	if (k == 5)
		numbers(num);
	return;
}

void hundred_thousand(char* str) {
	int num1, num2, num3;
	char* words[] = { "тисяча ","тисячі ","тисяч " };
	num1 = num / 1000;
	num2 = num;
	num = num1;
	hundred(str);
	//ten(str);
	num = num2;
	num = num % 100000;
	ten_thousand(str);
	if (k == 6)
		numbers(num);
	return;
}

void million(char* str) {
	int num1, num2, num3;
	char* words[] = { "мільйон ","мільйони ","мільйонів " };
	num1 = num / 1000000;
	num3 = num1 % 10;
	if (k != 9) {
		num = num % 1000000;
		num2 = num;
		num = num1;
		one(str);
	}
	if (num3 == 1)
		strcat(str, words[0]);
	if (num3 >= 2 && num3 <= 4)
		strcat(str, words[1]);
	if ((num3 >= 5 && num3 <= 9) || num3 == 0)
		strcat(str, words[2]);
	if (k != 9)
		num = num2;
	if (k == 7)
		numbers(num);
	return;
}

void ten_million(char* str) {
	int num1, num2, num3;
	char* words[] = { "мільйон ","мільйони ","мільйонів " };
	num1 = num / 1000000;
	num3 = num1 % 10;
	num = num % 1000000;
	num2 = num;
	num = num1;
	if ((num1 >= 10 && num1 <= 19)) {
		ten(str);
		strcat(str, words[2]);
	}
	else {
		num1 = num1 / 10;
		ten(str);
		one(str);
		if (num3 == 1)
			strcat(str, words[0]);
		if (num3 >= 2 && num3 <= 4)
			strcat(str, words[1]);
		if ((num3 >= 5 && num3 <= 9) || num3 == 0)
			strcat(str, words[2]);
	}
	num = num2;
	if (k == 8)
		numbers(num);
	return;
}

void hundred_million(char* str) {
	int num1, num2, num3;
	char* words[] = { "мільйон ","мільйони ","мільйонів " };
	num1 = num / 1000000;
	num2 = num;
	num = num1;
	hundred(str);
	if (num >= 10 && num <= 19)
		ten(str);
	else {
		ten(str);
		one(str);
	}
	num = num2;
	num = num % 10000000;
	million(str);
	num = num % 1000000;
	if (k == 9)
		numbers(num);
	return;
}

void grn(char* str) {
	char* words[] = { "гривня ", "гривні ", "гривень " };
	if (num_g == 0);
	else {
		if (num_g >= 10 && num_g <= 19)
			strcat(str, words[2]);
		else {
			num_g = num_g % 10;
			if (num_g == 1)
				strcat(str, words[0]);
			if (num_g >= 2 && num_g <= 4)
				strcat(str, words[1]);
			if ((num_g >= 5 && num_g <= 9) || num_g == 0)
				strcat(str, words[2]);
		}
	}
	return;
}

void kop(char* str) {
	char* words[] = { "копійка ", "копійки ", "копійок " };
	if (num_k == 0);
	else {
		if (num_k >= 10 && num_k <= 19)
			strcat(str, words[2]);
		else {
			num_k = num_k % 10;
			if (num_k == 1)
				strcat(str, words[0]);
			if (num_k >= 2 && num_k <= 4)
				strcat(str, words[1]);
			if ((num_k >= 5 && num_k <= 9) || num_k == 0)
				strcat(str, words[2]);
		}
	}
	return;
}

void numbers(int num1) {
	int y = 1;
	k = 0;
	while (y) {
		num1 /= 10;
		k++;
		if (num1 == 0)
			y = 0;
	}
	return;
}

void switchh(char* str) {
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
}
