#include <stdio.h>

void Recursion(int _num);

int main() {
	Recursion(5);
	return 0;
}

void Recursion(int _num)
{
	int val = 0; // 재귀마다 지역변수 메모리할당 누적되기 때문에 stack-overflow 생길 수 있다.
	if (_num == 0) return;
	printf("Recursion: %d\n", _num);
	// 재귀 호출(Recursion Call)
	Recursion(_num - 1); // 종료조건 나오고나야 함수 끝난다.
	printf("Recursion-End: %d\n", _num); // ********* 종료조건 나오고 함수 끝나야 출력된다. 들어간 순서 반대로 나오게 된다.
}