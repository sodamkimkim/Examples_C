#include <stdio.h>
int main(void)
{
	int ary1[4] = { 1, 2, 3, 4 };
	int ary2[4] = { 11, 12, 13, 14 };
	int ary3[4] = { 21,22,23,24 };
	int* pary[3] = { ary1, ary2, ary3 };

	double dary1[4] = { 1, 2, 3, 4 };
	double dary2[4] = { 11, 12, 13, 14 };
	double dary3[4] = { 21,22,23,24 };
	double* pdary[3] = { dary1, dary2, dary3 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d, %p\n", pary[i][j], &pary[i][j]);
			printf("%d, %p\n", *(pary[i]+j), &*(pary[i] + j)); // �ּ� 4byte�� ����
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.1lf, %p\n", pdary[i][j], &pdary[i][j]);
			printf("%.1lf, %p\n", *(pdary[i] + j), &*(pdary[i] + j)); // �ּ� 8byte�� ���� => ������ �ּ�ũ�Ⱑ �ƴ϶� �ش纯�� �ڷ���ũ�⸸ŭ ����(double)
		}
		printf("\n");
	}
	return 0;
}