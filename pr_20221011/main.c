#include <stdlib.h>
#include <stdio.h>
void main()
{
	int size;
	printf("배열의 사이즈 : ");
	scanf_s("%d", &size);
	
	// size만큼 배열의 세로 동적할당
	int** arr = (int**)malloc(sizeof(int*) * size);

	// size만큼 배열의 가로 동적할당
	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = i + j;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			arr[i][j] = i + j;
			printf("arr[%d][%d] : %d ", i, j, arr[i][j]);
		}
		printf("\n");

	}
	// 배열의 값 출력
	for (int i = 0; i < size; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}