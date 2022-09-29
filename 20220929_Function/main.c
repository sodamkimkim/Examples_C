#include <stdio.h>

// 함수 선언(function declaration)
// 반환형 함수명(매개변수)
// return-type functino-name(parameter)
// 함수 정의(function definition)
//int add3(int _val); // 함수 선언
//void printhelloworld(void);
//
//int add3(int _val) // 정의
//{
//	int tmp = _val * 2;
//	tmp /= 3;
//	tmp += 10;
//	return tmp;
//	return _val + 3;
//}
//int main() {
//	 함수(function)
//	 함수 호출(function call)
//	 매개변수 - 인자 : parameter - argument
//	printf("add3(10) : %d\n", add3(10));
//	return 0;
//}
//void ptinthelloword(void) {
//	printf("hello, world!\n");
//}

int main() {
	int n = 0;
	printf("피라미드 높이 입력하세요: ");
	scanf_s("%d",&n);
	int j = 1;
	int xn = n/2;
	int yn = (n%2)*(xn+1);
	int zn = (1+n)*xn+yn;
	for (int i = 1; i <= zn; i++) {
		printf("*");

		int xj = j / 2;
		int yj= (j % 2) * (xj + 1);
		int zj = (1 + j) * xj + yj;
		if (i == zj) {
			printf("\n");
			j++;
		}
	}

}