#include <stdio.h>
int main(void) {
	int a = 10, b = 20;
	const int* pa = &a;

	printf("변수 a 값: %d\n", *pa);
	pa = &b;
	printf("변수 b의 값: %d\n", *pa);
	//*pa = &b; // *pa는 const라서 pa간접참조로 값 못바꿔서 에러난다.

	pa = &a;
	a = 20;
	printf("변수 a 값: %d", *pa);

	return 0;

}
