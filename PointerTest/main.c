#include <stdio.h>
int main()
{
	int a = 3;
	double ad = 3.0;

	int* b = &a;
	double* bd = &ad;

	printf("b가 가리키는 값 = %d\n", *b); //3
	printf("b의 값 = %d\n", b); //주소값나옴

	printf("bd가 가리키는 값 = %.1f\n", *bd); //3.0
	printf("bd의 값 = %d\n", bd); //주소값나옴

}