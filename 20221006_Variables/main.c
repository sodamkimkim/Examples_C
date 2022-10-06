#include <stdio.h>
#include <limits.h>
int main()
{
	// # ����(Variable)
	// ���� ����(Variable Declaration)
	int val = 10;	
	val = 5;

	char c = 'a';
	printf("c: %c\n", c);
	printf("char size: %d byte\n", sizeof(char));
	printf("c Address: %p\n", &c);
	printf("===================================\n");

	// # ������(Integer Type)
	 /*# Most Significant Bit(MSB, �ֻ��� ��Ʈ) --> ��ȣ��Ʈ��  0�̸� ���, 1�̸� ����
	 1����Ʈ = 2���� 8��Ʈ (2�� 8���� 256)������ ��ȣ��Ʈ ������ 1����Ʈ ������ -127~127ǥ������
	 int�� ���� signed int (��ȣ�� �ִ� int)
	 */

	// # 2�� ������ ; ��ǻ�Ͱ� ������ ǥ���ϴ� ���
	// 1�� �������� +1
	signed int si = -1;
	printf("signed int : %d\n", si);
	printf("si size: %d\n", sizeof(si));
	unsigned int usi = -1; // ��ȣ���� int ������ -1�� ���� ��
	printf("unsigned int : %d\n", usi);
	printf("usi size: %d\n", sizeof(usi));

	printf("int Range: %d ~ %d\n", INT_MIN, INT_MAX); // #include <limits.h> ���ܿ���
	printf("===================================\n");
	// int �� 4byte�� ��ȣ�ڸ� + (+-)2�� 31�±��� ǥ�� ����
	// 0�� ����
	// �׷��� int range : -2,147,483,648 ~ 2,147,483,647
	int aaa = 2147483648; // ���: -2147483648
	int bbb = 2147483649; // ���: -2147483647
	int ccc = 2147483650; // ���: -2147483646
	int ddd = 2147483651; // ���: -2147483645
	printf("%d\n",aaa);
	printf("%d\n",bbb);
	printf("%d\n",ccc);
	printf("%d\n",ddd);
	
	printf("===================================\n");
	short s = 1;
	printf("short %d byte, %p\n", sizeof(s), &s);
	int i = 12;
	printf("int %d byte, %p\n", sizeof(i), &i);
	long l = 123;
	printf("long %d byte, %p\n", sizeof(l), &l);
	long long ll = 1234;
	printf("long long %d byte, %p\n", sizeof(ll), &ll);

	printf("===================================\n");
	// # �Ǽ���(Floating-Point Type)
	// # �ε��Ҽ���(Floating-Point)
	float f = 1.1f; // float f = 1.1 �̷��� f �Ⱥ��̸� double�� float���ٰ� �ִ� ����.
	// # double�� �ι� �� ��Ȯ�� ���� �Ǽ� �̴�. ������ �ٸ�.
	// float�� �� f �ٿ�����.
	// float : 4byte, double: 8byte
	printf("float %d byte, %p\n", sizeof(f), &f);

	// Double - Precision Floating - Point
	double d = 1.1;
	printf("double %d byte, %p\n", sizeof(d), &d);
	long double ld = 1.12;
	printf("long double %d byte, %p\n", sizeof(ld), &ld);
	printf("===================================\n");
	
	// # �ε� �Ҽ��� ����
	// ������ ����ٴ� ���� ���� �ϰ� ��������� �Ѵ�.
	// ��ǻ�Ͱ� �ε��Ҽ����� ����ϱ� ���ؼ� ����� ����� ���� ������.
	int idx = 0;
	float result = 0.0f;
	for (idx = 0; idx < 1000; ++idx)
		result += 0.001f;
	printf("result: %f\n", result);
	return 0;

	

}