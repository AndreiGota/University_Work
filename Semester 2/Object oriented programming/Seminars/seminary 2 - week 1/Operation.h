#pragma once
#include "repository.h"
typedef struct {
	Repository* repo;
	void* data;
	char* operationType;
}Operation;

Operation* createOperation(Planet* p, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Planet* getPlanet(Operation* o);