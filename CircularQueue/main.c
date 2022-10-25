// 원형 큐
// queue를 보완한 큐
// get했을 때 데이터를 다 밀어줘야 하는 것을 보완함. (int가 아니라 struct 인 경우 더더욱 까다롭다.)

/*
Head, Tail 필요
입력할 땐 head만 움직이고, get하면 tail움직임
=> 미는거 필요없어짐
근데 이거 1차원 배열로 만들어야함.
*/

#include <stdio.h>
#include <stdlib.h>

// 메모리 할당 함수
int DynamicMemoryForInt(int* _pCQueue, int _QUEUESIZE);

// 원형 queue 알고리즘 함수
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
	printf("메모리 동적할당 완료되었습니다. int * %d = %d byte\n", _QUEUESIZE, 4 * _QUEUESIZE);
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
