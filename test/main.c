#include <stdio.h>



void main() {
	char num = 0;
	int i = 0;

	printf("값을 입력해주세용\n");

	scanf_s("%hhd", &num);
	printf("%d\n", num);

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
		//0000 0000
		if (i == 3)
			printf(" ");

	}

	///////////
	//for (int i =7; i >= 0; --i) {
	//	int result = 0;
	//	result = num >> i & 1;
	//	printf("%d", result);
	//	if (i %4 ==0) {

	//	printf(" ");
	//		}
	//	
	//}
	return 0;

}

