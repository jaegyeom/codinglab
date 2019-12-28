#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int strlength(char* str)
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}

char* substring1(char* str, int b, int e) {
	char* str1 = malloc(sizeof(char) * (e - b + 2));
	for (int i = 0; i < strlength(str1) - 1; i++) {
		str1[i] = str[i + b];
	}
	str1[e - b + 1] = '\0';
	return str1;
}


int strcmp1(char* str1, char* str2)
{
	int len = strlength(str1);
	int len2 = strlength(str2);
	if (len - len2)return 1;
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) return 1;
	}
	return 0;
}

int strCon(char* str1, char* str2)
{
	int len1 = strlength(str1);
	int len2 = strlength(str2);
	if (len1 < len2) {
		for (int i = 0; i < len2 - len1; i++) {
			if (strcmp1(str1, substring1(str2, i, i + len1 - 1)) == 0) {
				return 1;
			}
		}
		return 0;
	}
	else {
		for (int i = 0; i < len1 - len2; i++) {
			if (strcmp1(str2, substring1(str1, i, i + len2 - 1)) == 0) {
				return 1;
			}
		}
		return 0;
	}
}

int main()
{
	char str1[100], str2[100];
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	scanf("%s", str1);
	scanf("%s", str2);
	printf("%d", strCon(str1,str2));
	return 0;
}