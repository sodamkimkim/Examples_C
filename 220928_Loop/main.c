#include <stdio.h>
int main() {
	// �ݺ���(Loop)
	// for��
	// for(�ʱ⹮; ���ǹ�; ������)
	for (int i = 2; i < 10; i++) {
		printf("%d��\n", i);
		for (int j = 1; j < 10; j++) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("=============\n");
	}
	int i = 0;
	int j = 0;



	//while (1) // while ���� ����: 0, ��: ������
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

