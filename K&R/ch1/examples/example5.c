//
// Created by zhao on 2026/11/21.
//
#include <stdio.h>

int main ()
{
	double nc;

	for (nc = 0; getchar() != EOF; nc++)
		;
	printf("%.0f\n", nc);
	return 0;
}