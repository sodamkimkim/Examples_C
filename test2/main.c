#include <stdio.h>
void main() {
	unsigned char num = 0; // 0 ~ 255
	int i = 0;
	printf("���� �Է����ּ���\n");
	//scanf_s("%hhd", &num); // hhd�� signed char Ÿ��. 1����Ʈ ���� ���� -127 ~ 128
	scanf_s("%hhu", &num);
	printf("hhu: %hhu\n", num);
	printf("hhd: %hhd\n", num);
	printf("c: %c\n", num);
	for (i = 0; i < 8; ++i) {
		printf("%d", (num & (0x80 >> i)) >> (7 - i));
		if (i == 3)
			printf(" ");

	}
}







