#include <stdio.h>
int main(void) {
	int a = 10, b = 20;
	const int* pa = &a;

	printf("���� a ��: %d\n", *pa);
	pa = &b;
	printf("���� b�� ��: %d\n", *pa);
	//*pa = &b; // *pa�� const�� pa���������� �� ���ٲ㼭 ��������.

	pa = &a;
	a = 20;
	printf("���� a ��: %d", *pa);

	return 0;

}
