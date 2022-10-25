#include <stdio.h>
#include <malloc.h>
#define SAFE_FREE(p) do{if(p){free(p);p=NULL;}}while(0)
#define DEBUG_MODE

void Put(int* const _pQueue, int _queueSize, int* const _pIdx, int _data);
int Get(int* const _pQueue, int* const _pIdx);

void PrintAll(const int* const _pQueue, int _idx, int _queueSize);
int main() {
	const int QUEUE_SIZE = 5;
	int* pQueue = (int*)malloc(sizeof(int) * QUEUE_SIZE);
	if (pQueue == NULL) return -1;
	int idx = 0; // Put해야 하는 곳 (!= Get하는 곳)

	PrintAll(pQueue, idx, QUEUE_SIZE);
	printf("Get: %d\n", Get(pQueue, &idx));
	for (int i = 0; i < 7; ++i) {
		Put(pQueue, QUEUE_SIZE, &idx, i + 1);
	}
	printf("Get: %d\n", Get(pQueue, &idx));
	printf("Get: %d\n", Get(pQueue, &idx));
	PrintAll(pQueue, idx, QUEUE_SIZE);

	printf("Get: %d\n", Get(pQueue, &idx));
	printf("Get: %d\n", Get(pQueue, &idx));
	printf("Get: %d\n", Get(pQueue, &idx));
	printf("Get: %d\n", Get(pQueue, &idx));
	PrintAll(pQueue, idx, QUEUE_SIZE);

	SAFE_FREE(pQueue);
	return 0;
}

void Put(int* const _pQueue, int _queueSize, int* const _pIdx, int _data) {
	// check-empty
	if (_pQueue == NULL)
	{
		// 에러코드 띄우기
		printf("[%s][%d]: _pQueue is NULL\n", __FILE__, __LINE__);
		return;
	}
	// check-full
	if (*(_pIdx) == _queueSize)
	{
		printf("Queue Overflow!\n");
		return;
	}
	*(_pQueue + ((*_pIdx)++)) = _data;
}
int Get(int* const _pQueue, int* const _pIdx)
{
	if (_pQueue == NULL)
	{
		printf("[%s][%d] : _pQueue is NULL\n", __FILE__, __LINE__);
		return -12345;
	}
	if ((*_pIdx) == 0) {
		printf("_pQueue is Empty!\n");
		return -67890;
	}
	// 1. 0번째 데이터 빼내기
	int returnData = *(_pQueue + 0);
	// 2. 나머지 데이터 앞 쭉 밀기
	for (int i = 0; i < *_pIdx; i++)
	{
#ifdef DEBUG_MODE 
		printf("%d -> %d\n", i, i - 1);
		// DEBUG_MODE 정의가 되어있으면 컴파일 때 포함시킨다.
#endif
		*(_pQueue + i) = *(_pQueue + i + 1);
	}
	// 3. 인덱스 -1
	--(*_pIdx);
	// 4. 빼낸 데이터 반환
	return returnData;
}
void PrintAll(const int* const _pQueue, int _idx, int _queueSize)
{
	// check-empty
	if (_pQueue == NULL) {
		printf("[%s] [%d] : _pQueue is empty!\n", __FILE__, __LINE__);
	}
	if (_idx == 0) {
		printf("Queue is empty!\n");
		return;
	}

	for (int i = 0; i < _idx; i++)
	{
		printf("%d - ", *(_pQueue + i));
	}
	printf("(%d / %d)\n\n", _idx, _queueSize);
}