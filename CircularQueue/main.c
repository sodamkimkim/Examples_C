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
# Put : cQueue�� head��°�� �����͸� �����ϴ� �Լ�
 - check-full �ʿ�
*/
int Put(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail, const int _data);
/*
# Get : cQueue�� Tail��°�� �����͸� ������ �Լ�
 - check-empty �ʿ�
*/
int Get(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail);

/*
# PrintAll : cQueue�� ��� �����͸� ����ϴ� �Լ�
 - check - empty�ʿ�
*/
int PrintAll(int* const _pCQueue, const int const _queueSize, const int  _head, const int* const _pTail);

// ����ó�� �Լ�
void CheckIntNullMemory(int* _memory);
void PrintNullMessage(char* _memory);
int main() {
	const int queueSize = QUEUESIZE;
	// �޸� ���� �Ҵ� �� �ʱ�ȭ
	int* pCQueue = (int*)malloc(sizeof(int) * QUEUESIZE);
	CheckIntNullMemory(pCQueue);

	printf("pCQueue address : %p\n", pCQueue);

	// queue ���� �� �ʱ�ȭ
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
	// �ּ� NULL üũ
	CheckIntNullMemory(_pCQueue);
	CheckIntNullMemory(_pHead);
	CheckIntNullMemory(_pTail);

	printf("Try Put: %d\n",_data);

	// Full üũ
	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pHead) != NULL)) {
		printf("Circular Queue is Overflow!\n");
		return 1;
	}

	// _head�� ������ �о�־��ְ�
	*(_pCQueue + *_pHead) = _data;
	// _head ++ ����� �ϴµ� (++_head)%_queueSize���� �־������
	*(_pHead) = (++*(_pHead)) % _queueSize;
#ifdef DEBUG_MODE_PUT
	printf("_head : %d\n", *_pHead); 
#endif
}

int Get(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail)
{
	// �ּ� NULL üũ
	CheckIntNullMemory(_pCQueue);
	CheckIntNullMemory(_pHead);
	CheckIntNullMemory(_pTail);


	// Queue Emptyüũ
	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pTail) == NULL)) {
		printf("Circular Queue is Empty! (%d / %d)\n", 0, _queueSize);
		return NULL;
	}

	// getData ������ְ� �ʱ�ȭ
	int getData = *(_pCQueue + *_pTail);
	*(_pCQueue + *_pTail) = NULL;

#ifdef DEBUG_MODE_GET
	printf("getData: %d\n", getData);
	printf("��ȭ �� * (_pTail): %d\n", *(_pTail));
#endif
	// Tail�Ű��ֱ�. �ٵ� ++tail % queuesize
	* (_pTail) = (++ * (_pTail)) % _queueSize;
#ifdef DEBUG_MODE_GET
	printf("��ȭ �� * (_pTail): %d\n", *(_pTail));
#endif
	return getData;
}

int PrintAll(int* const _pCQueue, const int const _queueSize, const int _head, const int* const _pTail)
{
	int occupiedSpace = 0;

	// �޸� ��üũ
	CheckIntNullMemory(_pCQueue);
	
	// occupied�ȸ�ŭ �����
	
	occupiedSpace = (*(_pTail) >= _head) ? _queueSize - abs(_head - *(_pTail)) : abs(_head - *(_pTail)); // head�� ū ���� ������ 1��~5��
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