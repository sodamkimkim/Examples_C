#include <stdio.h>

// <�Լ�>
// ��ȯ�� �Լ���(�Ű�����)

// # �Լ� �����(Function Declaration)
// �����Ϸ��� �Լ� ���� ���°� �ƴ϶� �Լ��� ���¸� ����.
// ���ڷ���
void PrintHelloFunc(void);
int SumWithInt(int, int); // ���� �ο����� �ڷ����� �����൵ �ȴ�.
// �׷��� ���� �� �����ϴ� ���� �����Ѵ�.
// �������� ������ ������
//  ����θ� ������ � �ڸ��� � ���� �־�� �� �� �𸣹Ƿ�
//  ���� ���Ǻ� Ȯ���� �ʿ��ϱ� �����̴�.
// int Sum(int hp, int mp);
void PrintSumResult(int result);

// # ���� ���� (Global - Variables)
// ���α׷� ���۶� �޸𸮿� �ö󰬴ٰ� ���α׷��� ����� �� �����´�.
// ���������� stack���� �������� �ʰ� Data������ ����.
int g_val = 100;
void Test();

int main() {


	int var = 0;
	printf("var : %d (�ּ�: %p)\n", var, &var);
	int local = 0;
	{
		int var = 1;
		printf("var : %d (�ּ�: %p)\n", var, &var);
		var = 100;
		local = 100;
		printf("local : %d\n", local);

	}
	Test();
	Test();

	return 0;
}


static int i = 0;
void Test() {
	for (; i < 5; ++i)
		printf("%d\n", i);
	printf("\n");
}