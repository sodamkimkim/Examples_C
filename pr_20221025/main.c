#include <stdio.h>
#include <malloc.h>
#define QUEUE_SIZE 5
#define SAFE_FREE(p)\
do{\
	if (p)\
	{\
		free(p);\
		p = NULL;\
	}\
} while (0);\

// # Put
// queue에 값 넣는 함수
// pQueue, queueSize (full check), pIdx(인덱스 변경시킬거니까 주소받음), data 
void Put(int* const _pQueue, const int const _queueSize, int* _pIdx, int _data);

// # Get
// queue에서 값 빼는 함수
// 인덱스 [0]에서 뺴고 하나씩 데이터 땡겨줘야 한다.
// pQueue, pIdx(인덱스 변경시킬 거니까)
int Get(int* const _pQueue, int* const _pIdx);

// # PrintAll
// 값 다뽑는 함수
// pQueue, idx
// queuesize는 필요 없는데 그냥 넣음
void PrintAll(const int* const _pQueue, int _idx, int _queueSize);
int main() {
	int queueSize = QUEUE_SIZE;
	int idx = 0;
	int* pQueue = (int*)malloc(sizeof(int) * queueSize);
	if (pQueue == NULL) return -1;

	for (int i = 0; i < queueSize + 2; i++)
	{
		Put(pQueue, queueSize, &idx, i + 1);
	}
	PrintAll(pQueue, idx, queueSize);
	return 0;
}

void Put(int* const _pQueue, const int const _queueSize, int* _pIdx, int _data)
{
	if (!_pQueue) return;
	if (*(_pIdx) == _queueSize)
	{
		printf("queue is full\n"); 
		return;
	}
	*(_pQueue + *_pIdx) = _data;
	++(*_pIdx);
}

int Get(int)

void PrintAll(const int* const _pQueue, int _idx, int _queueSize)
{
	if (!_pQueue)return;
	if (_idx == 0) { printf("queue is empty"); return; }
	for (int i = 0; i < _idx; i++)
	{
		printf("%d - ", *(_pQueue + i));
	}
	printf("(%d / %d)", _idx, _queueSize);
}
