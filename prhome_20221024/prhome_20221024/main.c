#include <stdio.h>

void Recursion(int _num);

int main() {
	Recursion(5);
	return 0;
}

void Recursion(int _num)
{
	int val = 0; // ��͸��� �������� �޸��Ҵ� �����Ǳ� ������ stack-overflow ���� �� �ִ�.
	if (_num == 0) return;
	printf("Recursion: %d\n", _num);
	// ��� ȣ��(Recursion Call)
	Recursion(_num - 1); // �������� �������� �Լ� ������.
	printf("Recursion-End: %d\n", _num); // ********* �������� ������ �Լ� ������ ��µȴ�. �� ���� �ݴ�� ������ �ȴ�.
}