#include <stdio.h>
int main()
{
	int a = 3;
	double ad = 3.0;

	int* b = &a;
	double* bd = &ad;

	printf("b�� ����Ű�� �� = %d\n", *b); //3
	printf("b�� �� = %d\n", b); //�ּҰ�����

	printf("bd�� ����Ű�� �� = %.1f\n", *bd); //3.0
	printf("bd�� �� = %d\n", bd); //�ּҰ�����

}