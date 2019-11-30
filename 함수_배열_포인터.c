#include<stdio.h>

void func1(int* arr, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

void func2(int* a, int *b)
{
	for (int* num = a; num < b; num++) {
		printf("%3d", *num);
	}
}
int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}
	func1(arr, 5);
	func2(arr, arr + 5);
}