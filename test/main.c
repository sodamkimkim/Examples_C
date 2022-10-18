#include <stdio.h>



void main() {
	unsigned char num = 0;
		int i = 0;

printf("값을 입력해주세용\n");

	scanf_s("%hhd", &num);



	printf("", num);



	// 1

	/*for (i = 0; i < 8; ++i) {

		printf("%d", (num & (0x80 >> i)) != 0);



		if (i == 3)

			printf(" ");

	}*/



	// 2

	/*for (i = 0; i < 8; ++i) {

		if (num & (1 << (7 - i)))

			printf("1");

		else printf("0");



		if (i == 3)

			printf(" ");

	} */



	// 3

	for (i = 0; i < 8; ++i) {

		printf("%d", (num & (0x80 >> i)) >> (7 - i));



		if (i == 3)

			printf(" ");

	}



}

