//
// Created by zhao on 2026/11/22.
//
#include <stdio.h>

static int x = 0;

int crease()
{
	x++;

	return x;
}

int crease1()
{
	++x;

	return x;
}

int main()
{
	crease();
	crease();

	int i = 1;
	int a[1] = {0};
	a[0] = i++;
	printf("a[0]=%d i=%d", a[0], i);
	a[0] = ++i;
	printf("a[0]=%d i=%d", a[0], i);

	printf("x=%d", crease());

	return 0;
}