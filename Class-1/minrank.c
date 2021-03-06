#include<stdio.h>
struct testcases
{
	int n, minrank;
} tests[] =
{
	{ 1234, 0 },
	{ 5437, 14 },
	{ 999, 0 },
	{ 1203, 8 },
	{ 675238, 444 },
	{ 98765432, 40319 },
	{ 112, 0 },
	{ 121, 1 },
};
int numsLessThan(int a[10], int key, int len)
{
	int i, less = 0;
	for (i = 0; i<len; i++)
	if (a[i]<key)
		less++;
	return less;
}
int fact(int n)
{
	int fact = 1;
	while (n)
		fact *= n--;
	return fact;
}
int findMinRank1(int a[10], int len) //recursive code for min rank
{
	int rank = 0, i = len - 1;
	if (len == 1)
		return 0;
	rank += (numsLessThan(a, a[i], len)*fact(len - 1)) + findMinRank1(a, len - 1);
	return rank;
}
int findMinRank2(int a[10], int len) //iterative code for min rank
{
	int rank = 0, i = len;
	while (i>1)
	{
		rank += numsLessThan(a, a[i - 1], i)*fact(i - 1);
		i--;
	}
	return rank;
}
int find(int n)
{
	int a[10], temp = n, i = 0, len;
	while (temp)
	{
		a[i++] = temp % 10;
		temp /= 10;
	}
	len = i;
	return findMinRank1(a, len);
}
void checkResult(int a, int b)
{
	printf("a: %d b: %d  ", a, b);
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int min_rank, i;
	for (i = 0; i < 8; i++)
	{
		min_rank = find(tests[i].n);
		checkResult(min_rank, tests[i].minrank);
	}
	return 0;
	//getchar();
	//getchar();
}