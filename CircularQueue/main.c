#include <stdio.h>
#include <stdlib.h>
#define SAFE_FREE(p) do{if(p){free(p);p=NULL;}}while(0);
#define QUEUESIZE 5
#define ERROR_CODE_NULLPOINTER -1111
#define FULL -9999
//#define DEBUG_MODE_PUT
//#define DEBUG_MODE_GET
//#define DEBUG_MODE_PRINT
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
int PrintAll(int* const _pCQueue, const int const _queueSize, const int  _head, const int* const _pTail);

// 예외처리 함수
void CheckIntNullMemory(int* _memory);
void PrintNullMessage(char* _memory);
int main() {
	const int queueSize = QUEUESIZE;
	// 메모리 공간 할당 및 초기화
	int* pCQueue = (int*)malloc(sizeof(int) * QUEUESIZE);
	CheckIntNullMemory(pCQueue);

	printf("pCQueue address : %p\n", pCQueue);

	// queue 내부 값 초기화
	for (int i = 0; i < queueSize; i++) {
		*(pCQueue + i) = NULL;
	}
	int head = 0;
	int tail = 0;
	PrintAll(pCQueue, queueSize, head, &tail);
	Put(pCQueue, queueSize, &head, &tail, 10);
	Put(pCQueue, queueSize, &head, &tail, 10);
	Put(pCQueue, queueSize, &head, &tail, 10);
	Put(pCQueue, queueSize, &head, &tail, 10);
	Put(pCQueue, queueSize, &head, &tail, 10);
	PrintAll(pCQueue, queueSize, head, &tail);

	Put(pCQueue, queueSize, &head, &tail, 10);
	Put(pCQueue, queueSize, &head, &tail, 10);
	PrintAll(pCQueue, queueSize, head, &tail);

	printf("\n===================\n");
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	PrintAll(pCQueue, queueSize, head, &tail);
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	PrintAll(pCQueue, queueSize, head, &tail);
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	printf("Get : %d\n", Get(pCQueue, queueSize, &head, &tail));
	PrintAll(pCQueue, queueSize, head, &tail);



	return 0;
}

int Put(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail, const int _data)
{
	// 주소 NULL 체크
	CheckIntNullMemory(_pCQueue);
	CheckIntNullMemory(_pHead);
	CheckIntNullMemory(_pTail);

	printf("Try Put: %d\n",_data);

	// Full 체크
	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pHead) != NULL)) {
		printf("Circular Queue is Overflow!\n");
		return 1;
	}

	// _head에 데이터 밀어넣어주고
	*(_pCQueue + *_pHead) = _data;
	// _head ++ 해줘야 하는데 (++_head)%_queueSize값을 넣어줘야함
	*(_pHead) = (++*(_pHead)) % _queueSize;
#ifdef DEBUG_MODE_PUT
	printf("_head : %d\n", *_pHead); 
#endif
}

int Get(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail)
{
	// 주소 NULL 체크
	CheckIntNullMemory(_pCQueue);
	CheckIntNullMemory(_pHead);
	CheckIntNullMemory(_pTail);


	// Queue Empty체크
	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pTail) == NULL)) {
		printf("Circular Queue is Empty! (%d / %d)\n", 0, _queueSize);
		return NULL;
	}

	// getData 백업해주고 초기화
	int getData = *(_pCQueue + *_pTail);
	*(_pCQueue + *_pTail) = NULL;

#ifdef DEBUG_MODE_GET
	printf("getData: %d\n", getData);
	printf("변화 전 * (_pTail): %d\n", *(_pTail));
#endif
	// Tail옮겨주기. 근데 ++tail % queuesize
	* (_pTail) = (++ * (_pTail)) % _queueSize;
#ifdef DEBUG_MODE_GET
	printf("변화 후 * (_pTail): %d\n", *(_pTail));
#endif
	return getData;
}

int PrintAll(int* const _pCQueue, const int const _queueSize, const int _head, const int* const _pTail)
{
	int occupiedSpace = 0;

	// 메모리 널체크
	CheckIntNullMemory(_pCQueue);
	
	// occupied된만큼 찍어줌
	
	occupiedSpace = (*(_pTail) >= _head) ? _queueSize - abs(_head - *(_pTail)) : abs(_head - *(_pTail)); // head가 큰 경우는 데이터 1개~5개
#ifdef DEBUG_MODE_PRINT
	printf("abs(head - tail) : %d\n", abs(_head - _tail));
	printf("occupiedSpace: %d\n", occupiedSpace);
#endif
	if ((*(_pCQueue + *_pTail) == NULL) && (_head >= *_pTail)) {
		occupiedSpace = 0;
	}
	for (int i = 0; i < occupiedSpace; i++)
	{
		int idx = (*(_pTail)+ i) % _queueSize;
		printf("%d - ", *(_pCQueue + idx));
	}
	printf("(%d / %d)\n", occupiedSpace, _queueSize);
	return;
}

void CheckIntNullMemory(int* _memory)
{
	if (!_memory)
	{
		PrintNullMessage(_memory);
		return;
	}
	return;
}

void PrintNullMessage(char* _memory) {
	printf("[ %s ] Memory is NULL! [%s], [%d]\n",_memory, __FILE__,__LINE__);
}