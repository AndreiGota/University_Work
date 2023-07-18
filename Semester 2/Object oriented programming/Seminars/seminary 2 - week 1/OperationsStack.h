#pragma once
#include "DynamicArray.h"
#include "Operation.h"

typedef struct {
	DynamicArray* arr; //array of structures Operation
} OperationsStack;

// create, destroy

void push(OperationsStack*, Operation*);
Operation* pop(OperationsStack*);
int isEmpty(OperationsStack*);