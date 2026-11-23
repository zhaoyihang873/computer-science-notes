#include <stdio.h>
#include <stddef.h>

void show_bytes(const void *p, size_t len) {
	const unsigned char *b = p;
	for (size_t i = 0; i < len; i++)
		printf(" %.2x", b[i]);
	printf("\n");
}

int main(void) {
	int      i = 0xA1B2C3D4;
	float    f = 12.0f;
	double   d = 12.0;
	const char *s = "ABC";
	int *pi = &i;

	printf("int    :"); show_bytes(&i, sizeof i);
	printf("float  :"); show_bytes(&f, sizeof f);
	printf("double :"); show_bytes(&d, sizeof d);
	printf("string :"); show_bytes(s, 4);          // 含结尾的 '\0'
	printf("pointer:"); show_bytes(&pi, sizeof pi);
	return 0;
}