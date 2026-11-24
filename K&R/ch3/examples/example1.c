#include <stdio.h>

int binsearch(int x, const int v[], int n);

int main(void)
{
	int v[] = {1, 3, 5, 7, 9, 11, 13};
	int n = 7;
	int k;

	for (k = 0; k <= 14; k += 1)
		printf("binsearch(%2d) = %2d\n", k, binsearch(k, v, n));
	printf("binsearch(11) = %d\n", binsearch(11, v, n));
	return 0;
}

/* binsearch：在 v[0] <= v[1] <= ... <= v[n-1] 中查找 x；找到返回下标，否则返回 -1 */
int binsearch(int x, const int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = low + (high - low) / 2;      /* 等价于 (low + high) / 2，但不会溢出 */
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else                               /* 找到了 */
			return mid;
	}
	return -1;                             /* 没找到 */
}