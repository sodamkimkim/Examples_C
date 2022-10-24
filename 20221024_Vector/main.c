#include <stdio.h>
#include <malloc.h>

// ���� �� �� �޸� �����ؼ� Ȯ���� ������ ������ ���� ������ ��� �Ѵ�. 
// �װ��� ���ϰ� �ϱ� ���ؼ� ��ũ�η� �����.
// # ��ũ��(Macro)
// �� �Լ��� ������ define����� �� �ִ�.
// P�� ���̸� �����̴ϱ� ����ȵȴ�. NULL�� �ƴϸ� �ּҸ� �޾Ҵٴ� ���̴ϱ� ���ǹ� ����ȴ�.
#define SAFE_FREE(p)\
do {\
	if(p)\
	{\
		free(p);\
		p=	NULL;\
	} \
}while(0)\
//* \ -> '���� ���̴�'

// �Լ� ���, �Ű����� �����Ϳ��� �� �����ϰ� �ڵ��ϱ�(������ �Ͼ�� �����Ͱ���?)
// Initialization
void InitDataAtArray(int* const _pArr, int _len, int* const _pIdx);
void PrintArray(const int* const _pArr, int _len, int _idx);
void AddData(int** const _pArr, int* const _pLen, int* const _pIdx, int _data);
// # Ȯ�����ִ� �Լ�
// �迭 ���޹ް�, ���� ���� ������ ��� �Ѵ�. => ����������
// *_len
//1. ���� ���̱�
//2. �þ ���̸�ŭ �����Ҵ�.
// 3. ���� ������ ����
// 4. ���� ������ ����
// 5. �����Ϳ� ���ο� �迭 ����
void ExtendArray(int** _pArr, int* const _pLen);


int main() {
	// #�ڷᱸ��(Data Structure)
	// �ڷᱸ���� ��Ȳ�� ���� ������ ���� �����ؾ��Ѵ�.
	// # Vector
	// - realloc �Ⱦ��� �޸� ũ�⸦ �ٲ۴�.

	// ��) �迭 �Ȱ����� �����ؼ� Ȯ���ϴ� ����ε�, Ȯ���� �� �����迭 �����͸� �����ؾ��Ѵ�. ���� ���� ���־� �Ѵ�.
	// �� ������ �迭�� �������� �����ؾ� ���� �� �ִ�.(���� �迭�� ���ִ°� �Ұ��ϴϱ�)
	// �� �� �޸𸮰� ���ÿ� �� ���� �ʿ��ϴٴ� ���� ����. => �޸� ���� �ʿ�.
	// Ȯ���� �� ������ �迭�� ���̸� �����ؾ� �Ѵ�. �������·�.
	int len = 3;
	int idx = 0;
	int* pArr = (int*)malloc(sizeof(int) * len);
	//memset
	InitDataAtArray(pArr, len, &idx);
	AddData(&pArr, &len, &idx, 10);
	//ExtendArray(&pArr, &len);
	PrintArray(pArr, len, idx);

	// �޸� ����
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
	if (!_pArr || !(*_pArr)) return; // pArr�� ������ ���� �Ǿ return
	if (*_pIdx == *_pLen)
	{
		//Ȯ��
		ExtendArray(_pArr, _pLen);
	}
	*((*_pArr) + (*_pIdx)) = _data;
	++(*_pIdx);
}
void ExtendArray(int** _pArr, int* const _pLen)
{
	// 0. ���� ���� ������ �α�.
	int preLen = (*_pLen);
	// 1. ���� �ø���
	(*_pLen) <<= 1;
	// 2. �þ ���̸�ŭ �����Ҵ�.
	int* pNewArr = (int*)malloc(sizeof(int) * (*_pLen));
	if (!pNewArr) {
		(*_pLen) = preLen;
		return;
	}
	printf("Extend Success : %d -> %d\n", preLen, *_pLen);
	// 3. ���� ������ ����
	for (int i = 0; i < preLen; ++i)
		*(pNewArr + i) = *(*(_pArr)+i);
	// 4. ���� ������ ����
	SAFE_FREE((*_pArr));
	// 5. �����Ϳ� ���ο� �迭 ����
	(*_pArr) = pNewArr;
}