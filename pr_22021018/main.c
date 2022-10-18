#include <stdio.h>

// # 기본 자료형 별칭선언
// HP자료형 바뀌어도 이것만 바꾸고 실행코드 변경 안해도 된다.
typedef char HP;

// # 구조체 선언 - 사용자 정의 자료형
struct _SData1 {
	int i;
	float f;
	HP hp;
	char mp;
	double d;
};

// # 구조체 별칭으로 선언1 : struct _SData2 -> SData2
typedef struct _SData2 {
	int i;
	int i2;
} SDaata2;


// # 구조체 별칭으로 선언2 : struct _SData3 -> SData3
struct _SData3 {
	int i;
	int i2;
};
typedef struct _SData3 SData3;

int main() {
	// 1. 기본방식으로 선언된 구조체 활용
	struct _SData1 sdata1;
	sdata1.i = 100;
	sdata1.f = 3.14f;
	printf("sdata1.i : %i\n", sdata1.i);
	printf("sdata1.f : %f\n", sdata1.f);
	// 2. 구조체 별칭 활용 1

	// 3. 구조체 별칭 활용 2
	return 0;

}
