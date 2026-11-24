//
// Created by cpcn on 2026/11/24.
//
#include <stdio.h>
#include <ctype.h>

int str_to_int(const char s[]);

int main(void)
{
	printf("[%d]\n", str_to_int("  -123abc")); /* -123：遇到非数字停止 */
	printf("[%d]\n", str_to_int("+42")); /* 42 */
	printf("[%d]\n", str_to_int("   ")); /* 0 */
	printf("[%d]\n", str_to_int("99")); /* 99 */
	return 0;
}

int str_to_int(const char s[])
{
	int i, n, sign;

	for (i = 0; isspace((unsigned char)s[i]); i++) /* 跳过前导空白 */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* 跳过符号 */
		i++;
	for (n = 0; isdigit((unsigned char)s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}