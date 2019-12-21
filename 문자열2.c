#include<stdio.h>
#include<stdlib.h>
int strlength(char* str)
{
	int len=0;
	for (int i = 0; str[i] != '\0' ; i++) {
		len++;
	}
	return len;
}

int strcmp1(char* str1,char* str2)
{
	int len = strlength(str1);
	int len2 = strlength(str2);
	if (len - len2)return 1;
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) return 1;
	}
	return 0;
}

int main()
{
	char str1[100],str2[100];
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	scanf("%s", str1);
	scanf("%s", str2);
	printf("%d",strcmp1(str1,str2));
	return 0;
}