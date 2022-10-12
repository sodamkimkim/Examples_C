#include <stdio.h>

// <함수>
// 반환형 함수명(매개변수)

// # 함수 선언부(Function Declaration)
// 컴파일러가 함수 명을 보는게 아니라 함수의 형태를 본다.
// ㄴ자료형
void PrintHelloFunc(void);
int SumWithInt(int, int); // 선언 부에서는 자료형만 적어줘도 된다.
// 그런데 변수 명도 선언하는 것을 권장한다.
// 변수명이 안적혀 있으면
//  선언부만 보고서는 어떤 자리에 어떤 값을 넣어야 할 지 모르므로
//  굳이 정의부 확인이 필요하기 때문이다.
// int Sum(int hp, int mp);
void PrintSumResult(int result);

// # 전역 변수 (Global - Variables)
// 프로그램 시작때 메모리에 올라갔다가 프로그램이 종료될 때 내려온다.
// 전역변수가 stack에서 관리되지 않고 Data영역에 들어간다.
int g_val = 100;
void Test();

int main() {


	int var = 0;
	printf("var : %d (주소: %p)\n", var, &var);
	int local = 0;
	{
		int var = 1;
		printf("var : %d (주소: %p)\n", var, &var);
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