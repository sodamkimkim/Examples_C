#include <stdio.h>
void main() {
	unsigned char num = 0; // 0 ~ 255
	int i = 0;
	printf("값을 입력해주세요\n");
	//scanf_s("%hhd", &num); // hhd는 signed char 타입. 1바이트 정수 저장 -127 ~ 128
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







