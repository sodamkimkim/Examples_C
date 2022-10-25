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

// 0: ����, -1: ����
int Push(int _data);
int Pop();
void PrintAll();

// ����ִ°� �˻��ϴ� �Ŵϱ� 1(T): �������, 0(F) : ������ ����
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
	g_arrStack[g_iIdx++] = _data; // ������ ������ ��� -> ������ �ְ��� ����
	return 0;
}
int Pop() {
	if (CheckEmpty())
	{
		PrintEmptyMessage();
		return ERROR_CODE_EMPTY;
	}
	return g_arrStack[--g_iIdx]; //g_iIdx �ϳ� �������ְ� Pop�Ѵ�.
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