#include <stdio.h>

int main()
{
	// �ڷ���(Data Type)
	// ����(Variables)
	// int: Integer(����)
	// ������(Variables Name)

	// int (Integer-Value)
	int iVal = 10;  
	iVal = 5;
	printf("int size : %d byte\n", sizeof(int));
	printf("iVal: %d\n", iVal);

	// float (Floating-Point : �ε��Ҽ���, �Ǽ�)
	float fVal = 3.14f;
	printf("float size: %d byte \n", sizeof(float));
	printf("fVal: %f\n", fVal);

	// �⺻ �ڷ���
	// Character(����)
	char c = 'a'; // ���� ����ǥ ���
	printf("char size: %c byte \n", sizeof(char)); // 1byte
	short int s = 5;
	printf("short int size: %d byte \n", sizeof(short)); // 2byte
	long int l = 3222;
	printf("long int size: %d byte \n", sizeof(long)); // 4byte
	long long int ll = 40;
	printf("long long int size: %d byte \n", sizeof(long long)); // 8byte


	float f = 3.14f; // 4byte

	// double (Double-Precision Floating Point) �ι� ���е� �ε� �Ҽ���(���� ������ ũ��. ) // 8byte
	double d = 3.14;
	printf("double size : %d byte \n", sizeof(double)); // 8byte
	long double ld = 3.14;
	printf("long double size : %d byte \n", sizeof(long double)); // 8byte
	return 0;
}