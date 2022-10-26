#include <stdio.h>
#include <stdlib.h>
#define SAFE_FREE(p) do{if(p){free(p);p=NULL;}}while(0);
#define QUEUESIZE 5
#define ERROR_CODE_NULLPOINTER -1111
#define FULL -9999
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
int PrintAll(int* const _pCQueue, const int const _queueSize, const int  _head, const int _tail);

// ����ó�� �Լ�
void CheckIntNullMemory(int* _memory);
void PrintNullMessage();
int main() {
	const int queueSize = QUEUESIZE;
	// �޸� ���� �Ҵ� �� �ʱ�ȭ
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
	// �ּ� NULL üũ
	if (*_pCQueue == NULL || *_pHead == NULL || *_pTail == NULL)
	{
		return ERROR_CODE_NULLPOINTER;
	}
	// Full üũ
	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pHead) != NULL)) {
		printf("Circular Queue is Overflow!\n");
		return 1;
	}
	// _head�� ������ �о�־��ְ�
	*(_pCQueue + *_pHead) = _data;
	printf("%d\n", *_pHead);
	// _head ++ ����� �ϴµ� (++_head)%_queueSize���� �־������
	*(_pHead) = (++*(_pHead)) % _queueSize;
}

//int Get(int* const _pCQueue, const int const _queueSize, int* const _pHead, int* const _pTail)
//{
//	// Emptyüũ
//	if ((*_pHead == *_pTail) && (*(_pCQueue + *_pTail) == NULL)) {
//		printf("Circular Queue is Empty!\n");
//		return;
//	}
//	return 0;
//}

int PrintAll(int* const _pCQueue, const int const _queueSize, const int _head, const int _tail)
{
	// �޸� ��üũ
	CheckIntNullMemory(_pCQueue);
	// CQueue empty üũ
	if ((_head == _tail) && (*(_pCQueue+_tail) == NULL)) {
		printf("Circular Queue is Empty!\n");
		return ERROR_CODE_NULLPOINTER;
	}

	// print all 
	// occupied�ȸ�ŭ �����
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