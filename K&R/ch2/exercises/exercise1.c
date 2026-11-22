//
// Created by zhao on 2026/11/22.
//
#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main()
{
	char s1[] = "abcdefghijklmnopqrst";

	squeeze(s1, "ae");
	printf("squeeze=%s\n", s1);
	return 0;
}

void squeeze(char s1[], const char s2[])
{
	int i, j, k;

	for(i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
			;
		if (s2[k] == '\0')
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
