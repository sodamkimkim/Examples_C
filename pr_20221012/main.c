#include <stdio.h>

int calGugudan(int _row, int _col);
void printGugudan(int _arr[][9], int _dan);
int main() {
	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		// 구구단 계산을 해서 배열에 값 넣어주는 곳
		for (int j = 0; j < 9; j++) {
			arr[i][j] = calGugudan(i + 1, j + 1);
			printf("%d  ", arr[i][j]);
		}
	}
	return 0;


}

// 곱셈 계산을 해주는 함수
int calMultiply(int _lval, int _rval) {
	int result;
	result = _lval * _rval;
	return result;

}
// 구구단 프린트해서 배열에 저장해주는 함수
void printGugudan(int _arr[][9], int _dan) {

}
