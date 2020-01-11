#include<stdio.h>
int main()
{
	int arr[3][3];
	int arr2[10];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr2[i * 3 + j] = arr[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr2[j] < arr2[i]) {
				int t = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = t;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = arr2[i * 3 + j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}