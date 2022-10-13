#include <stdio.h>
/*
* 함수의 기능, 목적이 명확하게
* output 가지기
* 
* <필요한 함수>
*
1. 2중 배열을 테이블형태로 프린트해주는 함수
ㄴ 매개변수 arr[][9], _rowCnt, _colCnt
ㄴ 가로 세로 값
ㄴ return x -> printf()

2. 곱셈 해주는 함수
ㄴ 매개변수: lval, rval, return result

3. row와 col만큼 생성된 이중배열에 곱셈 값을 담는 함수
ㄴ 매개변수 _row, _col
ㄴ return 2중배열

4. 테이블 row 몇단까지 출력할지 scan받아 return 하는 함수
ㄴ  return dan : row size
*/

// 몇단 출력할 지 scan하는 scanner
int DanScanner();

//row와 col값을 받아 int 2중배열에 값 담는 함수 ( 포인터 리턴)
int* PutResult2DArray(int _row, int _col);

// rval, lval받아 곱셈값 리턴해주는 함수
int Multiply(int _lVal, int _rVal);

// 2중 배열을 테이블형태로 프린트해주는 함수
int Print2DArray(int _arr2D[][9], int _rowCnt, int _colCnt);

int main() {
	int dan = 0;
	int* arr;
	dan = DanScanner();
	arr = PutResult2DArray(dan, 9);
	Print2DArray(arr, dan, 9);
	return 0;
}
int DanScanner() {
	printf("몇단까지 출력할까요? (~ 9단) : ");
	int dan;
	scanf_s("%d", &dan);
	printf("\n\t<<< %d단까지 출력 >>>\n\n", dan);
	return dan;
}
int* PutResult2DArray(int _row, int _col) {
	int arr2D[9][9];
	//for문 돌려서 곱셈함수 호출
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++) {
			arr2D[i][j] = Multiply(i + 1, j + 1);
		}
	}

	return arr2D;
}

int Multiply(int _lVal, int _rVal)
{
	int result = _lVal * _rVal;
	return result;
}

int Print2DArray(int _arr2D[][9], int _rowCnt, int _colCnt)
{
	printf("   ");

	// column num을 출력해주는 for문
	for (int k = 0; k < 9; k++) {
		printf("  %d  ", k+1);
	}
	printf("\n");
	printf("   ");

	// 테이블 꾸미기 for문
	for (int k = 0; k < 9; k++) {
		printf(" --- ");
	}
	printf("\n");

	// 배열 값 찍어주는 for문
	for (int i = 0; i < _rowCnt; i++)
	{
		printf("%d |", i + 1);
		for (int j = 0; j < _colCnt; j++) {
			_arr2D[i][j] = Multiply(i + 1, j + 1);
			if (_arr2D[i][j] >= 10) {
				printf("  %d", _arr2D[i][j]);
				printf(" ");
			}
			else {
				printf("  %d", _arr2D[i][j]);
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}
