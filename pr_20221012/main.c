#include <stdio.h>

int calGugudan(int _row, int _col);
void printGugudan(int _arr[][9], int _dan);
int main() {
	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		// ������ ����� �ؼ� �迭�� �� �־��ִ� ��
		for (int j = 0; j < 9; j++) {
			arr[i][j] = calGugudan(i + 1, j + 1);
			printf("%d  ", arr[i][j]);
		}
	}
	return 0;


}

// ���� ����� ���ִ� �Լ�
int calMultiply(int _lval, int _rval) {
	int result;
	result = _lval * _rval;
	return result;

}
// ������ ����Ʈ�ؼ� �迭�� �������ִ� �Լ�
void printGugudan(int _arr[][9], int _dan) {

}
