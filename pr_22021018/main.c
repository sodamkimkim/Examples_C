#include <stdio.h>

// # �⺻ �ڷ��� ��Ī����
// HP�ڷ��� �ٲ� �̰͸� �ٲٰ� �����ڵ� ���� ���ص� �ȴ�.
typedef char HP;

// # ����ü ���� - ����� ���� �ڷ���
struct _SData1 {
	int i;
	float f;
	HP hp;
	char mp;
	double d;
};

// # ����ü ��Ī���� ����1 : struct _SData2 -> SData2
typedef struct _SData2 {
	int i;
	int i2;
} SDaata2;


// # ����ü ��Ī���� ����2 : struct _SData3 -> SData3
struct _SData3 {
	int i;
	int i2;
};
typedef struct _SData3 SData3;

int main() {
	// 1. �⺻������� ����� ����ü Ȱ��
	struct _SData1 sdata1;
	sdata1.i = 100;
	sdata1.f = 3.14f;
	printf("sdata1.i : %i\n", sdata1.i);
	printf("sdata1.f : %f\n", sdata1.f);
	// 2. ����ü ��Ī Ȱ�� 1

	// 3. ����ü ��Ī Ȱ�� 2
	return 0;

}
