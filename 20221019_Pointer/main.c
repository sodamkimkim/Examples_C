#include <stdio.h>

typedef struct SInfo {
	int i;
	float f;
	double d;
}SInfo;
void PrintArray(int* _pArr, int _len);

// 포인터가 배열과 다르게 없는 정보는 col에 대한 정보가 없다. 건너뛸 정보가 없다.
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

	// # 포인터에 변수값을 넣으니까 에러난다. 주소를 넣어야지.
	//float* pF = var;
	//printf("pF: %f / %d (%p)\n", *pF, (int)*pF, pF);

	// # 포인터에 주소를 넣었기 때문에 에러는 안난다.
	//하지만 실행결과에 문제가 있다.
	// 포인터가 가리키는 값의 자료형이 다르기 때문이다. (float != int)
	// 자료형에 맞는 포인터를 사용하자.
	float* pF = pVar;
	printf("pF: %f / %d (%p)\n", *pF, (int)*pF, pF);

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// # 배열의 이름은 배열의 첫번째 요소의 주소와 같다. -> 얘는 그냥 포인터다.
	// 배열을 함수로 던질 때, 주소의크기인 4byte만 복사된다. 
	// 얼마나 큰 배열이든 주소만 전달. -> 그래서 size도 같이 던져줬다.
	int arr[] = { 1,2,3 };
	int* pArr = arr; // 배열의 포인터 ( 배열포인터)
	for (int i = 0; i < 3; ++i) {
		printf("pArr[%d]: %d\n", i, pArr[i]);
	}
	// # 메모리 주소 연산
	// 4byte씩(offset) 건너뛴다. == 자료형의 크기
	printf("pArr + 0 : %p (%d)\n", pArr + 0, *(pArr + 0));
	printf("pArr + 1 : %p (%d)\n", pArr + 1, *(pArr + 1));
	printf("pArr + 2 : %p (%d)\n", pArr + 2, *(pArr + 2));
	// 이렇게 배열 이름을 포인터 처럼 쓸 수 있다. 결국 주소이기 때문이다. ㄱ
	// printf("pArr + 2 : %p (%d)\n", arr + 2, *(arr + 2)); 

	printf("\n");

	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// # 2차원 포인터
	double d = 3.14;
	double* pD = &d; // 실제 변수 값의 주소 저장
	double** ppD = &pD; // 실제 변수 값의 주소의 주소를 저장
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
	// 주소연산 배열 ! = 포인터 메모리 offset 값이 다르다 (12byte vs 4byte)
	int* pArr2D = arr2D;
	int** ppArr2D = arr2D;
	printf("arr2D : %p\n", arr2D);
	printf("arr2D+1 : %p\n", arr2D + 1); // 12byte건너뜀
	printf("pArr2D : %p\n", pArr2D);
	printf("pArr2D+1 : %p\n", pArr2D + 1); // 4byte건너뜀
	printf("ppArr2D: %p\n", ppArr2D);
	printf("ppArr2D+1 : %p\n", ppArr2D + 1); // 4byte건너뜀
	printf("*ppArr2D + 0 : %p\n", *ppArr2D + 0);
	printf("*ppArr2D + 1 : %p\n", *ppArr2D + 1);

	printf("\n");
	//printf("pArr2D[1][1] : %d (%p)\n", pArr2D[1][1], &pArr2D[1][1]); -> 1차원은 2차원으로 접근이 아예 불가능하다.
	printf("pArr2D[1][1] : %d (%p)\n", pArr2D[1], &pArr2D[1]);

	// 이차원 포인터로 [][] 접근은 가능하지만 에러난다.
	//printf("ppArr2D[1][1] : %d (%p)\n", ppArr2D[1][1], &ppArr2D[1][1]);

	printf("\n");
	for (int row = 0; row < 2; ++row)
		for (int col = 0; col < 3; ++col)
			printf("arr2D[%d][%d] : %d (%p)\n",
				row, col,
				arr2D[row][col],
				&arr2D[row][col]);

	// # 1차원 포인터 배열
	// 배열 포인터와 포인터 배열의 차이? 
	int* pArr1D[2] = { // int* 가 두개. 포인터 배열.
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
	// 포인터 멤버 접근 연산자
	pInfo->f = 123.4f;
	printf("pInfo->f: %f\n", pInfo->f);

	/// ////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	// 문자열은 결국 문자형 배열이기 때문에 포인터로 선언하기도 한다.
	//char* str = "Hello, World"; // 상수로 만들어지고 그 주소만 str에 들어가기 때문에 접근은 가능하지만 값 변경은 불가능한 것.
	//*(str + 1) = 'E'; // 값 변경안된다.
	// 문자열 변수와 문자열 상수가 있는데, 배열형식으로 만들면 변수, 포인터 형식으로 만들면 문자열 상수가 만들어 지는 것.
	char strArr[] = "Hello, World!"; // 문자열을 배열 형식 -> 변수형태로 생성 => 값 변경 가능
	char* str = strArr;
	*(str + 1) = 'E'; // 값 변경된다.
		printf("*(str + 1): %c\n", *(str + 1));

	return 0;

}

// void PrintArray(int _arr[], int _len)와 같은 폼이다.
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