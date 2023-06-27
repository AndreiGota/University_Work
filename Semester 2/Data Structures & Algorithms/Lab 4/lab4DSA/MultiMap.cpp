#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

//BC=OC=WC=O(1)
MultiMap::MultiMap() {
	this->hash_table_size = 0;
	this->load_factor = 0.7;
	this->capacity = 1;
	this->hash_table = new Node * [this->capacity];
	for (int i = 0; i < this->capacity; i++)
		this->hash_table[i] = nullptr;
}

//BC=O(1)
//OC=WC=O(n), where n is the number of keys that have the same result for the hash_function
void MultiMap::add(TKey c, TValue v) {
	int where = this->hash_function(c);
	Node* now = this->hash_table[where];
	Node* prev = nullptr;
	while (now != nullptr) {
		if (now->key == c) {
			if (now->size == now->capacity)
				MultiMap::resize(now);
			now->values[now->size] = v;
			now->size++;
			this->hash_table_size++;
			break;
		}
		prev = now;
		now = now->next;
	}
	if (now == nullptr) {
		if (double(this->hash_table_size + 1) / this->capacity >= this->load_factor) {
			this->resize();
			where = this->hash_function(c); //recalculates the hash for key because capacity was changed
			now = this->hash_table[where];
			prev = nullptr;
			while (now != nullptr) {
				prev = now;
				now = now->next;
			}
		}
		Node* new_node = new Node;
		new_node->values[0] = v;
		new_node->size = 1;
		new_node->key = c;
		if (prev == nullptr) {
			new_node->next = this->hash_table[where];
			this->hash_table[where] = new_node;
		}
		else {
			new_node->next = prev->next;
			prev->next = new_node;
		}
		this->hash_table_size++;
	}
}

//BC=O(1)
//OC=WC=O(n), where n is the number of keys that have the same result for the hash_function
bool MultiMap::remove(TKey c, TValue v) {
	int where = this->hash_function(c);
	Node* prev = nullptr;
	Node* now = this->hash_table[where];
	while (now != nullptr) {
		if (now->key == c) {
			bool removed = false;
			for (int i = 0; i < now->size; i++)
				if (now->values[i] == v) {
					for (int j = i; j + 1 < now->size; j++)
						now->values[j] = now->values[j + 1];
					now->size--;
					this->hash_table_size--;
					removed = true;
					break;
				}
			if (now->size == 0) {
				delete[] now->values;
				if (prev == nullptr) {
					this->hash_table[where] = now->next;
					delete now;
				}
				else {
					Node* next = now->next;
					prev->next = next;
					delete now;
				}
			}
			return removed;
		}
		prev = now;
		now = now->next;
	}
	return false;
}

//BC=OC=WC=O(n), n is the number of values with key = c
vector<TValue> MultiMap::search(TKey c) const {
	int where = this->hash_function(c);
	Node* now = this->hash_table[where];
	vector<TValue> values;
	while (now != nullptr) {
		if (now->key == c) {
			for (int i = 0; i < now->size; i++)
				values.push_back(now->values[i]);
			break;
		}
		now = now->next;
	}
	return values;
}

//BC=OC=WC=O(1)
int MultiMap::size() const {
	return this->hash_table_size;
}

//BC=OC=WC=O(1)
bool MultiMap::isEmpty() const {
	return this->hash_table_size == 0;
}

//BC=OC=WC=O(1)
MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

//BC=OC=WC=O(capacity * nr of values for each key)
MultiMap::~MultiMap() {
	for (int i = 0; i < this->capacity; i++) {
		Node* now = this->hash_table[i];
		while (now != nullptr) {
			delete[] now->values;
			Node* next = now->next;
			delete now;
			now = next;
		}
	}
	delete[] this->hash_table;
}

//BC=OC=WC=O(1)
int MultiMap::hash_function(int key) const
{
	if (key < 0)
		key = this->capacity + key % this->capacity;
	return key % this->capacity;
}

//BC=OC=WC=O(n)
void MultiMap::resize()
{
	this->capacity *= 2;
	Node** aux = new Node * [this->capacity];
	for (int i = 0; i < this->capacity; i++)
		aux[i] = nullptr;
	for (int i = 0; i < this->capacity / 2; i++) {
		Node* now = this->hash_table[i];
		while (now != nullptr) {
			int where = this->hash_function(now->key);
			Node* next = now->next;
			now->next = aux[where];
			aux[where] = now;
			now = next;
		}
	}
	delete[] this->hash_table;
	this->hash_table = aux;
}

//BC=OC=WC=O(n)
void MultiMap::resize(Node* node)
{
	node->capacity *= 2;
	auto* aux = new TValue[node->capacity];
	for (int i = 0; i < node->size; i++)
		aux[i] = node->values[i];
	delete[] node->values;
	node->values = aux;
}

//BC=OC=WC=O(1)
MultiMap::Node::Node()
{
	this->next = nullptr;
	this->key = 0;
	this->size = 0;
	this->capacity = 1;
	this->values = new TValue[this->capacity];
}

vector<TKey> MultiMap::keySet() const {
	vector<TKey> keys;

	for (int i = 0; i < this->capacity; i++) {
		Node* current = this->hash_table[i];
		while (current != nullptr) {
			keys.push_back(current->key);
			current = current->next;
		}
	}

	return keys;
}

