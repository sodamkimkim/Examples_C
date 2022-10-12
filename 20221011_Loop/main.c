#include <stdio.h>
int main() {
	// 반복문(Loop)
	// for문(초기문; 조건문; 증감문)
	int i = 0;
	for (i = 0; i < 5; ++i) {
		printf("i : %d\n", i);
	}
	// 선 증가, 후 증가 연산자
	// ++i, i++
	// --i, i--

	float fVal = 0.5f;
	++fVal;
	printf("fVal : %f\n", fVal);

	// 사칙연산자
	int lhs = 3, rhs = 2;
	printf("lhs + rhs = %d\n", lhs + rhs);
	printf("lhs - rhs = %d\n", lhs - rhs);
	printf("lhs * rhs = %d\n", lhs * rhs);

	// 형변환(Type-Casting, Type-Conversion)
	// 묵시적 형변환
	float f = lhs / rhs; // -> 1.000000 출력
	printf("lhs / rhs = %f\n", f);

	// 명시적 형변환
	// 자료형의 승격(정밀도가 높은 쪽으로 결과 값 자료형이 따라 간다.)
	printf("lhs / rhs = %f\n", (float)lhs / rhs); // -> 1.500000 출력
	printf("lhs / rhs = %f\n", (float)(lhs / rhs)); // 정수계산한 것을 float로 형 변환 -> 1.000000 출력

	printf("lhs % rhs = %d\n", lhs % rhs);

	// 삼항연산자
	// 조건 ? 참 : 거짓
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
	// 반복문의 중첩

	return 0;
}
