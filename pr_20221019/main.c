#include <stdio.h>
int main() {
	int var = 10;
	int* pVar = &var;
	printf("pVal(%p) == &var(%p)\n", pVar, &var);
	*pVar = 20;
	printf("*pVar(%d), var(%d)\n", *pVar, var);
	printf("pVar Address : %p\n", &pVar);
	printf("*(&pVar): %p\n", *(&pVar));

	printf("\n");
	int arr[] = { 1,2,3 };
	int* pArr = arr; // �迭�� ������ (: �迭������)
	for (int i = 0; i < 3; ++i) {
		printf("pArr[%d]: %d\n", i, pArr[i]);
		printf("pArr[%d]: %p\n", i, &pArr[i]);
	}

}