#include<stdio.h>

int fac(int n)
{
	if (n == 1) return 1;
	return n * fac(n - 1);
}

int fibo(int n) {
	if (n <= 1)return n;
	return fibo(n - 2) + fibo(n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n%d", fac(n), fibo(n));
}