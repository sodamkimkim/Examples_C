#include <stdio.h>
// �������� LEN�� �־ Ȱ���� �� ����
enum EIdx { A, B, C, D, LEN };


int main() {
	enum EIdx idx;
	printf("idx Size : %d byte\n", sizeof(idx));
	printf("idx Address: %p\n", &idx);

	// ���� �ʱ�ȭ ���� �ʾƵ� 0,1,2,3 ���� �� �ִ�.
	printf("A: %d\n", A);
	printf("B: %d\n", B);
	printf("C: %d\n", C);
	printf("D: %d\n", D);
	//A = 100; // -> ����ü�� ��Ҵ� ����� �ٲ��� �ʴ´�.
	return 0;
}
