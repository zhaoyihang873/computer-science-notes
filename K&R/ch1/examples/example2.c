//
// Created by zhao on 2026/11/21.
//
#include <stdio.h>

/* 把输入复制到输出 */
int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);
	return 0;
}