#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 2
#define CHAR_SIZE sizeof(char)

#define SAFE_FREE(p) do{ if(p){ free(p); p =NULL; } }while(0)

int StrLen(const char* const _pStr);
int StrCmp(const char* const  _pLhs, const char* const _pRhs);
void StrCpy(char** const _pDst, const char* const _pSrc);
void StrCat(char** const _pDst, const char* const _pSrc1, const char* const _pSrc2);

int main()
{
	const char* pSample1 = "Hello";
	const char* pSample2 = "World";
	const char* pSample3 = "Hello, World!";
	char* buff = NULL;

	printf("<%s> Length: %d\n", pSample1, StrLen(pSample1));
	printf("%s == %s : %s\n", pSample1, pSample2, StrCmp(pSample1, pSample2) == TRUE ? "True" : "False");
	printf("%s == %s : %s\n", pSample1, pSample1, StrCmp(pSample1, pSample1) == TRUE ? "True" : "False");

	StrCpy(&buff, pSample3);
	printf("StrCpy < %s> : %s\n", pSample3, buff);
	SAFE_FREE(buff);
	
	StrCat(&buff, pSample1, pSample2);
	printf("StrCat <%s> <%s> : %s\n", pSample1, pSample2, buff);

	SAFE_FREE(buff);
	return 0;

}

int StrLen(const char* const _pStr)
{
	if (_pStr == NULL) return -1;
	int cnt = 0;
	while (*(_pStr + cnt) != '\0')
	{
		++cnt;
	}
	return cnt;
}
int StrCmp(const char* const _pLhs, const char* const _pRhs)
{
	if (_pLhs == NULL || _pRhs == NULL) return FALSE;

	int lhsLen = StrLen(_pLhs);
	int rhsLen = StrLen(_pRhs);

	if (lhsLen != rhsLen) return FALSE;
	for (int i = 0; i < lhsLen; ++i)
		if (*(_pLhs + i) != *(_pRhs + i)) return FALSE;

	return TRUE;
}

void StrCpy(char** const _pDst, const char* const _pSrc)
{
	if((*_pDst) != NULL) SAFE_FREE((*_pDst));
	int srcLen = StrLen(_pSrc);
	(*_pDst) = (char*)malloc(CHAR_SIZE * (srcLen + CHAR_SIZE));
	if ((*_pDst) == NULL)return;
	for (int i = 0; i < srcLen; ++i)
	{
		*((*_pDst) + i) = *(_pSrc + i);
	}
	*((*_pDst) + srcLen) = '\0';
}

void StrCat(char** const _pDst, const char* const _pSrc1, const char* const _pSrc2)
{
	if (_pSrc1 == NULL || _pSrc2 == NULL)return;
	if ((*_pDst) != NULL) SAFE_FREE((*_pDst));

	int src1Len = StrLen(_pSrc1);
	int src2Len = StrLen(_pSrc2);

	(*_pDst) = (char*)malloc(CHAR_SIZE * (src1Len + src2Len + CHAR_SIZE));
	if ((*_pDst) == NULL) return;
	for (int i = 0; i < src1Len; ++i)
		*((*_pDst) + i) = *(_pSrc1 + i);
	for (int i = 0; i < src2Len; ++i)
		*((*_pDst) + src1Len + i) = *(_pSrc2 + i);
	*((*_pDst) + src1Len + src2Len) = '\0';
}
