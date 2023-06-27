#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

//BC: O(n)
//WC: O(n)
//Total: O(n)
Bag::Bag() {
	capacity = 3;
	length = 0;
	bagsize = 0;
	b = new TElem[capacity];
	max_num = INT_MIN;
	min_num = INT_MAX;
	for (int i = 0; i < capacity; i++)
		b[i] = 0;
}

//BC: O(1)
//WC: O(n)
//Total: O(n)
void Bag::add(TElem elem) {
	if (length == capacity) {
		capacity = capacity * 2;
		TElem* newb = new TElem[capacity];
		for (int i = 0; i < length; i++) {
			newb[i] = b[i];
		}
		delete[] b;
		b = newb;
	}

	if (min_num == INT_MAX) {
		min_num = elem;
		max_num = elem;
		b[0] = 1;
		length++;
		bagsize++;
	}
	else if (elem > max_num) {
		int dif = elem - min_num;
		int dif2 = elem - max_num;
		max_num = elem;
		if (max_num - min_num + 1 >= capacity) {
			capacity = dif * 2;
			TElem* newb = new TElem[capacity];
			for (int i = 0; i < length; i++) {
				newb[i] = b[i];
			}
			delete[]  b;
			b = newb;
			for (int i = length; i < capacity; i++)
				b[i] = 0;
		}
		b[dif] = 1;
		bagsize++;
		length += dif2;
	}
	else if (elem < min_num) {
		int dif = min_num - elem;
		min_num = elem;
		if (max_num - min_num + 1 >= capacity) {
			capacity = (max_num - min_num) * 2;
			TElem* newb = new TElem[capacity];
			for (int i = 0; i < length; i++) {
				newb[i] = b[i];
			}
			delete[]  b;
			b = newb;
			for (int i = length; i < capacity; i++)
				b[i] = 0;
		}
		for (int i = 0; i < dif; i++) {
			length++;
			for (int j = length; j > 0; j--)
				b[j] = b[j - 1];
		}
		for (int i = 1; i < dif; i++)
			b[i] = 0;
		b[0] = 1;
		bagsize++;
	}
	else {
		int dif = elem - min_num;
		b[dif]++;
		bagsize++;
	}
}

//BC: O(1)
//WC: O(n^2)
//Total: O(n)
bool Bag::remove(TElem elem) {
	if (search(elem) == false)
		return false;
	b[elem - min_num]--;
	bagsize--;

	//if elem = min_num and b[elem-min_num] = 0 we need a new min_num and resize the length
	while (b[0] == 0 && length > 0) {
		for (int i = 0; i < length; i++)
			b[i] = b[i + 1];
		length--;
		min_num++;
	}

	//if elem = max_num and b[elem-min_num] = 0 we need a new max_num and resize the length
	while (b[length - 1] == 0 && length > 0) {
		length--;
		max_num--;
	}
	return true;
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
bool Bag::search(TElem elem) const {
	if (max_num == INT_MIN || elem < min_num || elem > max_num)
		return false;
	int dif = elem - min_num;
	return b[dif] != 0;
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
int Bag::nrOccurrences(TElem elem) const {
	if (search(elem) == false)
		return 0;
	return b[elem - min_num];
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
int Bag::size() const {
	if (bagsize == 0)
		return 0;
	return bagsize;
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
bool Bag::isEmpty() const {
	return bagsize == 0;
}

//BC: O(1)
//WC: O(1)
//Total: O(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//BC: O(1)
//WC: O(n)
//Total: O(n)


//BC: O(1)
//WC: O(1)
//Total: O(1)
Bag::~Bag() {
	delete[] b;
}

