#include <stdio.h>
#include <limits.h>

// # �Լ�������(Function Pointer)
// �Լ��� �ּҸ� �����ϴ� ������
void Foo();
void (*pFoo)(); // �Լ������� ����. ��ȯ���� void, �Ű����� ����
int Calculator(int (*pCal)(int, int), int _lhs, int _rhs);
double DCalculator(double (*pCalc)(int, int), int _lhs, int _rhs);

int Sum(int _lhs, int _rhs);
int Sub(int _lhs, int _rhs);
int Mul(int _lhs, int _rhs);
double Div(int _lhs, int _rhs);

// ���(Recursion)
void Recursion(int _num);

int main() {
	//void (*pFoo)() = Foo;
	pFoo = Foo; // &���� Foo�� ���� : means, �Լ� �̸��� �ּҴ�
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
		return INT_MIN;// int min ���� ���� �� ��� �����ڵ�� ����ϰ� ��.
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
	// return (int)((float)_lhs / _rhs);//�ڷ����� �°�, int�� ����ȯ�ؼ� int�� ��ȯ�� �� �̷��� ����.
}

void Recursion(int _num)
{
	int val = 0; // ��͸��� �������� �޸��Ҵ� �����Ǳ� ������ stack-overflow ���� �� �ִ�.
	if (_num == 0) return;
	printf("Recursion: %d\n", _num);
	// ��� ȣ��(Recursion Call)
	Recursion(_num-1); // �������� �������� �Լ� ������.
	printf("Recursion-End: %d\n", _num); // ********* �������� ������ �Լ� ������ ��µȴ�. �� ���� �ݴ�� ������ �ȴ�.
}