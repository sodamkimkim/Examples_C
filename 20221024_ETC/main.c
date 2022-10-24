#include <stdio.h>
#include <limits.h>

// # 함수포인터(Function Pointer)
// 함수의 주소를 저장하는 포인터
void Foo();
void (*pFoo)(); // 함수포인터 선언. 반환형이 void, 매개변수 없음
int Calculator(int (*pCal)(int, int), int _lhs, int _rhs);
double DCalculator(double (*pCalc)(int, int), int _lhs, int _rhs);

int Sum(int _lhs, int _rhs);
int Sub(int _lhs, int _rhs);
int Mul(int _lhs, int _rhs);
double Div(int _lhs, int _rhs);

// 재귀(Recursion)
void Recursion(int _num);

int main() {
	//void (*pFoo)() = Foo;
	pFoo = Foo; // &없이 Foo가 들어간다 : means, 함수 이름은 주소다
	printf("pFoo Address: %p\n", pFoo);
	pFoo();

	printf("Calculator Sum: %d\n", Calculator(Sum, 3, 5));
	printf("Calculator Sub: %d\n", Calculator(Sub, 3, 5));
	printf("Calculator Mul: %d\n", Calculator(Mul, 3, 5));
	printf("Calculator Div: %f\n", DCalculator(Div, 10, 5));

	///////////////////////////////////////
	printf("\n");
	Recursion(5);
	return 0;
}

void Foo() {
	printf("Hello, Function!\n");
}

int Calculator(int (*pCalc)(int, int), int _lhs, int _rhs)
{
	if (pCalc == NULL) {
		printf("pCalc is NULL!\n");
		return INT_MIN;// int min 거의 나올 일 없어서 에러코드로 사용하곤 함.
	}
	return pCalc(_lhs, _rhs);
}

double DCalculator(double (*pCalc)(int, int), int _lhs, int _rhs)
{

	if (pCalc == NULL)
	{
		printf("pCalc is NULL!\n");
		return INT_MIN;
	}
	return pCalc(_lhs, _rhs);
}

int Sum(int _lhs, int _rhs)
{
	return _lhs + _rhs;
}

int Sub(int _lhs, int _rhs)
{
	return _lhs - _rhs;
}

int Mul(int _lhs, int _rhs)
{
	return _lhs * _rhs;
}

double Div(int _lhs, int _rhs)
{
	double result;
	result = _lhs / _rhs;
	return result;
	// return (int)((float)_lhs / _rhs);//자료형의 승격, int로 형변환해서 int로 반환할 땐 이렇게 쓴다.
}

void Recursion(int _num)
{
	int val = 0; // 재귀마다 지역변수 메모리할당 누적되기 때문에 stack-overflow 생길 수 있다.
	if (_num == 0) return;
	printf("Recursion: %d\n", _num);
	// 재귀 호출(Recursion Call)
	Recursion(_num-1); // 종료조건 나오고나야 함수 끝난다.
	printf("Recursion-End: %d\n", _num); // ********* 종료조건 나오고 함수 끝나야 출력된다. 들어간 순서 반대로 나오게 된다.
}