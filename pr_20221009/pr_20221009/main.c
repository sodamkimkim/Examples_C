#include <stdio.h>

int main(void)
{
	int ary[3];
	int* pa = ary;

	*pa = 10;
	*(pa + 1) = 20;
	*(pa + 2) = 30;
	printf("*pa = %d\n", *(pa));
	printf("*(pa + 1) = %d\n", *(pa + 1));
	printf("*(pa + 2) = %d\n\n", *(pa + 2));

	pa[0] = 100;
	pa[1] = 200;
	pa[2] = 300;

	printf("====포인터로 배열요소 출력ㄱ========\n");
	printf("pa[0] = %d\n", pa[0]);
	printf("pa[1] = %d\n", pa[1]);
	printf("pa[2] = %d\n", pa[2]);
	return 0;
}
