#include <stdio.h>
#include <malloc.h>
#define SAFE_FREE(p) do{if(p){free(p);p=NULL;}}while(0);
#define ERROR_CODE 82828282;
 //#define DEBUG_MODE

/*
# Put
1. pQueue�޸� NULL���� üũ
2. queue full ���� üũ
3. queue�� idx �ڸ��� data�ֱ� -> pQueue�ʿ�. ����Ǵϱ�.
4. idx ++ -> pIdx �ʿ�. ����Ǵϱ�.
*/
void Put(int* const _pQueue, int _queueSize, int* const _pIdx, int _data);

/*
# Get
1. pQueue�޸� NULL���� üũ
2. queue empty���� üũ
3. queue[0] ������ ���� ����
4. ������ ������ �� ĭ�� ������ ����ֱ� ->pQueue�ʿ�. �����ϴϱ�.
5. idx--���ֱ� -> pIdx�ʿ�. �����ϴϱ�.
6. return GetData
*/
int Get(int* const _pQueue, int* const _pIdx);

/*
# PrintAll
queue ������ idx���� �� ������ִ� �Լ�.
1. pQueue�޸� NULL���� üũ
2. emptyüũ
3. for�� ������ �� ���
*/
void PrintAll(const int* const _pQueue, int _idx, int _queueSize);

int main()
{
	const int QUEUE_SIZE = 5;
	int* pQueue = (int*)malloc(sizeof(int) * QUEUE_SIZE);
	if (pQueue == NULL) return -1;
	int idx = 0; // queue �� put�ؾ� �ϴ� ��  != get �ؾ� �ϴ� �� 
	PrintAll(pQueue, idx, QUEUE_SIZE);
	printf("Get: %d\n", Get(pQueue, &idx));
	for (int i = 0; i < 7; ++i) {
		Put(pQueue, QUEUE_SIZE, &idx, i + 1);
	}
	PrintAll(pQueue, idx, QUEUE_SIZE);
	printf("Get: %d\n", Get(pQueue, &idx));
	printf("Get: %d\n", Get(pQueue, &idx));
	PrintAll(pQueue, idx, QUEUE_SIZE);

	SAFE_FREE(pQueue);
	return 0;

}

void Put(int* const _pQueue, int _queueSize, int* const _pIdx, int _data)
{
	if (_pQueue == NULL)
	{
		printf("[%s][%d] : _pQueue is NULL\n", __FILE__, __LINE__);
		return;
	}
	// check - full
	if (*(_pIdx) == _queueSize)
	{
		printf("Queue Overflow!\n");
		return;
	}
	*(_pQueue + ((*_pIdx)++)) = _data;
}

int Get(int* const _pQueue, int* const _pIdx)
{
	if (_pQueue == NULL) {
		printf("[%s][%d] : _pQueue is NULL\n", __FILE__, __LINE__);
		return ERROR_CODE;
	}
	// empty - check
	if ((*_pIdx) == 0) {
		printf("_pQueue is Empty!\n");
		return ERROR_CODE;
	}
	int GetData = *(_pQueue + 0);
	for (int i = 0; i < *_pIdx; i++)
	{
#ifdef DEBUG_MODE 
		printf("%d -> %d\n", i, i - 1);
		// DEBUG_MODE ���ǰ� �Ǿ������� ������ �� ���Խ�Ų��.
#endif

		* (_pQueue + i) = *(_pQueue + i + 1);
	}
	--(*_pIdx);
	return GetData;
}

void PrintAll(const int* const _pQueue, int _idx, int _queueSize)
{
	if (_pQueue == NULL) {
		printf("[%s][%d] : _pQueue is empty\n", __FILE__, __LINE__);
	}
	// empty-check
	if (_idx == 0) {
		printf("Queue is empty\n");
		return;
	}
	for (int i = 0; i < _idx; i++)
	{
		printf("%d - ", *(_pQueue + i));
	}
	printf("(%d / %d)\n\n", _idx, _queueSize);
}
