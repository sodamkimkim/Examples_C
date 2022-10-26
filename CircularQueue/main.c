#include <stdio.h>
#include <stdlib.h>
#define SAFE_FREE(p) do{if(p){free(p);p=NULL;}}while(0);
#define QUEUESIZE 5
#define ERROR_CODE_NULLPOINTER -1111
#define FULL -9999
/*
# Put : cQueue의 head번째에 데이터를 삽입하는 함수
 - check-full 필요
*/
int Put(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail, const int _data);
/*
# Get : cQueue의 Tail번째의 데이터를 빼내는 함수
 - check-empty 필요
*/
int Get(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail);

/*
# PrintAll : cQueue의 모든 데이터를 출력하는 함수
 - check - empty필요
*/
int PrintAll(int* const _pCQueue, const int const _queueSize, const int  _head, const int _tail);

// 예외처리 함수
void CheckIntNullMemory(int* _memory);
void PrintNullMessage();
int main() {
	const int queueSize = QUEUESIZE;
	// 메모리 공간 할당 및 초기화
	int* pCQueue = (int*)malloc(sizeof(int) * QUEUESIZE);
	CheckIntNullMemory(pCQueue);
	printf("pCQueue address : %p\n", pCQueue);
	int head = 0;
	int tail = 0;
	PrintAll(pCQueue, queueSize, head, tail);
	Put(pCQueue, queueSize, &head, &tail, 10);
	PrintAll(pCQueue, queueSize, head, tail);

	return 0;
}


int Put(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail, const int _data)
{
	// 주소 NULL 체크
	if (*_pCQueue == NULL || *_pHead == NULL || *_pTail == NULL)
	{
		return ERROR_CODE_NULLPOINTER;
	}
	// Full 체크
	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pHead) != NULL)) {
		printf("Circular Queue is Overflow!\n");
		return 1;
	}
	// _head에 데이터 밀어넣어주고
	*(_pCQueue + *_pHead) = _data;
	printf("%d\n", *_pHead);
	// _head ++ 해줘야 하는데 (++_head)%_queueSize값을 넣어줘야함
	*(_pHead) = (++*(_pHead)) % _queueSize;
}

//int Get(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail)
//{
//	// Empty체크
//	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pTail) == NULL)) {
//		printf("Circular Queue is Empty!\n");
//		return;
//	}
//	return 0;
//}

int PrintAll(int* const _pCQueue, const int const _queueSize, const int _head, const int _tail)
{
	// 메모리 널체크
	CheckIntNullMemory(_pCQueue);
	// CQueue empty 체크
	if ((_head == _tail) && (*(_pCQueue+_tail) == NULL)) {
		printf("Circular Queue is Empty!\n");
		return ERROR_CODE_NULLPOINTER;
	}

	// print all 
	// occupied된만큼 찍어줌
	int occupiedSpace = _queueSize - abs(_head - _tail);
	for (int i = 0; i < occupiedSpace; i++)
	{
		int idx = (_tail + i) % _queueSize;
		printf("%d - ", *(_pCQueue + idx));
	}
	printf("(%d / %d)\n\n", occupiedSpace, _queueSize);
	return 0;
}

void CheckIntNullMemory(int* _memory)
{
	if (!_memory)
	{
		PrintNullMessage();
		return;
	}
	return;
}

void PrintNullMessage() {
	printf("Memory is NULL! [%s], [%d]\n", __FILE__,__LINE__);
}