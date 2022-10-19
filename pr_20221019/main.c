#include <stdio.h>


void PrintArray(int* _pArr, int _len);
void PrintArray2D(int** _ppArr, int _rowCnt, int _colCnt);
int main() {
	int var = 10;
	int* pVar = &var;
	printf("pVal(%p) == &var(%p)\n", pVar, &var);
	*pVar = 20;
	printf("*pVar(%d), var(%d)\n", *pVar, var);
	printf("pVar Address : %p\n", &pVar);
	printf("*(&pVar): %p\n", *(&pVar));

	printf("\n");

	// # �迭�� �̸��� �迭�� ù ��° ����� �ּҿ� ����.
	// �� ��� �׳� �������̴�.
	int arr[] = { 1,2,3 };
	// # �迭�� ������ ( : �迭������)
	// �������ε� �迭ó�� �� ���� �����ϴ�.
	int* pArr = arr;
	for (int i = 0; i < 3; ++i) {
		printf("pArr[%d]: %d\n", i,pArr[i]);
	}
	printf("\n");
	// # �޸� �ּ� ����
	// 4byte��(offset)�ǳʶڴ�. == �ڷ����� ũ��
	printf("pArr + 0 : %p (%d)\n", pArr + 0, *(pArr + 0));
	printf("pArr + 1 : %p (%d)\n", pArr + 1, *(pArr + 1));
	printf("pArr + 2 : %p (%d)\n", pArr + 2, *(pArr + 2));
	// �Ʒ��� ���� �迭 �̸��� ������ó�� �� �� �ִ�. �ᱹ �迭 �� == �ּ��̱� �����̴�.
	printf("pArr + 2 : %p (%d)\n", arr + 2, *(arr + 2));

	printf("\n");
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//////////////////////////////////////////////////////////
	printf("\n");

	// # 2���� ������
	double d = 3.14;
	double* pD = &d;
	double** ppD = &pD;
	printf("d: %lf (%p)\n", d, &d); // d�� ��, d�� �ּ�
	printf("pD: %p (%p)\n", pD, &pD); // pd�� ��(==d�� �ּ�), pd�� �ּ�(==ppd�� ��)
	printf("ppD: %p (%p)\n", ppD, &ppD); // ppd�� ��(pd�� �ּ�), ppd�� �ּ�

	printf("\n");
	printf("*ppD: %p\n", *ppD); // (ppD�� ��)�� ������ (��)
	printf("**ppD: %lf\n", **ppD); // (ppD�� ��)�� ������ (��)�� ������ (��)
	printf("ppD size: %d byte\n", sizeof(ppD));
	//////////////////////////////////////////////////////////
	printf("\n");
	int arr2D[][3] = {
		{11, 12, 13},
		{21, 22, 23}
	};
	// # �ּ� ���� ) �迭 != ������ �޸� offset --> �� �ٸ���. (12byte vs 4byte)
	int* pArr2D = arr2D;
	int** ppArr2D = arr2D;

	// # arr2D�� �ּҿ����� 12byte�� �ǳʶڴ�.
	printf("arr2D : %p\n", arr2D); // {11, 12, 13}, {21, 22, 23}
	printf("arr2D +0 : %p\n", (arr2D +0)[0]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +0 : %p\n", (arr2D +0)[1]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +0 : %p\n", (arr2D +1)[0]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +0 : %p\n", (arr2D +1)[1]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +1 : %p\n", arr2D +1); // {21, 22, 23}
	printf("*(arr2D)[0] : %d\n", *(arr2D)[0]); // 11
	//printf("*(arr2D)[0][1] : %d\n", *(arr2D)[0][1]); // �ȵȴ�.
	printf("*(arr2D)[1] : %d\n", *(arr2D)[1]); // 21
	printf("*(arr2D)[0][0] : %d\n", arr2D[0][0]); // 11
	printf("*(arr2D)[0][1] : %d\n", arr2D[0][1]); // 12
	printf("*(arr2D)[1][0] : %d\n", arr2D[1][0]); // 21
	printf("*(arr2D)[1][1] : %d\n", arr2D[1][1]); // 22


	printf("\n");
	printf("*(arr2D) : %p\n", *(arr2D));
	printf("*(arr2D)[0] : %d\n", *(arr2D)[0]);
	printf("*(arr2D)[1] : %d\n", *(arr2D)[1]);
	printf("**(arr2D) : %d\n", **(arr2D));


	printf("*(arr2D +0)[0] : %d\n", *(arr2D +0)[0]); // 11
	printf("*(arr2D +0)[1] : %d\n", *(arr2D +0)[1]); // 21
	printf("*(arr2D +1)[0] : %d\n", *(arr2D +1)[0]); // 21
	printf("*(arr2D +1)[1] : %d\n", *(arr2D +1)[1]);  // �����Ⱚ
	printf("arr2D[0] : %p\n", arr2D[0]); // {11, 12, 13}
	printf("arr2D[1] : %p\n", arr2D[1]); // {21, 22, 23}

	printf("arr2D + 1 : %p\n", arr2D + 1); // {21, 22, 23}
	printf("\n");
	// �����ʹ� �ڷ����� 4byte offset�� ������.
	printf("pArr2D : %d\n", pArr2D[0]);
	printf("pArr2D+0 : %p\n", pArr2D+0);
	printf("pArr2D+1 : %p\n", pArr2D + 1);
	printf("*pArr2D : %d\n", *pArr2D); // 11
	printf("*pArr2D+0 : %d\n", *pArr2D+0); //11
	printf("*pArr2D+1 : %d\n", *pArr2D+1); //12
	printf("*pArr2D+2 : %d\n", *pArr2D+2); //13

	////////////////////////////////////////////////////////////////////////////////
	// # 1���� ������ �迭 ( != �迭 ������)
	// int*�� �ΰ�
	// ����� �迭 �����ʹ� '�迭�� ����Ű�� �ϳ��� ������'
	int* pArr1D[2] = { &arr2D[0][0], &arr2D[1][0] }; // �ּ� �� �ΰ� �Ҵ�. ���߹迭 row1, row2
	ppArr2D = &pArr1D; // 2���� �����Ϳ� 1���� �����͹迭(������ �ΰ�)����

	printf("arr2D[1][1] : %d\n", arr2D[1][1]);
	printf("*(*ppArr2D + 1) + 1 :  %d\n",*(*ppArr2D + 1) + 1); // 13
	printf("*(*(ppArr2D + 1) + 1) :  %d\n",*(*(ppArr2D + 1) + 1)); // 22
	PrintArray2D(ppArr2D, 2, 3);
}
void PrintArray(int* _pArr, int _len)
{
	printf(" -- PrintArray -- \n");
	for (int i = 0; i < _len; ++i)
		printf("*(_pArr + %d) : %d\n", i, *(_pArr + i));
}
void PrintArray2D(int** _ppArr, int _rowCnt, int _colCnt) {
	printf("== PrintArray2D ==\n");
	for (int row = 0; row < _rowCnt; ++row) { // 0, 1
		for (int col = 0; col < _colCnt; ++col) {// 0, 1, 2
			printf("*(*(_ppArr + %d) + %d : %d\n", row, col, *(*(_ppArr + row) + col));
			/*
			*    *(*(_ppArr + 0) + 0) // 11
			*    *(*(_ppArr + 0) + 1) // 12
			*    *(*(_ppArr + 0) + 2) // 13
			* 
			*    *(*(_ppArr + 1) + 0) // 21
			*    *(*(_ppArr + 1) + 1) // 22
			*    *(*(_ppArr + 1) + 2) // 23
			*/
		}
	}
}