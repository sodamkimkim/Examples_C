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

	// # 배열의 이름은 배열의 첫 번째 요소의 주소와 같다.
	// ㄴ 얘는 그냥 포인터이다.
	int arr[] = { 1,2,3 };
	// # 배열의 포인터 ( : 배열포인터)
	// 포인터인데 배열처럼 값 접근 가능하다.
	int* pArr = arr;
	for (int i = 0; i < 3; ++i) {
		printf("pArr[%d]: %d\n", i,pArr[i]);
	}
	printf("\n");
	// # 메모리 주소 연산
	// 4byte씩(offset)건너뛴다. == 자료형의 크기
	printf("pArr + 0 : %p (%d)\n", pArr + 0, *(pArr + 0));
	printf("pArr + 1 : %p (%d)\n", pArr + 1, *(pArr + 1));
	printf("pArr + 2 : %p (%d)\n", pArr + 2, *(pArr + 2));
	// 아래와 같이 배열 이름을 포인터처럼 쓸 수 있다. 결국 배열 명 == 주소이기 때문이다.
	printf("pArr + 2 : %p (%d)\n", arr + 2, *(arr + 2));

	printf("\n");
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//////////////////////////////////////////////////////////
	printf("\n");

	// # 2차원 포인터
	double d = 3.14;
	double* pD = &d;
	double** ppD = &pD;
	printf("d: %lf (%p)\n", d, &d); // d의 값, d의 주소
	printf("pD: %p (%p)\n", pD, &pD); // pd의 값(==d의 주소), pd의 주소(==ppd의 값)
	printf("ppD: %p (%p)\n", ppD, &ppD); // ppd의 값(pd의 주소), ppd의 주소

	printf("\n");
	printf("*ppD: %p\n", *ppD); // (ppD의 값)이 가지는 (값)
	printf("**ppD: %lf\n", **ppD); // (ppD의 값)이 가지는 (값)이 가지는 (값)
	printf("ppD size: %d byte\n", sizeof(ppD));
	//////////////////////////////////////////////////////////
	printf("\n");
	int arr2D[][3] = {
		{11, 12, 13},
		{21, 22, 23}
	};
	// # 주소 연산 ) 배열 != 포인터 메모리 offset --> 값 다르다. (12byte vs 4byte)
	int* pArr2D = arr2D;
	int** ppArr2D = arr2D;

	// # arr2D의 주소연산은 12byte씩 건너뛴다.
	printf("arr2D : %p\n", arr2D); // {11, 12, 13}, {21, 22, 23}
	printf("arr2D +0 : %p\n", (arr2D +0)[0]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +0 : %p\n", (arr2D +0)[1]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +0 : %p\n", (arr2D +1)[0]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +0 : %p\n", (arr2D +1)[1]); // {11, 12, 13}   --> arr2D != arr2D+0
	printf("arr2D +1 : %p\n", arr2D +1); // {21, 22, 23}
	printf("*(arr2D)[0] : %d\n", *(arr2D)[0]); // 11
	//printf("*(arr2D)[0][1] : %d\n", *(arr2D)[0][1]); // 안된다.
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
	printf("*(arr2D +1)[1] : %d\n", *(arr2D +1)[1]);  // 쓰레기값
	printf("arr2D[0] : %p\n", arr2D[0]); // {11, 12, 13}
	printf("arr2D[1] : %p\n", arr2D[1]); // {21, 22, 23}

	printf("arr2D + 1 : %p\n", arr2D + 1); // {21, 22, 23}
	printf("\n");
	// 포인터는 자료형인 4byte offset을 가진다.
	printf("pArr2D : %d\n", pArr2D[0]);
	printf("pArr2D+0 : %p\n", pArr2D+0);
	printf("pArr2D+1 : %p\n", pArr2D + 1);
	printf("*pArr2D : %d\n", *pArr2D); // 11
	printf("*pArr2D+0 : %d\n", *pArr2D+0); //11
	printf("*pArr2D+1 : %d\n", *pArr2D+1); //12
	printf("*pArr2D+2 : %d\n", *pArr2D+2); //13

	////////////////////////////////////////////////////////////////////////////////
	// # 1차원 포인터 배열 ( != 배열 포인터)
	// int*가 두개
	// 참고로 배열 포인터는 '배열을 가리키는 하나의 포인터'
	int* pArr1D[2] = { &arr2D[0][0], &arr2D[1][0] }; // 주소 값 두개 할당. 이중배열 row1, row2
	ppArr2D = &pArr1D; // 2차원 포인터에 1차원 포인터배열(포인터 두개)넣음

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