//
// Created by zhao on 2026/11/21.
//
#include <stdio.h>

int main(void)
{
	int c, i, nwhite = 0, nother = 0;
	int ndigit[10] = {0};

	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0; /* 必须手动初始化！ */

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}

	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);


	return 0;
}

