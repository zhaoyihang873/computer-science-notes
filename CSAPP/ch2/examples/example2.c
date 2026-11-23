//
// Created by cpcn on 2026/11/23.
//
#include <stdio.h>

int main(void)
{
	unsigned int x = 1;
	printf("%s\n", *(unsigned char *)&x == 1 ? "little" : "big");
	return 0;
}