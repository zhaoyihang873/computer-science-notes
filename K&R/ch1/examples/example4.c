//
// Created by zhao on 2026/11/21.
//
#include <stdio.h>

/* 统计输入的字符数（写法一：while） */
int main(void)
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
	return 0;
}