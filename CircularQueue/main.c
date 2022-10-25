// ���� ť
// queue�� ������ ť
// get���� �� �����͸� �� �о���� �ϴ� ���� ������. (int�� �ƴ϶� struct �� ��� ������ ��ٷӴ�.)

/*
Head, Tail �ʿ�
�Է��� �� head�� �����̰�, get�ϸ� tail������
=> �̴°� �ʿ������
�ٵ� �̰� 1���� �迭�� ��������.
*/

#include <stdio.h>
#include <stdlib.h>

// �޸� �Ҵ� �Լ�
int DynamicMemoryForInt(int* _pCQueue, int _QUEUESIZE);

// ���� queue �˰��� �Լ�
void Put(int* const _pCQueue, int _queueSize, int* const _pHead, int* const _pTail, int _data);
int Get(int const _pCQueue, int _queueSize, int* const _pHead, int* const _pTail);

void PrintAll(const int* const _pCQueue, int _queueSize, int* _pHead, int* _pTail);

int main() {
	const int QUEUE_SIZE = 8
		;
	int* pCQueue = NULL;
	DynamicMemoryForInt(pCQueue, QUEUE_SIZE);
	int* pHead = 0;
	int* pTail = 0;


	return 0;
}

int DynamicMemoryForInt(int* _pCQueue, int _QUEUESIZE)
{
	_pCQueue = (int*)malloc(sizeof(int) * _QUEUESIZE);
	if (_pCQueue == NULL) return -1;
	printf("�޸� �����Ҵ� �Ϸ�Ǿ����ϴ�. int * %d = %d byte\n", _QUEUESIZE, 4 * _QUEUESIZE);
	return 0;
}

void Put(int* const _pCQueue, int _queueSize, int* const _pHead, int* const _pTail, int _data) {
	// check-empty
	if (_pCQueue == NULL)
	{
		printf("pCQueue is NULL\n");
		return;
	}
	// check-full
	// head
	if ()

}
