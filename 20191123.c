#include<stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,89,0 };
	printf("%x\n", &arr[0]);
	printf("%d", *(arr+8));

}