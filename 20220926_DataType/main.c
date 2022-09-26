#include <stdio.h>

int main()
{
	// 자료형(Data Type)
	// 변수(Variables)
	// int: Integer(정수)
	// 변수명(Variables Name)

	// int (Integer-Value)
	int iVal = 10;  
	iVal = 5;
	printf("int size : %d byte\n", sizeof(int));
	printf("iVal: %d\n", iVal);

	// float (Floating-Point : 부동소숫점, 실수)
	float fVal = 3.14f;
	printf("float size: %d byte \n", sizeof(float));
	printf("fVal: %f\n", fVal);

	// 기본 자료형
	// Character(문자)
	char c = 'a'; // 작은 따옴표 사용
	printf("char size: %c byte \n", sizeof(char)); // 1byte
	short int s = 5;
	printf("short int size: %d byte \n", sizeof(short)); // 2byte
	long int l = 3222;
	printf("long int size: %d byte \n", sizeof(long)); // 4byte
	long long int ll = 40;
	printf("long long int size: %d byte \n", sizeof(long long)); // 8byte


	float f = 3.14f; // 4byte

	// double (Double-Precision Floating Point) 두배 정밀도 부동 소숫점(저장 공간이 크다. ) // 8byte
	double d = 3.14;
	printf("double size : %d byte \n", sizeof(double)); // 8byte
	long double ld = 3.14;
	printf("long double size : %d byte \n", sizeof(long double)); // 8byte
	return 0;
}