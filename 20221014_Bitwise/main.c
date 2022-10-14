#include <stdio.h>

char* CheckFlag(unsigned char _flags, unsigned char _checkFlag);
int main() {
	// 비트단위 연산자(Bitwise Operator)
	// & (AND)
	printf("3 & 5 = %d\n", 3 & 5);
	// | ( OR )
	printf("3 | 5 = %d\n", 3 | 5);
	// ^ (XOR) : 다르면 참
	printf("3 ^ 5 = %d\n", 3 ^ 5);
	// ~ (NOT) : 현재있는 논리 값을 부정
	printf("~3 = %d\n", ~3);

	// <<(left-shift) -> 왼쪽으로 한 번 밀때마다 두배가 된다.
	printf("3 << 1 = %d\n", 3 << 1);
	// >>(right-shift) -> 오른쪽으로 밀고 원래 값의 반이 된다.
	printf("15 >> 2 = %d\n", 15 >> 2);

	int var = 3;
	var ^= 1;
	var &= 4;
	var <<= 2;

	////////////////////////////////////
	printf("\n");

	// 비트플래그(Bit-Flag)

	// 움직이면 안되니까 상수로 만들어서 사용 
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

	// 옵션들을 한방에 켜기
	bitFlags = fullScreen | move | mouseClick; // bitFlag 켜져있으면 그대로 1일 테고 아니면 or연산을 통해서 켜진다.

	/*bitflags는 빠르고 간단하게 연산한다. 실제로 디바이스 레이아웃 설정 등에 사용한다.


	1. bitflags를 한눈에 보고싶을때? 2진수로 표시 과제
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
