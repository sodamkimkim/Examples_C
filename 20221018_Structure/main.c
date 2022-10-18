#include <stdio.h>

typedef char HP; // 기본 자료형을 typedef를 통해서 다른식으로 부를 수 있다.
// HP자료형이 바뀌어도 이것만 바꾸면 된다.

// 구조체 (Structure) - 사용자 정의 자료형
typedef struct _SData {

	// 구조체 멤버변수(Member Variables)
	// 선언과 동시에 초기화는 불가능.
	// 구조체의 패딩(padding)
	// cpu는 어차피 4byte씩 읽는다. 
	// ㄴ 한번에 읽을 수 있도록 부족한 부분은 padding처리해 준다.
	int i;
	float f;
	HP hp; // 1byte인데 4byte잡음
	char mp; // 1byte인데 4byte잡음 => 메모리 낭비
	double d;

	// 구조체를 설계할 때, 패딩을 고려해서 메모리 낭비가 최소화 될 수 있도록 하자.
} SData; // 구조체 별칭선언

//typedef struct _SData SData;

////////////////////////////////////////////////////////////////////////////////////////////
// 공용체(Union)
union UMem
{
	// 공용체는 메모리 공간을 멤버들이 공용으로 사용하는 것이다.
	// Union의 메모리 사이즈는 큰 것 기준으로 나온다.
	// 마지막에 넣은 자료형으로 바뀌어서 출력된다.
	int i;
	float f;
	char c;
	double d;
};
////////////////////////////////////////////////////////////////////////////////////////////
// 열거체(열거형, Enumerated Type, Enumeration)
enum EIdx { A, B = 100, C, D, LEN };
enum Anim{ kIdle, kRun, kAttack, kJump, kLen }; // 애니메이션 상수로 활용하기
enum EOption{ // BitFlags에 활용하기
	FullScreen = 1,
	UseController = 2,
	MouseClick = 4,
	Move = 8
};

void main() {
	//struct _SData data;
	SData data;
	// ' .  '-> 구조체 멤버 접근 연산자(Member Access Operator)
	data.i = 100;
	data.f = 3.14f;
	printf("data.f : %f\n", data.f);

	struct _SData info;
	info.i = 123;
	printf("info.i: %d\n", info.i);

	printf("\n");
	SData sData = { 200, 200.5f, 5,8, 123.5f };
	printf("sData Address: %p\n", &sData);
	printf("sData size: %d byte\n", sizeof(sData));
	printf("\n");
	printf("sData.i : %d (%p)\n", sData.i, &sData.i);
	printf("sData.f : %f (%p)\n", sData.f, &sData.f);
	printf("sData.hp : %d (%p)\n", sData.hp, &sData.hp);
	printf("sData.mp : %d (%p)\n", sData.mp, &sData.mp);
	printf("sData.d : %lf (%p)\n", sData.d, &sData.d);

	////////////////////////////////////////////////////////////////////////
	printf("\n");

	// 구조체 복사하기
	SData dataCpy = sData;
	printf("dataCpy.i : %d\n", dataCpy.i);
	printf("dataCpy.d : %lf\n", dataCpy.d);

	////////////////////////////////////////////////////////////////////////
	printf("\n");
	union UMem mem;
	mem.f = 3.14f;
	mem.i = 100;
	mem.d = 3.14;

	printf("mem Size : %d byte\n", sizeof(mem));
	printf("mem Address: %p\n", &mem);
	printf("mem.i : %d (%p)\n", mem.i, &mem.i);
	printf("mem.f : %f (%p)\n", mem.f, &mem.f);
	printf("mem.d : %lf (%p)\n", mem.d, &mem.d);

	////////////////////////////////////////////////////////////////////////
	printf("\n");
	enum EIdx idx;
	printf("idx Size: %d byte\n", sizeof(idx));
	printf("idx Address: %p\n", &idx);

	// 따로 초기화 하지 않아도 0, 1, 2, 3으로 값이 들어가 있다.
	printf("A: %d\n", A);
	printf("B: %d\n", B);
	printf("C: %d\n", C);
	printf("D: %d\n", D);
	//A = 100; // -> 열거체의 요소는 상수라서 바뀌지 않는다.

	// switch - case에서 많이 사용한다. (리터럴 상수만 가능했었음)
	idx = A;
	switch (idx)
	{
	case A: printf("idx = A"); break;
	case B: printf("idx = B"); break;
	case C: printf("idx = C"); break;
	defalut: break;
	}

	// 배열에도 사용이 가능하다. (배열에도 리터럴 상수만 가능했었음)
	int arr[LEN];
	// arr[HP] = 100; //이런식으로 사용하면 arr[0]이런거 보다 가독성이 좋다.
	arr[B] = 100;
	arr[C] = 40;
	
}
