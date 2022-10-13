#include <stdio.h>

// ġȯ
#define ARR_LEN 10 // �����Ϸ��� 30���� ����(���ͷ� ����� ����.

void PrintArray(int _arr[], int _arrLen);

//2���� �迭�� �Ű������� ���� ���� �ּ��� col������� �־���� ���� ������ �� �ִ�.
void PrintArray2D(int _arr[][3], int _rowCnt, int _colCnt);

int main() {
	int arr[ARR_LEN] = { 10,20,30 };
	printf("arr size : %d byte\n", sizeof(arr));
	printf("arr[0] size: %d byte\n", sizeof(arr[0]));
	printf("arr Address: %p\n", arr); // �迭�̸� == (ù ��° �迭 ����� �ּ�)
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

	// �������迭
	// 2���� �迭
	//int arr2D[2][3] = { 0 };
	//int arr2D[2][3] = { 1,2 };
	int arr2D[2][3] = {
		{11,12,13},{21,22,23}
	};
	//Ư�� row ã�ư� �� [3] ��ŭ �ǳʶپ��
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
	printf("arr2D[0][4] : %d\n", arr2D[0][4]); //[1][1]�� ������µȴ�.
	printf("arr2D[0][4] : %p\n", &arr2D[0][4]);
	
	

	//////////////////////////////
	printf("\n");
	int printArr[4] = { 1,2,3,4 };
	PrintArray(printArr, sizeof(printArr)/sizeof(printArr[0]));
	printf("???%p\n\n", printArr);
	printf("???%d\n\n", printArr[0]);
	// �Լ� ȣ���� ��,, �迭�� �Ű������� �־��ָ� �ּҰ� ����ȴ�.
	// �� ȣ��� �Լ� �Ű��� �������� �迭���� �ּҰ��� ������ sizeof�� ����غ��� �ּҰ� ����ü�� size�� ��µȴ�.
	// �迭�� ������ ������ sizeof�� ���� �ּ��� ũ�Ⱑ �ƴ϶� �迭��ü�� ũ�Ⱑ ��µ��� �� �� �ִ�.
	// �� ������ ���� ȣ��� �Լ� ������ ��� �迭������ �ּҰ��� ������ ������
	// ������ ���� �迭�� �迭 ����ü�� ��Һ� ������ ���������� �Լ��� ���޵� �迭�� �ּҰ��� ���̴�.
	// �� �迭�� �Ű������� ������ ����, �迭�� ������ ������ size�� ���ؼ� ���� ������� �Ѵ�.
	// �迭Ư������ �����ϰ� ���޵� ���� �ƴ����� �Լ����� �ּҰ��� ���� �� �󸶳� �ǳʶ� ������[ i ]�� ��� ������ �����ϴ�.

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