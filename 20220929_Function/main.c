#include <stdio.h>
// �Լ� ����(Function Declaration)
// ��ȯ�� �Լ���(�Ű�����)
// Return-Type Function-Name(Parameter)
// �Լ� ����(Function Definition)
int Add3(int _val); // �Լ� ����
void PrintHelloWorld(void);

int Add3(int _val) // ����
{
	// int tmp = _val *2;
	// tmp /= 3;
	// tmp += 10;
	// return tmp;
	return _val + 3;

}
int main() {
	// �Լ�(Funciton)
	// �Լ� ȣ��(Function Call)
	// �Ű����� - ���� : Parameter - Argument
	printf("Add3(10) : %d\n", Add3(10));
	return 0;

}
void PrintHelloWorld(void) {
	printf("Hello, World\n");
}