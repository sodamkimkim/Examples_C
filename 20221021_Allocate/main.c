#include <stdlib.h>
#include <stdio.h>
void ChangeValue(int* _pVal);
void Swap(int* _pLhs, int* _pRhs);
char* StringConstant2Variables(const char* _str);
int main() {

	// # �޸� ���� �Ҵ�(Memory Dynamic Allocate)
	int* pVar = NULL;
	//printf("Before pVar : %d (%p)\n",*pVar, pVar);
	pVar = (int*)malloc(sizeof(int));
	if (pVar != NULL)
	{
		*pVar = 10;
		printf("pVar : %d (%p)\n", *pVar, pVar);
	}

	// # �޸� ����(Memory leak)
	if (pVar != NULL) {
		free(pVar);
		pVar = NULL; // �ּҵ� �ʱ�ȭ . �����ص� ���� ����. free(pVar)�ϰ� �ּҵ� NULL���ֱ�
	}
	//free(pVar);

	/// ///////////////////////////////////////////
	printf("\n");
	// # ���� �迭
	int arr[5];
	int len = 5;
	// # ���� �迭(Dynamic Array)
	int* pArr = (int*)malloc(sizeof(int) * len);
	pArr[0] = 100;
	*(pArr + 1) = 200;
	printf("pArr[0]: %d (%p)\n", pArr[0], &pArr[0]);
	printf("*(pArr + 1) : %d (%p)\n", *(pArr + 1), pArr + 1);
	printf("pArr Size: %d byte\n", sizeof(pArr)); // �����Ͷ� 4byte. ���� �迭�� �� �迭�� ũ�Ⱑ ���´�.

	//*(pArr + 10) = 100;
	//printf("*(pArr + 10) : %d (%p)\n", *(pArr + 10), pArr + 10);

	if (pArr != NULL) {
		free(pArr);
		pArr = NULL;
	}
	///////////////////////////////////////////////////////////////////////////////
	printf("\n");
	// # ������ �����迭
	int** ppArr2D = (int**)malloc(sizeof(int*) * 2); // int������ �ΰ� �������� -> 2���� ������ �ּ� ��ȯ
	ppArr2D[0] = (int*)malloc(sizeof(int) * 3);
	*(ppArr2D + 1) = (int*)malloc(sizeof(int) * 3);
	// �� �̷��� 3��¥�� �ΰ� ���ε����ϸ� �ּ� ����ȵȴ�. malloc�ѹ��� �ؾ� ���ӵ�.
	// ���� �Ϲ����� ���� ������ �迭ó�� ���ӵ� �ּҸ� ���� �ʹٸ� 6��¥�� �����ϰ� �ּҸ� �����Ҵ��ϴ� ����� ����ؾ� �Ѵ�.

	// �� ���� malloc�Ҵ� �����ؼ� *(ppArr2D + 1) =  null; �� ���� ��, �տ��� �Ҵ��� �͵鵵 free���ְ� ������ �Ѵ�. �׷��� �޸� ���� �߻����Ѵ�.
	// �� : stack �ǰ���

	ppArr2D[0][0] = 11;
	*(*(ppArr2D + 1) + 0) = 21;
	printf("ppArr2D[0][0] : %d (%p) \n", ppArr2D[0][0], &ppArr2D[0][0]);
	printf("*(*(ppArr2D+1)+0): %d (%p)\n", *(*(ppArr2D + 1) + 0), &(*(*(ppArr2D + 1) + 0)));

	// # ������ ������ ����.
	// malloc 3�� ������ 3�� �� ���� �� ��� �Ѵ�. 
	for (int i = 0; i < 2; ++i) {
		if (ppArr2D[i] != NULL) {
			free(ppArr2D[i]);
			ppArr2D[i] = NULL;
		}
	}
	if (ppArr2D != NULL) {
		free(ppArr2D);
		ppArr2D = NULL;
	}
	///////////////////////////////////////////////////////////////////////////////
	printf("\n");
	int var = 0;
	ChangeValue(&var); // ������ �ּҸ� ����. �Լ� ������ �ּҸ� ã�ư��� ���� �ٲٴϱ� ���� �ٲ�.
	printf("var : %d\n", var);

	int lhs = 3, rhs = 5;
	Swap(&lhs, &rhs);
	printf("lhs: %d, rhs: %d\n", lhs, rhs);

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");
	char* str = StringConstant2Variables("Hello");
	str[3] = 'L';
	printf("str: %s\n", str);

	// ������ �Լ����� ������, (buff) ����ŭ ���� main���� �ش� �ּ� ����(buff�� ���������� str�� ���� �ּҰ��� ������ �ִ�.)
	if (str != NULL) {
		free(str);
	}

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// # const
	//  pointer�� const �� ���� �� �ִ� ���� �� ��
	// �ּ� or ��
	double* pDouble = NULL;
	//const double* const pDouble = NULL;  // �Ѵ� ���ٲ�
	//const double* pDouble = NULL;  // �� ���ٲ�
	//double* const pDouble = NULL;  // �ּ� ���ٲ�
	pDouble = malloc(8);
	*pDouble = 3.14;
	if (pDouble != NULL)
	{
		free(pDouble);
		pDouble = NULL;
	}


	return 0;
}
// # call - by - value (: �Ű������� ��)
// # call - by - reference (: �Ű������� �ּ�) - �ּҸ� ������ �ּҸ� �����ؼ� ���� ����
void ChangeValue(int* _pVal)
{
	*_pVal = 123456789;

}

void Swap(int* const _pLhs, int* const _pRhs) { // �ּҸ� ���ٲٵ��� �Ѵ�.

	// const�� ���ؼ� ���� ������ �ٲ� �� �ִ��� �����ܿ��� Ȯ���� ����ؾ��Ѵ�.
	//_pRhs = 0x88; -> �̷��� �ּ� �ٲ������ �ȵ��ݾ�.
	// �����Ͱ� ������ const�� ������@!@


	int tmp = *_pRhs;
	*_pRhs = *_pLhs;
	*_pLhs = tmp;
}

char* StringConstant2Variables(const char* const _str)
{
	// 1. ���ڿ� ���� ���ϱ�
	// 2. ���� �غ�(���� �Ҵ�)
	// 3. ���ڿ� ����
	// 4. �Ϸ�� ���� ��ȯ
	int cnt = 0;
	while (*(_str+cnt) != '\0') {
		cnt++;
		printf("%d\n", cnt);
	}
	//char* buff = (char*)malloc(sizeof(_str));
	char* buff = (char*)malloc(sizeof(char)* (cnt+1));

	if (buff == NULL) {
		printf("buff == NULL");
		return NULL;
	}
	for (int i = 0; i< cnt; i++) {
		*(buff + i) = *(_str + i);
		printf("%c", *(buff + i));
	}
	printf("\n");
	*(buff + cnt) = '\0';
	return buff;

}
