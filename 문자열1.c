#define _USE_MATH_DEFINES
#include<stdio.h>

int func(char* str1, char* str2)
{
	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
		if (str1[i] - str2[i]) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	char str1[10];
	char str2[10];
	int flag = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	for (int i = 0; i < 10; i++) {
		if(str1[i]!=str2[i]){
			flag = 1;
			break;
		}
	}
	printf("%d\n", flag);
	printf("%d", func(str1, str2));
	return 0;
}