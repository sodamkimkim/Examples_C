#include <stdio.h> // #으로 시작하는 것은 전처리기(Pre-Process)
/*
- 전처리기는 컴파일과정을 하기 전에 뭔가를 처리하는 것임.
- include : 뭔가를 포함시킴. <stdio.h>를 밑에 소스코드가 실행되는 데에 필요한 것들을 들고오겠다.
- <>는 경로. 여기서 c언어가 들어가있는 경로를 의미함. .h는 확장자. 저 파일을 지금 포함시키겠다.
- std: Standard
- io: Input-output
- .h: Header File
*/

// 함수(Function)
// 반환형 함수명(매개변수)
// Return-Type Function-Name(Parameters)
// 자료형(Data-Type)
// int 정수형
// 함수 선언 : Function Declaration
// 함수 정의 : Function Definition
int main()
{
	printf("Hello, world!\n");
	return 0;
}