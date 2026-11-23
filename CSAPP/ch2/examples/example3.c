//
// Created by cpcn on 2026/11/23.
//
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void) {
	printf("-1 < 0U            : %d\n", -1 < 0U);
	printf("INT_MIN < INT_MAX  : %d\n", INT_MIN < INT_MAX);
	printf("INT_MIN < (unsigned)INT_MAX: %d\n", INT_MIN < (unsigned)INT_MAX);
	printf("(unsigned)-1 > -2  : %d\n", (unsigned)-1 > -2);

	const char *s = "ab", *t = "abcd";
	printf("strlen(s)-strlen(t) > 0 : %d   (期望 0)\n", strlen(s) - strlen(t) > 0);

	short sx = -5;
	printf("(int)sx      = %d\n", (int)sx);
	printf("(unsigned)sx = %u  (0x%x)\n", (unsigned)sx, (unsigned)sx);

	int big = 53191;
	printf("(short)53191 = %d\n", (short)big);
	return 0;
}