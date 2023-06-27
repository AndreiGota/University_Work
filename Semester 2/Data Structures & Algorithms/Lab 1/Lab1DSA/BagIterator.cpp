#include <exception>
#include <iostream>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//BC: O(1)
//WC: O(1)
//Total: O(1)
BagIterator::BagIterator(const Bag& c) : bag(c)
{
	index = 0;
	frequency = bag.b[0];
	poz = 0;
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
void BagIterator::first() {
	index = 0;
	frequency = bag.b[0];
	poz = 0;
}

//BC: O(1)
//WC: O(n)
//Total: O(1)
void BagIterator::next() {
	if (!valid()) {
		throw runtime_error{ "" };
	}
	else {
		index++;
		frequency--;
		if (frequency <= 0) {
			poz++;
			while (bag.b[poz] == 0 && poz < bag.length)
				poz++;
			frequency = bag.b[poz];
		}
	}
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
bool BagIterator::valid() const {
	return 0 <= index && index < bag.bagsize;
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
TElem BagIterator::getCurrent() const
{
	if (!valid()) {
		throw runtime_error{ "" };
	}
	else {
		return bag.min_num + poz;
	}
}
