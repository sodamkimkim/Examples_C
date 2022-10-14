#include <stdio.h>

char* CheckFlag(unsigned char _flags, unsigned char _checkFlag);
int main() {
	// ��Ʈ���� ������(Bitwise Operator)
	// & (AND)
	printf("3 & 5 = %d\n", 3 & 5);
	// | ( OR )
	printf("3 | 5 = %d\n", 3 | 5);
	// ^ (XOR) : �ٸ��� ��
	printf("3 ^ 5 = %d\n", 3 ^ 5);
	// ~ (NOT) : �����ִ� �� ���� ����
	printf("~3 = %d\n", ~3);

	// <<(left-shift) -> �������� �� �� �ж����� �ι谡 �ȴ�.
	printf("3 << 1 = %d\n", 3 << 1);
	// >>(right-shift) -> ���������� �а� ���� ���� ���� �ȴ�.
	printf("15 >> 2 = %d\n", 15 >> 2);

	int var = 3;
	var ^= 1;
	var &= 4;
	var <<= 2;

	////////////////////////////////////
	printf("\n");

	// ��Ʈ�÷���(Bit-Flag)

	// �����̸� �ȵǴϱ� ����� ���� ��� 
	const unsigned char fullScreen = 1;
	const unsigned char useController = 2;
	const unsigned char mouseClick = 4;
	const unsigned char move = 8;


	unsigned char bitFlags = 0;
	bitFlags |= fullScreen;
	bitFlags |= mouseClick;
	bitFlags |= fullScreen;
	printf("bitFlags : %d\n", bitFlags);

	//printf("Full Screen: %s\n", (bitFlags & fullScreen) != 0 ? "True" : "False");
	printf("Full Screen: %s\n", CheckFlag(bitFlags, fullScreen));
	printf("Move : %s\n", (bitFlags & move) != 0 ? "True" : "False");

	bitFlags ^= fullScreen;

	printf("Full Screen: %s\n", CheckFlag(bitFlags, fullScreen));

	// �ɼǵ��� �ѹ濡 �ѱ�
	bitFlags = fullScreen | move | mouseClick; // bitFlag ���������� �״�� 1�� �װ� �ƴϸ� or������ ���ؼ� ������.

	/*bitflags�� ������ �����ϰ� �����Ѵ�. ������ ����̽� ���̾ƿ� ���� � ����Ѵ�.


	1. bitflags�� �Ѵ��� ���������? 2������ ǥ�� ����
	*/
	char tmp1 = 4;
	tmp1 = 4 | 128;


	printf("%d\n",tmp1); // -124
	printf("%d\n", tmp1 + 128); // 4

	int tmp2 = 4;
	tmp2 = 4 | 2147483648;
	printf("tmp2 = %d\n", tmp2);
	printf("\n");

	printf("bitFlags: %d\n\n", bitFlags);
	for (int i = 7; i >= 0; --i) {
		int result = bitFlags >> i & 1;
		printf("%d", result);
	}

	printf("\n");

	return 0;


}

char* CheckFlag(unsigned char _flags, unsigned char _checkFlag) {
	return (_flags & _checkFlag) != 0 ? "True" : "False";
}
