#include <stdio.h>
//#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack_HW.h"

stackHead* CreateStack()
{
	stackHead* pHead = (stackHead*)malloc(sizeof(stackHead));
	if (pHead == NULL) //fail to allocate memory for stack head
		return NULL;

	pHead->count = 0;
	pHead->top = NULL;
	return pHead;
};
void DestroyStack(stackHead* pHead)
{
	if (pHead->top == NULL)
		free(pHead);
	else
	{
		stackNode* temp;
		while (pHead->top != NULL)
		{
			temp = pHead->top;
			pHead->top = pHead->top->link;
			free(temp);
		}
		free(pHead);
	}
};
void push(stackHead* pHead, Element item)
{
	stackNode* pNode = (stackNode*)malloc(sizeof(stackNode));
	if (pNode == NULL) //fail to allocate memory for new stack node
		exit(-1);

	pNode->data = item;
	pNode->link = pHead->top;
	pHead->top = pNode;
	pHead->count++;
};

Element pop(stackHead* pHead)
{
	if (pHead->count == 0) //empty stack
	{
		printf("stack is empty\n");
		return 0;
	}
	else
	{
		Element top_item = pHead->top->data;
		stackNode* pOldTop = pHead->top;
		pHead->top = pOldTop->link;
		free(pOldTop);

		pHead->count--;
		return top_item;
	}
};

int isEmptyStack(stackHead* pHead)
{
	if (pHead->count == 0)
		return True;
	else
		return False;
};
int PriorityOper(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 1;
	}
	return -1;
};
int CompareOper(char op1, char op2)
{
	int op1_pri = PriorityOper(op1);
	int op2_pri = PriorityOper(op2);
	if (op1_pri > op2_pri)
		return 1;
	else if (op1_pri < op2_pri)
		return -1;
	else
		return 0;
};
char* infix2postfix(char *infix)
{
	int length = strlen(infix);
	char* postfix = (char*)malloc(length + 1);
	stackHead* pHead = CreateStack();
	Element token;
	int index_postfix = 0;
	Element topOper;
	int compare_oper;

	for (int i = 0; i < length; i++)
	{
		token = infix[i];
		if (isdigit(token))
		{
			postfix[index_postfix] = token;
			index_postfix++;
		}
		else
		{
			printf("Current token : %c\n", token);
			if (pHead->top == NULL)
				push(pHead, token);
			else
			{
				topOper = stackTop(pHead);
				compare_oper = CompareOper(topOper, token);
				printf("Top : %c, current : %c, compare result: %d\n", topOper, token, compare_oper);
				printf("The number of item in the stack is %d\n", pHead->count);
				if (compare_oper == 1)   // if top in the stack is prior to the current token,
				{
					while (pHead->count != 0)
					{
						Element temp = pop(pHead);
						postfix[index_postfix] = temp;
						index_postfix++;
					}
					push(pHead, token);
				}
				else
					push(pHead, token);
			}
		}
	}
	while (pHead->count != 0)
	{
		Element temp = pop(pHead);
		postfix[index_postfix] = temp;
		index_postfix++;
	}
	postfix[index_postfix] = '\0';
	DestroyStack(pHead);
	return postfix;
};

int char2int(char op)
{
	if (isdigit(op))
		return op - '0';
	else
	{
		printf("can't be converted to an integer\n");
		exit(-1);
	}
};


////////////// HW2 : complete the following functions ///////////////

Element stackTop(stackHead* pHead)
{
    if (pHead->count == 0) //empty stack
	{
		printf("stack is empty\n");
		return 0;
	}
	else // show top item
	{
		Element top_item = pHead->top->data;
		return top_item;
	}
};

float evalPostfix(char* postfix)//postfix is input data
{	
	char* Postfix;
	Postfix = infix2postfix(postfix);//post postfix value computed
	int length = strlen(Postfix);
	stackHead* pHead = CreateStack();
	Element token;
	int index_postfix = 0;
	int oper;
	for (int i = 0; i<length; i++)
	{
		token = Postfix[i];
		double num1 = 0;
		double num2 = 0;
		if (token != '+' && token != '-' && token != '*' && token != '/')// when the token is a number
		{
			oper = char2int(token);//converting a char an integer
			push(pHead,oper);
		}
		else
		{
			num2 = pop(pHead);
			num1 = pop(pHead);
			switch(token)//Calculated by each operator
			{
				case '+': push(pHead,num1+num2); break;
				case '-': push(pHead,num1-num2); break;
				case '*': push(pHead,num1*num2); break;
				case '/': push(pHead,num1/num2); break;
			}//and push the calculation result
		}

	}
	float value = pop(pHead);
	DestroyStack(pHead);
	return value;
}
 
int main()
{
	
	int b;
	stackHead stack;
	CreateStack();
	push(&stack, 0);
	push(&stack, 1);
	
	int value;
	value = evalPostfix("3/2");
	printf("%d\n", value);
	
};	