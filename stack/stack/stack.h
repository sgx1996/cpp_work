#pragma once
#pragma once
#ifndef __LITE_QUEUE_h__
#define __LITE_QUEUE_h__

#include <stdbool.h>

typedef struct _stackNode
{
	char *data;
	int size;
	int capacity;
}stackNode, *stackNodePtr;

typedef void(*LITE_FUNC)(char);


void Push(stackNodePtr* ptr, const char data);
char Pop(stackNodePtr* ptr);

void stack_foreach(stackNodePtr, LITE_FUNC);

bool stack_empty(stackNodePtr);

#endif
