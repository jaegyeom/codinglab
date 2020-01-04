#include<stdio.h>

int main()	
{
	int arr[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = i * 4 + j + 1;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

	int arr2[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr2[i]);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr2[i] > arr2[j]) {
				int t = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = t;
			}
		}
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr2[j] > arr2[j+1]) {
				int t = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = t;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%3d", arr2[i]);
	}


	return 0;
}