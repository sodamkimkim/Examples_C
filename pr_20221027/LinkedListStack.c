#include "LinkedListStack.h"
void LLS_CreateStack(LinkedListStack** Stack)
{
	// 스택을 자유 저장소에 생성
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
	// 스택을 자유 저장소에서 해제
	free(Stack);
}
Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 널로 초기화한다.
	return NewNode;
	// 노드의 주소를 반환한다.
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