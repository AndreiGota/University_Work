#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& map;

	MultiMap::Node* current, * head;
	int pos;

public:
	MultiMapIterator(const MultiMap& map);
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
};

