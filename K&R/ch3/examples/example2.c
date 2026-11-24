//
// Created by cpcn on 2026/11/23.
//
#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void int_to_str(int n, char s[]);

void int_to_str(int n, char s[])
{
	unsigned int u;
	int i;

	u = (n < 0) ? -(unsigned int)n : (unsigned int)n;
	i = 0;
	do {
		s[i++] = u % 10 + '0';
	} while ((u /= 10) > 0);
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = (int)strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main()
{
	return 0;
}