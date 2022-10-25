#include <stdio.h>
#include <limits.h>
#define STACK_SIZE 5
#define TRUE 1
#define FALSE 0
#define EMPTY 1
#define NOT EMPTY 0
#define ERROR_CODE_EMPTY -12345

int g_arrStack[STACK_SIZE] = { 0 };
int g_iIdx = 0;

// 0: 성공, -1: 실패
int Push(int _data);
int Pop();
void PrintAll();

// 비어있는거 검사하는 거니까 1(T): 비어있음, 0(F) : 데이터 있음
int CheckEmpty();

void PrintEmptyMessage();
int main() {
	PrintAll();
	printf("Pop: %d\n", Pop());
	Pop();
	for (int i = 0; i < 7; ++i)
	{
		Push(i + 1);
	}
	PrintAll();
	printf("Pop: %d\n", Pop());
	printf("Pop: %d\n", Pop());
	printf("Pop: %d\n", Pop());
	PrintAll();
	return 0;
}
int Push(int _data)
{
	if (g_iIdx == STACK_SIZE)
	{
		printf("Stack is full\n");
		return -1;
	}
	g_arrStack[g_iIdx++] = _data; // 후증가 연산자 사용 -> 데이터 넣고나서 증가
	return 0;
}
int Pop() {
	if (CheckEmpty())
	{
		PrintEmptyMessage();
		return ERROR_CODE_EMPTY;
	}
	return g_arrStack[--g_iIdx]; //g_iIdx 하나 감소해주고 Pop한다.
}
void PrintAll() {
	if (CheckEmpty())
	{
		PrintEmptyMessage();
		return ERROR_CODE_EMPTY;
	}
	for (int i = 0; i < g_iIdx; i++)
	{
		printf("%d - ", g_arrStack[i]);
	}
	printf("(%d / %d)\n", g_iIdx, STACK_SIZE);
}
int CheckEmpty()
{
	return g_iIdx == 0 ? EMPTY : FALSE;
}
void PrintEmptyMessage() {
	printf("Stack is Empty\n");
}