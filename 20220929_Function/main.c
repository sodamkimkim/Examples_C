#include <stdio.h>

// �Լ� ����(function declaration)
// ��ȯ�� �Լ���(�Ű�����)
// return-type functino-name(parameter)
// �Լ� ����(function definition)
//int add3(int _val); // �Լ� ����
//void printhelloworld(void);
//
//int add3(int _val) // ����
//{
//	int tmp = _val * 2;
//	tmp /= 3;
//	tmp += 10;
//	return tmp;
//	return _val + 3;
//}
//int main() {
//	 �Լ�(function)
//	 �Լ� ȣ��(function call)
//	 �Ű����� - ���� : parameter - argument
//	printf("add3(10) : %d\n", add3(10));
//	return 0;
//}
//void ptinthelloword(void) {
//	printf("hello, world!\n");
//}

int main() {
	int n = 0;
	printf("�Ƕ�̵� ���� �Է��ϼ���: ");
	scanf_s("%d",&n);
	int j = 1;
	int xn = n/2;
	int yn = (n%2)*(xn+1);
	int zn = (1+n)*xn+yn;
	for (int i = 1; i <= zn; i++) {
		printf("*");

		int xj = j / 2;
		int yj= (j % 2) * (xj + 1);
		int zj = (1 + j) * xj + yj;
		if (i == zj) {
			printf("\n");
			j++;
		}
	}

}