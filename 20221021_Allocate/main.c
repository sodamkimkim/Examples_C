#include <stdlib.h>
#include <stdio.h>
void ChangeValue(int* _pVal);
void Swap(int* _pLhs, int* _pRhs);
char* StringConstant2Variables(const char* _str);
int main() {

	// # 메모리 동적 할당(Memory Dynamic Allocate)
	int* pVar = NULL;
	//printf("Before pVar : %d (%p)\n",*pVar, pVar);
	pVar = (int*)malloc(sizeof(int));
	if (pVar != NULL)
	{
		*pVar = 10;
		printf("pVar : %d (%p)\n", *pVar, pVar);
	}

	// # 메모리 누수(Memory leak)
	if (pVar != NULL) {
		free(pVar);
		pVar = NULL; // 주소도 초기화 . 해제해도 문제 없다. free(pVar)하고 주소도 NULL해주기
	}
	//free(pVar);

	/// ///////////////////////////////////////////
	printf("\n");
	// # 정적 배열
	int arr[5];
	int len = 5;
	// # 동적 배열(Dynamic Array)
	int* pArr = (int*)malloc(sizeof(int) * len);
	pArr[0] = 100;
	*(pArr + 1) = 200;
	printf("pArr[0]: %d (%p)\n", pArr[0], &pArr[0]);
	printf("*(pArr + 1) : %d (%p)\n", *(pArr + 1), pArr + 1);
	printf("pArr Size: %d byte\n", sizeof(pArr)); // 포인터라서 4byte. 정적 배열만 그 배열의 크기가 나온다.

	//*(pArr + 10) = 100;
	//printf("*(pArr + 10) : %d (%p)\n", *(pArr + 10), pArr + 10);

	if (pArr != NULL) {
		free(pArr);
		pArr = NULL;
	}
	///////////////////////////////////////////////////////////////////////////////
	printf("\n");
	// # 이차원 동적배열
	int** ppArr2D = (int**)malloc(sizeof(int*) * 2); // int포인터 두개 공간생성 -> 2차원 포인터 주소 반환
	ppArr2D[0] = (int*)malloc(sizeof(int) * 3);
	*(ppArr2D + 1) = (int*)malloc(sizeof(int) * 3);
	// ㄴ 이렇게 3개짜리 두개 따로따로하면 주소 연결안된다. malloc한번만 해야 연속됨.
	// 따라서 일반적인 정적 이차원 배열처럼 연속된 주소를 갖고 싶다면 6개짜리 선언하고 주소를 각각할당하는 방식을 사용해야 한다.

	// ㄴ 만약 malloc할당 실패해서 *(ppArr2D + 1) =  null; 로 나갈 때, 앞에서 할당한 것들도 free해주고 나가야 한다. 그래야 메모리 누수 발생안한다.
	// ㄴ : stack 되감기

	ppArr2D[0][0] = 11;
	*(*(ppArr2D + 1) + 0) = 21;
	printf("ppArr2D[0][0] : %d (%p) \n", ppArr2D[0][0], &ppArr2D[0][0]);
	printf("*(*(ppArr2D+1)+0): %d (%p)\n", *(*(ppArr2D + 1) + 0), &(*(*(ppArr2D + 1) + 0)));

	// # 해제는 생성의 역순.
	// malloc 3번 했으면 3번 다 해제 해 줘야 한다. 
	for (int i = 0; i < 2; ++i) {
		if (ppArr2D[i] != NULL) {
			free(ppArr2D[i]);
			ppArr2D[i] = NULL;
		}
	}
	if (ppArr2D != NULL) {
		free(ppArr2D);
		ppArr2D = NULL;
	}
	///////////////////////////////////////////////////////////////////////////////
	printf("\n");
	int var = 0;
	ChangeValue(&var); // 변수의 주소를 복사. 함수 내에서 주소를 찾아가서 값을 바꾸니까 값이 바뀜.
	printf("var : %d\n", var);

	int lhs = 3, rhs = 5;
	Swap(&lhs, &rhs);
	printf("lhs: %d, rhs: %d\n", lhs, rhs);

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");
	char* str = StringConstant2Variables("Hello");
	str[3] = 'L';
	printf("str: %s\n", str);

	// 선언은 함수에서 했지만, (buff) 쓸만큼 쓰고 main에서 해당 주소 해제(buff로 선언했지만 str도 같은 주소값을 가지고 있다.)
	if (str != NULL) {
		free(str);
	}

	///////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// # const
	//  pointer는 const 를 붙일 수 있는 곳이 두 곳
	// 주소 or 값
	double* pDouble = NULL;
	//const double* const pDouble = NULL;  // 둘다 못바꿈
	//const double* pDouble = NULL;  // 값 못바꿈
	//double* const pDouble = NULL;  // 주소 못바꿈
	pDouble = malloc(8);
	*pDouble = 3.14;
	if (pDouble != NULL)
	{
		free(pDouble);
		pDouble = NULL;
	}


	return 0;
}
// # call - by - value (: 매개변수가 값)
// # call - by - reference (: 매개변수가 주소) - 주소를 던져서 주소를 참조해서 값에 접근
void ChangeValue(int* _pVal)
{
	*_pVal = 123456789;

}

void Swap(int* const _pLhs, int* const _pRhs) { // 주소를 못바꾸도록 한다.

	// const를 통해서 값을 어디까지 바꿀 수 있는지 문법단에서 확실히 명시해야한다.
	//_pRhs = 0x88; -> 이렇게 주소 바꿔버리면 안되잖아.
	// 포인터가 나오면 const는 따라가자@!@


	int tmp = *_pRhs;
	*_pRhs = *_pLhs;
	*_pLhs = tmp;
}

char* StringConstant2Variables(const char* const _str)
{
	// 1. 문자열 길이 구하기
	// 2. 버퍼 준비(동적 할당)
	// 3. 문자열 복사
	// 4. 완료된 버퍼 반환
	int cnt = 0;
	while (*(_str+cnt) != '\0') {
		cnt++;
		printf("%d\n", cnt);
	}
	//char* buff = (char*)malloc(sizeof(_str));
	char* buff = (char*)malloc(sizeof(char)* (cnt+1));

	if (buff == NULL) {
		printf("buff == NULL");
		return NULL;
	}
	for (int i = 0; i< cnt; i++) {
		*(buff + i) = *(_str + i);
		printf("%c", *(buff + i));
	}
	printf("\n");
	*(buff + cnt) = '\0';
	return buff;

}
