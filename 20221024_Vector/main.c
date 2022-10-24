#include <stdio.h>
#include <malloc.h>

// 벡터 쓸 때 메모리 복사해서 확장할 때마다 기존의 것을 해제해 줘야 한다. 
// 그것을 편리하게 하기 위해서 매크로로 만든다.
// # 매크로(Macro)
// ㄴ 함수를 가지고 define사용할 수 있다.
// P가 널이면 거짓이니까 수행안된다. NULL이 아니면 주소를 받았다는 것이니까 조건문 실행된다.
#define SAFE_FREE(p)\
do {\
	if(p)\
	{\
		free(p);\
		p=	NULL;\
	} \
}while(0)\
//* \ -> '같은 줄이다'

// 함수 기능, 매개변수 포인터여부 등 설계하고 코딩하기(변경이 일어나면 포인터겠지?)
// Initialization
void InitDataAtArray(int* const _pArr, int _len, int* const _pIdx);
void PrintArray(const int* const _pArr, int _len, int _idx);
void AddData(int** const _pArr, int* const _pLen, int* const _pIdx, int _data);
// # 확장해주는 함수
// 배열 전달받고, 원래 것을 지워도 줘야 한다. => 이중포인터
// *_len
//1. 길이 늘이기
//2. 늘어난 길이만큼 동적할당.
// 3. 기존 데이터 복사
// 4. 기존 데이터 해제
// 5. 포인터에 새로운 배열 연결
void ExtendArray(int** _pArr, int* const _pLen);


int main() {
	// #자료구조(Data Structure)
	// 자료구조는 상황에 따라 최적의 것을 선택해야한다.
	// # Vector
	// - realloc 안쓰고 메모리 크기를 바꾼다.

	// 단) 배열 똑같은걸 생성해서 확장하는 방식인데, 확장할 때 기존배열 데이터를 복사해야한다. 원래 것을 없애야 한다.
	// ㄴ 기존의 배열을 동적으로 생성해야 없앨 수 있다.(정적 배열은 없애는거 불가하니까)
	// 이 때 메모리가 동시에 두 군데 필요하다는 것이 단점. => 메모리 많이 필요.
	// 확장이 될 때마다 배열의 길이를 관리해야 한다. 변수형태로.
	int len = 3;
	int idx = 0;
	int* pArr = (int*)malloc(sizeof(int) * len);
	//memset
	InitDataAtArray(pArr, len, &idx);
	AddData(&pArr, &len, &idx, 10);
	//ExtendArray(&pArr, &len);
	PrintArray(pArr, len, idx);

	// 메모리 해제
	SAFE_FREE(pArr);
	return 0;
}

void InitDataAtArray(int* const _pArr, int _len, int* const _pIdx)
{
	if (_pArr == NULL) return;
	for (int i = 0; i < _len; ++i)
	{
		*(_pArr + i) = i + 1;
		++(*_pIdx);
		//(*_pIdx) = _len;
	}
}
void PrintArray(const int* const _pArr, int _len, int _idx)
{
	if (_pArr == NULL) return;
	for (int i = 0; i < _idx; ++i)
	{
		printf("%d - ", *(_pArr + i));
	}
	printf("(%d / %d)\n", _idx, _len);

}
void AddData(int** const _pArr, int* const _pLen, int* const _pIdx, int _data)
{
	if (!_pArr || !(*_pArr)) return; // pArr가 없으면 참이 되어서 return
	if (*_pIdx == *_pLen)
	{
		//확장
		ExtendArray(_pArr, _pLen);
	}
	*((*_pArr) + (*_pIdx)) = _data;
	++(*_pIdx);
}
void ExtendArray(int** _pArr, int* const _pLen)
{
	// 0. 이전 길이 저장해 두기.
	int preLen = (*_pLen);
	// 1. 길이 늘리기
	(*_pLen) <<= 1;
	// 2. 늘어난 길이만큼 동적할당.
	int* pNewArr = (int*)malloc(sizeof(int) * (*_pLen));
	if (!pNewArr) {
		(*_pLen) = preLen;
		return;
	}
	printf("Extend Success : %d -> %d\n", preLen, *_pLen);
	// 3. 기존 데이터 복사
	for (int i = 0; i < preLen; ++i)
		*(pNewArr + i) = *(*(_pArr)+i);
	// 4. 기존 데이터 해제
	SAFE_FREE((*_pArr));
	// 5. 포인터에 새로운 배열 연결
	(*_pArr) = pNewArr;
}