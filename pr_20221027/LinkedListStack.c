#include "LinkedListStack.h"
void LLS_CreateStack(LinkedListStack** Stack)
{
	// ������ ���� ����ҿ� ����
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}
void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	// ������ ���� ����ҿ��� ����
	free(Stack);
}
Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL; // ���� ��忡 ���� �����ʹ� �η� �ʱ�ȭ�Ѵ�.
	return NewNode;
	// ����� �ּҸ� ��ȯ�Ѵ�.
}
void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}
void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List 
}
}