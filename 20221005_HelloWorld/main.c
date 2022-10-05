// Source-Code Editor
// High-Level Language
// C Language
// Assembly Language
// Machine Language
// Low-Level Language
// Compile -> Build
// Editor, Compiler, Builder, Debuger합쳐놓은거 --> IDE(Intergrated Development Environment) : 통합 개발 환경

// Debug : 버그 잡아주는 코드까지 들어가있는 거
// Release : 기능만(구매해서 실행하는 프로그램들은 모두 release)

// #: 전처리기(Pre-Process}
//  include: 포함하다.
// <> : 경로. c언어가 설치되어있는 곳(c언어의 기본적인 기능들이 들어있는 곳)
// .stdio: Standard Input - Output
// .h : Header File // 예를들어 기능printf를 해석해서 headerfile이 모니터에 띄워준다.(기능구현 코드들이 정의되어있다.)
#include <stdio.h>

// 함수(Function)
// 반환형 함수명(매개변수)
// main함수는 Entry-Point
int main() {

	// 함수 호출(Function Call)
	// printf: Print-Format
	printf("Hello, World\n");

	// return 숫자;
	// 프로그램이 제대로 종료되었는지 알 수 있다.
	// 통상적으로 return 0; 은 정상종료, return -1; 은 문제가 있게 종료가 되었다. 이렇게 사용
	return 0;
}