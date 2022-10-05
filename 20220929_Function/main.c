#include <stdio.h>
// 함수 선언(Function Declaration)
// 반환형 함수명(매개변수)
// Return-Type Function-Name(Parameter)
// 함수 정의(Function Definition)
int Add3(int _val); // 함수 선언
void PrintHelloWorld(void);

int Add3(int _val) // 정의
{
	// int tmp = _val *2;
	// tmp /= 3;
	// tmp += 10;
	// return tmp;
	return _val + 3;

}
int main() {
	// 함수(Funciton)
	// 함수 호출(Function Call)
	// 매개변수 - 인자 : Parameter - Argument
	printf("Add3(10) : %d\n", Add3(10));
	return 0;

}
void PrintHelloWorld(void) {
	printf("Hello, World\n");
}