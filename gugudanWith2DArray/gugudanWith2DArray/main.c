#include <stdio.h>
/*
* �Լ��� ���, ������ ��Ȯ�ϰ�
* output ������
* 
* <�ʿ��� �Լ�>
*
1. 2�� �迭�� ���̺����·� ����Ʈ���ִ� �Լ�
�� �Ű����� arr[][9], _rowCnt, _colCnt
�� ���� ���� ��
�� return x -> printf()

2. ���� ���ִ� �Լ�
�� �Ű�����: lval, rval, return result

3. row�� col��ŭ ������ ���߹迭�� ���� ���� ��� �Լ�
�� �Ű����� _row, _col
�� return 2�߹迭

4. ���̺� row ��ܱ��� ������� scan�޾� return �ϴ� �Լ�
��  return dan : row size
*/

// ��� ����� �� scan�ϴ� scanner
int DanScanner();

//row�� col���� �޾� int 2�߹迭�� �� ��� �Լ� ( ������ ����)
int* PutResult2DArray(int _row, int _col);

// rval, lval�޾� ������ �������ִ� �Լ�
int Multiply(int _lVal, int _rVal);

// 2�� �迭�� ���̺����·� ����Ʈ���ִ� �Լ�
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
	printf("��ܱ��� ����ұ��? (~ 9��) : ");
	int dan;
	scanf_s("%d", &dan);
	printf("\n\t<<< %d�ܱ��� ��� >>>\n\n", dan);
	return dan;
}
int* PutResult2DArray(int _row, int _col) {
	int arr2D[9][9];
	//for�� ������ �����Լ� ȣ��
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

	// column num�� ������ִ� for��
	for (int k = 0; k < 9; k++) {
		printf("  %d  ", k+1);
	}
	printf("\n");
	printf("   ");

	// ���̺� �ٹ̱� for��
	for (int k = 0; k < 9; k++) {
		printf(" --- ");
	}
	printf("\n");

	// �迭 �� ����ִ� for��
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
