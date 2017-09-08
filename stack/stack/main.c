#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int ALLOC_STEP = 100;

void Push(stackNodePtr* ptr, const char data)
{
	assert(ptr != 0);
	//考虑空队列
	if (*ptr == 0)
	{
		*ptr = (stackNodePtr)calloc(1, sizeof(stackNode));
	}
	//考虑队列内部数据空间不足时扩容
	if ((*ptr)->size + 1 > (*ptr)->capacity)
	{
		//给数据成员分配空间
		(*ptr)->data = (char*)realloc((*ptr)->data, (*ptr)->capacity + ALLOC_STEP);
		(*ptr)->capacity = (*ptr)->capacity + ALLOC_STEP;
	}
	//给队列内部数据按索引赋值(尾部)
	if ((*ptr)->data[0] == 0)
	{
		(*ptr)->data[0] = data;
	}
	else
	{
		for (int i = (*ptr)->size;i > 0; i--)
		{
			(*ptr)->data[i] = (*ptr)->data[i - 1];
		}
		(*ptr)->data[0] = data;
	}
	(*ptr)->size += 1;

}
char Pop(stackNodePtr* ptr)
{
	assert(ptr != 0 && (*ptr) != 0 && (*ptr)->size != 0);

	char ret = (*ptr)->data[0];

	char* pdata = (char*)malloc((*ptr)->capacity);
	memcpy(pdata, (*ptr)->data + 1, (*ptr)->size - 1);
	free((*ptr)->data);
	(*ptr)->data = pdata;

	//memmove((*ptr)->data, (*ptr)->data + 1, (*ptr)->size - 1);

	(*ptr)->size -= 1;

	return ret;
}

bool stack_empty(stackNodePtr queue)
{
	assert(queue != 0);
	return queue->size == 0;
}

void stack_foreach(stackNodePtr queue, LITE_FUNC func)
{
	assert(queue);

	for (int i = 0; i <queue->size; i++)
	{
		func(queue->data[i]);
		printf("-->");
	}
	printf("NULL\n");
}
void instructions(void);

void printElement(char data)
{
	printf("%c ", data);
}
int main()
{
	stackNodePtr pQueue = 0;

	char item;

	instructions();
	printf("? ");
	int choice;
	scanf("%d", &choice);

	while (choice != 4)
	{

		switch (choice)
		{

		case 1:
		{
			printf("Enter a character: ");
			scanf("\n%c", &item);
			Push(&pQueue, item);
		}
		break;
		case 2:
		{
			if (!stack_empty(pQueue))
			{
				item = Pop(&pQueue);
				printf("\'%c\' has been dequeued.\n", item);
			}

		}
		break;

		case 3:
		{
			printf("queue elements:\n");
			stack_foreach(pQueue, printElement);
			printf("\n");
		}
		break;

		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}

	printf("End of run.\n");
	return 0;
}

void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to add an item to the stack\n"
		"   2 to remove an item from the stack\n"
		"   3 show all elements in the stack\n"
		"   4 to end\n");
}
