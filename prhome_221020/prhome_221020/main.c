#include <stdio.h>
// 마지막에 LEN을 넣어서 활용할 수 있음
enum EIdx { A, B, C, D, LEN };


int main() {
	enum EIdx idx;
	printf("idx Size : %d byte\n", sizeof(idx));
	printf("idx Address: %p\n", &idx);

	// 따로 초기화 하지 않아도 0,1,2,3 값이 들어가 있다.
	printf("A: %d\n", A);
	printf("B: %d\n", B);
	printf("C: %d\n", C);
	printf("D: %d\n", D);
	//A = 100; // -> 열거체의 요소는 상수라서 바뀌지 않는다.
	return 0;
}
