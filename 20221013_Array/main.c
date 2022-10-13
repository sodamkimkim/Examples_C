#include <stdio.h>

// 치환
#define ARR_LEN 10 // 컴파일러는 30으로 본다(리터럴 상수로 본다.

void PrintArray(int _arr[], int _arrLen);

//2차원 배열을 매개변수로 던질 때는 최소한 col사이즈는 넣어줘야 행을 구분할 수 있다.
void PrintArray2D(int _arr[][3], int _rowCnt, int _colCnt);

int main() {
	int arr[ARR_LEN] = { 10,20,30 };
	printf("arr size : %d byte\n", sizeof(arr));
	printf("arr[0] size: %d byte\n", sizeof(arr[0]));
	printf("arr Address: %p\n", arr); // 배열이름 == (첫 번째 배열 요소의 주소)
	printf("\n");

	for (int i = 0; i < ARR_LEN; i++) {
		printf("arr[%d] : %i (%p), %p\n", i, arr[i], &arr[i], arr);
	}

	/*arr[100] = 10000;
	printf("arr[100] : %d (%p)\n", arr[100], &arr[100]);
	arr[-1] = -10;
	printf("arr[-1] : %d (%p)\n, arr[-1], &arr[-1]");*/

	// compile -Time Error
	// Run-Time Error

	//////////////////////////////////////
	printf("\n");

	// 다차원배열
	// 2차원 배열
	//int arr2D[2][3] = { 0 };
	//int arr2D[2][3] = { 1,2 };
	int arr2D[2][3] = {
		{11,12,13},{21,22,23}
	};
	//특정 row 찾아갈 때 [3] 만큼 건너뛰어라
	printf("arr2D Address : %p\n", arr2D);
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 3; col++) {
			printf("arr[%d][%d] = %d (%p)\n", row, col, arr2D[row][col], &arr2D[row][col]);
		}
	}
	printf("\n");

	printf("arr2D[0][0]: %p\n", &arr2D[0][0]);
	printf("arr2D[0][1]: %p\n", &arr2D[0][1]);
	printf("arr2D[1][0]: %p\n", &arr2D[1][0]);
	printf("\n");

	printf("arr2D[0] : %p\n", arr2D[0]);
	printf("&arr2D[0] : %p\n", &arr2D[0]);
	int ptr = arr2D;
	printf("*arr2D[0] : %d\n", *arr2D[0]);
	printf("arr2D[0][0] : %d\n", arr2D[0][0]);
	printf("arr2D[0][0] : %p\n", &arr2D[0][0]);

	printf("\n");

	printf("arr2D[1] : %p\n", arr2D[1]);
	printf("arr2D[0][4] : %d\n", arr2D[0][4]); //[1][1]의 값이출력된다.
	printf("arr2D[0][4] : %p\n", &arr2D[0][4]);
	
	

	//////////////////////////////
	printf("\n");
	int printArr[4] = { 1,2,3,4 };
	PrintArray(printArr, sizeof(printArr)/sizeof(printArr[0]));
	printf("???%p\n\n", printArr);
	printf("???%d\n\n", printArr[0]);
	// 함수 호출할 때,, 배열을 매개변수로 넣어주면 주소가 복사된다.
	// 즉 호출된 함수 매개로 던져지는 배열에는 주소값만 가지고 sizeof로 출력해보면 주소값 그자체의 size만 출력된다.
	// 배열이 생성된 곳에서 sizeof를 찍어보면 주소의 크기가 아니라 배열자체의 크기가 출력됨을 알 수 있다.
	// 즉 생성된 곳과 호출된 함수 내에서 모두 배열변수는 주소값을 가지긴 하지만
	// 생성된 곳의 배열은 배열 그자체라서 요소별 접근이 가능하지만 함수에 전달된 배열은 주소값일 뿐이다.
	// 즉 배열을 매개변수로 던져줄 때는, 배열이 생성된 곳에서 size를 구해서 같이 던져줘야 한다.
	// 배열특성으로 온전하게 전달된 것은 아니지만 함수에서 주소값을 받은 후 얼마나 건너뛸 것인지[ i ]로 요소 접근은 가능하다.

	int printArr2D[3][3] = { 1,2,3,4,5,6,7,8,9 };
	PrintArray2D(printArr2D, 3, 3);
	return 0;
}
void PrintArray(int _arr[], int _arrLen)
{
	printf("_arr Address : %p\n", _arr);

	for (int i = 0; i < _arrLen; ++i) {
		printf("_arr[%d]: %d\n", i, _arr[i]);
	}
}
void PrintArray2D(int _arr2D[][3], int _rowCnt, int _colCnt)
{
	for (int row = 0; row < _rowCnt; ++row) {
		for (int col = 0; col < _colCnt; ++col) {
			printf("_arr2D[%d[%d] = %d\n", row, col, _arr2D[row][col]);
		}
	}
}