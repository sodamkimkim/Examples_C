#include <stdio.h>
int main() {
	// 반복문(Loop)
	// for문
	// for(초기문; 조건문; 증감문)
	for (int i = 2; i < 10; i++) {
		printf("%d단\n", i);
		for (int j = 1; j < 10; j++) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("=============\n");
	}
	int i = 0;
	int j = 0;



	//while (1) // while 조건 거짓: 0, 참: 나머지
	// {
	//
	//	printf("while: %d\n", i);
	//	++i;
	//}
	//
	//do
	//{
	//	printf("do~while\n");
	//} while (0);

	star(5);
	return 0;
}


int star(int j) {
	for (int i = 1; i <= j; i++) {
		printf("*");
	}
	printf("\n");
	j = j - 1;
	if (j == 0)
		return 0;
	star(j);
}

