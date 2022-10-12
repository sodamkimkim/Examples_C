#include <stdio.h>
int main() {
	// �ݺ���(Loop)
	// for��(�ʱ⹮; ���ǹ�; ������)
	int i = 0;
	for (i = 0; i < 5; ++i) {
		printf("i : %d\n", i);
	}
	// �� ����, �� ���� ������
	// ++i, i++
	// --i, i--

	float fVal = 0.5f;
	++fVal;
	printf("fVal : %f\n", fVal);

	// ��Ģ������
	int lhs = 3, rhs = 2;
	printf("lhs + rhs = %d\n", lhs + rhs);
	printf("lhs - rhs = %d\n", lhs - rhs);
	printf("lhs * rhs = %d\n", lhs * rhs);

	// ����ȯ(Type-Casting, Type-Conversion)
	// ������ ����ȯ
	float f = lhs / rhs; // -> 1.000000 ���
	printf("lhs / rhs = %f\n", f);

	// ����� ����ȯ
	// �ڷ����� �°�(���е��� ���� ������ ��� �� �ڷ����� ���� ����.)
	printf("lhs / rhs = %f\n", (float)lhs / rhs); // -> 1.500000 ���
	printf("lhs / rhs = %f\n", (float)(lhs / rhs)); // ��������� ���� float�� �� ��ȯ -> 1.000000 ���

	printf("lhs % rhs = %d\n", lhs % rhs);

	// ���׿�����
	// ���� ? �� : ����
	int iVal = lhs < rhs ? 10 : 100;

	///////////////////////////////////////////
	printf("\n");
	for (int i = 0; i < 10; ++i)
	{
		if (i > 5) break;
		if (i == 2) continue;
		printf("i : %d\n", i);
	}
	printf("\n");
	int j = 0;
	while (j <= 5) {
		printf("while i : %d\n", ++j);
	}

	do {
		printf("do-while\n");
	} while (0);
	///////////////////////////////////////////
	// �ݺ����� ��ø

	return 0;
}
