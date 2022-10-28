#include "Calculator.h"
char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8','9','.' };
int IsNumber(char Cipher)
{
	int i = 0;
	int ArrayLength = sizeof(NUMBER);
	for (i = 0; i < ArrayLength; i++)
	{
		if (Cipher == NUMBER[I])
			return 1;
	}
	return 0;
}
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
	unsigned int i = 0;
	for (i = 0; 0 != Expression[i]; i++)
	{
		Token[i] = Expression[i];
		if (IsNumber(Expression[i]) == 1)
		{
			*TYPE = OPERAND;
			if (IsNumber(Expression[i + 1] != 1))
				break;
		}
		else {
			*TYPE = Expression[i];
			break;
		}
	}
		Token[++i] = '\0';
		return i;
}
int GetPriority(char Operator, int InStack)
{
	int Priority = -1;
	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (InStack)
			Priority = 3;
		else
			Priority = 0;
		break;

	case MULTIPLY:
	case DIVIDE:
		Priority = 1;
		break;

	case  PLUS:
	case MINUS:
		Priority = 2;
		break;
	}
	return Priority;
}
int IsPrior(char OperatorInStack, char OperatorInToken)
{
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}
void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
	LinkedListStack* Stack;
	char Token[32];
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);
	LLS_CreateStack(&Stack);

	while (Position < Length)
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type);
		if (Type == OPERAND)
		{
			strcat(PostfixExpression, Token);
			strcat(PostfixExpression, " ");
		}
		else if (Type == RIGHT_PARENTHESIS)
		{
			while (!LLS_IsEmpty(Stack))
			{
				Node* Popped = LLS_Pop(Stack);
				if (Popped->Data[0] == LEFT_PARENTHESIS)
				{
					LLS_DestroyNode(Popped);
					break;
				}
				else
				{
					strcat(PostfixExpression, Popped->Data);
					LLS_DestroyNode(Popped);
				}
			}
		}
	}
}