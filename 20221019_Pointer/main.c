#include <stdio.h>

typedef struct SInfo {
	int i;
	float f;
	double d;
}SInfo;
void PrintArray(int* _pArr, int _len);

// �����Ͱ� �迭�� �ٸ��� ���� ������ col�� ���� ������ ����. �ǳʶ� ������ ����.
//void PrintArray2D(int _arr[][3], int _rowCnt, int _colCnt);
void PrintArray2D(int** _ppArr, int _rowCnt, int _colCnt);


int main() {
	int var = 10;
	int* pVar = &var;
	printf("pVar(%p) == &var(%p)\n", pVar, &var);
	*pVar = 20;
	printf("*pVar(%d), var(%d)\n", *pVar, var);
	printf("&pVar Address: %p\n", &pVar);
	printf("*(&pVar): %p\n", *(&pVar));

	printf("char* size: %dbyte\n", sizeof(char*));
	printf("float* size: %dbyte\n", sizeof(float*));
	printf("long long* size: %dbyte\n", sizeof(long long*));

	// # �����Ϳ� �������� �����ϱ� ��������. �ּҸ� �־����.
	//float* pF = var;
	//printf("pF: %f / %d (%p)\n", *pF, (int)*pF, pF);

	// # �����Ϳ� �ּҸ� �־��� ������ ������ �ȳ���.
	//������ �������� ������ �ִ�.
	// �����Ͱ� ����Ű�� ���� �ڷ����� �ٸ��� �����̴�. (float != int)
	// �ڷ����� �´� �����͸� �������.
	float* pF = pVar;
	printf("pF: %f / %d (%p)\n", *pF, (int)*pF, pF);

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// # �迭�� �̸��� �迭�� ù��° ����� �ּҿ� ����. -> ��� �׳� �����ʹ�.
	// �迭�� �Լ��� ���� ��, �ּ���ũ���� 4byte�� ����ȴ�. 
	// �󸶳� ū �迭�̵� �ּҸ� ����. -> �׷��� size�� ���� �������.
	int arr[] = { 1,2,3 };
	int* pArr = arr; // �迭�� ������ ( �迭������)
	for (int i = 0; i < 3; ++i) {
		printf("pArr[%d]: %d\n", i, pArr[i]);
	}
	// # �޸� �ּ� ����
	// 4byte��(offset) �ǳʶڴ�. == �ڷ����� ũ��
	printf("pArr + 0 : %p (%d)\n", pArr + 0, *(pArr + 0));
	printf("pArr + 1 : %p (%d)\n", pArr + 1, *(pArr + 1));
	printf("pArr + 2 : %p (%d)\n", pArr + 2, *(pArr + 2));
	// �̷��� �迭 �̸��� ������ ó�� �� �� �ִ�. �ᱹ �ּ��̱� �����̴�. ��
	// printf("pArr + 2 : %p (%d)\n", arr + 2, *(arr + 2)); 

	printf("\n");

	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// # 2���� ������
	double d = 3.14;
	double* pD = &d; // ���� ���� ���� �ּ� ����
	double** ppD = &pD; // ���� ���� ���� �ּ��� �ּҸ� ����
	printf("d: %lf (%p)\n", d, &d);
	printf("pD: %p (%p)\n", pD, &pD);
	printf("ppD: %p (%p)\n", ppD, &ppD);
	printf("*ppD: %p\n", *ppD);
	printf("**ppD: %lf\n", **ppD);
	printf("ppD Size: %d byte\n", sizeof(ppD));

	/// ////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	int arr2D[][3] = {
		{11, 12, 13},
		{21, 22, 23}
	};
	// �ּҿ��� �迭 ! = ������ �޸� offset ���� �ٸ��� (12byte vs 4byte)
	int* pArr2D = arr2D;
	int** ppArr2D = arr2D;
	printf("arr2D : %p\n", arr2D);
	printf("arr2D+1 : %p\n", arr2D + 1); // 12byte�ǳʶ�
	printf("pArr2D : %p\n", pArr2D);
	printf("pArr2D+1 : %p\n", pArr2D + 1); // 4byte�ǳʶ�
	printf("ppArr2D: %p\n", ppArr2D);
	printf("ppArr2D+1 : %p\n", ppArr2D + 1); // 4byte�ǳʶ�
	printf("*ppArr2D + 0 : %p\n", *ppArr2D + 0);
	printf("*ppArr2D + 1 : %p\n", *ppArr2D + 1);

	printf("\n");
	//printf("pArr2D[1][1] : %d (%p)\n", pArr2D[1][1], &pArr2D[1][1]); -> 1������ 2�������� ������ �ƿ� �Ұ����ϴ�.
	printf("pArr2D[1][1] : %d (%p)\n", pArr2D[1], &pArr2D[1]);

	// ������ �����ͷ� [][] ������ ���������� ��������.
	//printf("ppArr2D[1][1] : %d (%p)\n", ppArr2D[1][1], &ppArr2D[1][1]);

	printf("\n");
	for (int row = 0; row < 2; ++row)
		for (int col = 0; col < 3; ++col)
			printf("arr2D[%d][%d] : %d (%p)\n",
				row, col,
				arr2D[row][col],
				&arr2D[row][col]);

	// # 1���� ������ �迭
	// �迭 �����Ϳ� ������ �迭�� ����? 
	int* pArr1D[2] = { // int* �� �ΰ�. ������ �迭.
		&arr2D[0][0], &arr2D[1][0]
	};
	ppArr2D = &pArr1D;
	PrintArray2D(ppArr2D, 2, 3); // **********

	/// ////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	SInfo info = {1, 1.5f, 2.6};
	SInfo* pInfo = &info;
	printf("SInfo Size: %d byte\n", sizeof(SInfo));
	printf("SInfo* Size: %d byte\n", sizeof(SInfo*));

	info.i = 100;
	// ������ ��� ���� ������
	pInfo->f = 123.4f;
	printf("pInfo->f: %f\n", pInfo->f);

	/// ////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	// ���ڿ��� �ᱹ ������ �迭�̱� ������ �����ͷ� �����ϱ⵵ �Ѵ�.
	//char* str = "Hello, World"; // ����� ��������� �� �ּҸ� str�� ���� ������ ������ ���������� �� ������ �Ұ����� ��.
	//*(str + 1) = 'E'; // �� ����ȵȴ�.
	// ���ڿ� ������ ���ڿ� ����� �ִµ�, �迭�������� ����� ����, ������ �������� ����� ���ڿ� ����� ����� ���� ��.
	char strArr[] = "Hello, World!"; // ���ڿ��� �迭 ���� -> �������·� ���� => �� ���� ����
	char* str = strArr;
	*(str + 1) = 'E'; // �� ����ȴ�.
		printf("*(str + 1): %c\n", *(str + 1));

	return 0;

}

// void PrintArray(int _arr[], int _len)�� ���� ���̴�.
void PrintArray(int* _pArr, int _len)
{
	printf(" -- PrintArray --\n");
	for (int i = 0; i < _len; ++i)
		printf("*(_pArr + %d) : %d\n", i, *(_pArr + i));
}
void PrintArray2D(int** _ppArr, int _rowCnt, int _colCnt) {
	printf("== PrintArray2D ==\n");
	for (int row = 0; row < _rowCnt; ++row)
	{
		for (int col = 0; col < _colCnt; ++col) {
			printf("*(*(_ppArr + %d) + %d: %d\n",
				row, col, *(*(_ppArr + row) + col));
		}
	}
}