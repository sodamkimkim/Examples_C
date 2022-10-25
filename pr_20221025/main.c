#include <stdio.h>
#include <malloc.h>
#define SAFE_FREE(p) do{if(p){free(p);p=NULL;}}while(0);
#define ERROR_CODE 82828282;
 //#define DEBUG_MODE

/*
# Put
1. pQueue메모리 NULL여부 체크
2. queue full 여부 체크
3. queue의 idx 자리에 data넣기 -> pQueue필요. 변경되니까.
4. idx ++ -> pIdx 필요. 변경되니까.
*/
void Put(int* const _pQueue, int _queueSize, int* const _pIdx, int _data);

/*
# Get
1. pQueue메모리 NULL여부 체크
2. queue empty여부 체크
3. queue[0] 데이터 따로 저장
4. 나머지 데이터 한 칸씩 앞으로 당겨주기 ->pQueue필요. 변경하니까.
5. idx--해주기 -> pIdx필요. 변경하니까.
6. return GetData
*/
int Get(int* const _pQueue, int* const _pIdx);

/*
# PrintAll
queue 데이터 idx까지 다 출력해주는 함수.
1. pQueue메모리 NULL여부 체크
2. empty체크
3. for문 돌려서 값 출력
*/
void PrintAll(const int* const _pQueue, int _idx, int _queueSize);

int main()
{
	const int QUEUE_SIZE = 5;
	int* pQueue = (int*)malloc(sizeof(int) * QUEUE_SIZE);
	if (pQueue == NULL) return -1;
	int idx = 0; // queue 는 put해야 하는 곳  != get 해야 하는 곳 
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
		// DEBUG_MODE 정의가 되어있으면 컴파일 때 포함시킨다.
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
