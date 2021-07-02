#pragma once
/**
* @file pract.cpp
* @author Любченко М.С., гр. 515А, Завдання 33
* @date 29.06.2021
* @brief Практика
*
* Програма переводу грошей у текст українською
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "windows.h"

extern int k, num, num_g, num_k;

void one(char* str);
void ten(char* str);
void hundred(char* str);
void thousand(char* str);
void ten_thousand(char* str);
void hundred_thousand(char* str);
void million(char* str);
void ten_million(char* str);
void hundred_million(char* str);
void grn(char* str);
void kop(char* str);
