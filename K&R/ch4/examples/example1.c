//
// Created by cpcn on 2026/11/25.
//
#include <stdio.h>

void quicksort(int v[], int left, int right);
void swap(int v[], int i, int j);
void print_array(const int v[], int n);

int main(void)
{
	int v[] = {6, 3, 9, 1, 5, 8, 2, 7, 4};
	int n = 9;
	int w[1000], i, ok;
	unsigned int seed = 7;

	print_array(v, n);
	quicksort(v, 0, n - 1);
	print_array(v, n);

	/* 随机数据自检：排序后是否有序 */
	for (i = 0; i < 1000; i++) {
		seed = seed * 1103515245u + 12345u;
		w[i] = (int) ((seed >> 8) % 500);          /* 范围小，含大量重复值 */
	}
	quicksort(w, 0, 999);
	ok = 1;
	for (i = 1; i < 1000; i++)
		if (w[i - 1] > w[i])
			ok = 0;
	printf("1000 random values sorted: %s\n", ok ? "OK" : "FAILED");
	return 0;
}

/* quicksort：把 v[left] ... v[right] 按升序排序 */
void quicksort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)                  /* 少于两个元素：什么也不用做（终止条件） */
		return;
	swap(v, left, (left + right) / 2);  /* 把中间元素（枢轴）换到最左边 */
	last = left;
	for (i = left + 1; i <= right; i++) /* 划分 */
		if (v[i] < v[left])
			swap(v, ++last, i);         /* 比枢轴小的，依次放到前面 */
	swap(v, left, last);                /* 枢轴放回它的最终位置 */
	quicksort(v, left, last - 1);       /* 递归排序左半部分 */
	quicksort(v, last + 1, right);      /* 递归排序右半部分 */
}

/* swap：交换 v[i] 与 v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void print_array(const int v[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}