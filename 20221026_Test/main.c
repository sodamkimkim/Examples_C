#include <stdio.h>
#include <malloc.h>
#define SAFE_FREE(p)do{if(p){free(p);p=NULL;}}while(0);
#define DIFFERENT 0;
#define SAME 1;
/*
# StringLength - 문자열 길이 반환해주는 함수
*/
int StringLength(const char* const _str);
/*
# strCmp - 문자열 두개를 비교하는 함수
- 같으면 1 : 다르면 0 return 
*/
int StrCmp(const char* const _str1, const char* const _str2);

/*
# StrCpy - 문자열 복사해주는 함수
-  결과) buff에 동적메모리 주소 복사
*/
char* StrCpy(const char* const _sour);
/*
# StrCat - 문자열 합쳐주는 함수
결과) 동적 메모리 주소 return 
*/
char* StrCat(const char* const _sour1, const char* const _sour2);

// # 널메시지 출력함수. 에러코드는 안뜸
void PrintNULLMessage();

// # char* 메모리 NULL여부 판별 함수.
void CheckCharNULLMemory(const char* const _memory);

int main() {
	// <Test-Constraint>
	// 1. 함수 내 동적할당
	// 2. 포인터 주소 연산
	// 3. 예외처리
	// 4. const
	//﻿ 20221026_Test_String + 이름

	char* buff = NULL;

	// # StringLenghth test
	printf("StringLength test: %d\n", StringLength("abcde")); //5

	// #StringCmp test
	printf("StringCmp test : %s\n", StrCmp("Hello", "Helsdflo") == 1 ? "SAME" : "DIFFERENT"); // return 1. 같음

	// # StrCpy test
	buff = StrCpy("Hello! world");
	printf("%s\n", buff);
	SAFE_FREE(buff);

	// # StrCat test
	buff = StrCat("Hello", "strCatTest!\n");
	printf("%s\n", buff);
	SAFE_FREE(buff);

	CheckCharNULLMemory(buff);

	return 0;
}

int StringLength(const char* const _str)
{
	// # 문자열 상수 길이 구하기
	int cnt = 0;
	while (*(_str + cnt) != '\0')
	{
		++cnt;
	}
	return cnt;
}

int StrCmp(const char* const _str1, const char* const _str2)
{
	// 1. 각 문자열 길이 구하기
	int lhsLen = StringLength(_str1);
	int rhsLen = StringLength(_str2);

	// 2. 문자열 길이가 서로 다르면 다른 문자열
	if (lhsLen != rhsLen) return DIFFERENT; // return 0;

	// 3. 문자열 길이만큼 반복하면서 문자 단위로 비교하기
	for (int i = 0; i < lhsLen; ++i) {
		if(*(_str1+i) != *(_str2+i)) return DIFFERENT; // return 0;
	}
	return SAME; // return 1;
}

char* StrCpy(const char* const _sour)
{
	// 1. source문자열 길이 구하기
	int sourLen = StringLength(_sour);
	
	// 2. temp 메모리 동적할당
	char* temp = (char*)malloc(sizeof(char) * (sourLen + 1));
	CheckCharNULLMemory(temp);

	// 3. source 데이터 복사
	for (int i = 0; i < sourLen; ++i)
	{
		*(temp + i) = *(_sour + i);
	}
	// 4. 마지막에 널문자 넣기
	*(temp + sourLen) = '\0';

	// 5. temp 메모리 주소 return 
	return temp;
}

char* StrCat(const char* const _sour1, const char* const _sour2)
{
	// 1. _sour1, _sour2 length 구하기
	int src1Len = StringLength(_sour1);
	int src2Len = StringLength(_sour2);

	// 2. strcat 결과 넣을 동적 메모리 temp생성
	char* temp = (char*)malloc(sizeof(char) * (src1Len + src2Len + 1));
	CheckCharNULLMemory(temp);

	// 3. _sour1 복사
	for (int i = 0; i < src1Len; ++i) {
		*(temp + i) = *(_sour1 + i);
	}
	// 4. _sour2 복사
	for (int i = 0; i < src2Len; ++i) {
		*(temp + src1Len + i) = *(_sour2+ i);
	}

	// 5. 마지막에 널문자 입력
	int destLen = src1Len + src2Len;
	*(temp + destLen) = '\0';

	// 6. 동적 메모리 주소 return 
	return temp;
}

void PrintNULLMessage()
{
	printf("Memory is NULL! [%s], [%d]\n", __FILE__,__LINE__);
}

void CheckCharNULLMemory(const char* const _memory)
{
	if (!_memory)
	{
		PrintNULLMessage();
		return;
	}
	return;
}

