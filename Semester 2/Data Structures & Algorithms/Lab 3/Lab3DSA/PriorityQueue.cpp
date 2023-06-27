#include "PriorityQueue.h"
#include <stdexcept>

//BC=WC=OC=O(capacity)
PriorityQueue::PriorityQueue(Relation r) {
	//TODO - Implementation
	this->rel = r;
	this->capacity = 10;
	this->head = -1;
	this->tail = -1;
	this->firstEmpty = 0;
	this->nodes = new Node[capacity];
	for (int i = 0; i < capacity - 1; i++) {
		nodes[i].next = i + 1;
	}
	nodes[capacity - 1].next = -1;
	this->size = 0;
}

//BC=WC=OC=O(capacity)
void PriorityQueue::resize() {
	Node* newNodes = new Node[this->capacity * 2];
	int index;
	for (index = 0; index < this->capacity; index++) {
		newNodes[index] = this->nodes[index];
	}
	for (index = this->capacity; index < this->capacity * 2 - 1; index++) {
		newNodes[index].next = index + 1;
	}
	this->firstEmpty = this->capacity;
	this->capacity *= 2;
	newNodes[this->capacity - 1].next = -1;
	delete[] this->nodes;
	this->nodes = newNodes;
}

//BC=O(1)
//WC=OC=O(size)
void PriorityQueue::push(TElem e, TPriority p) {
	//TODO - Implementation
	if (this->size == this->capacity)
		this->resize();
	int newNode = this->firstEmpty;
	this->firstEmpty = this->nodes[firstEmpty].next;
	this->size++;
	if (this->head == -1) { //first element
		this->nodes[newNode].info.first = e;
		this->nodes[newNode].info.second = p;
		this->nodes[newNode].next = -1;
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		int current = this->head;
		int prev = -1;
		while (current != -1 && !this->rel(p, this->nodes[current].info.second)) {
			prev = current;
			current = this->nodes[current].next;
		}
		if (prev == -1) {  // insert at head
			this->nodes[newNode].info.first = e;
			this->nodes[newNode].info.second = p;
			this->nodes[newNode].next = this->head;
			this->head = newNode;
		}
		else {  // insert after prev
			this->nodes[newNode].info.first = e;
			this->nodes[newNode].info.second = p;
			this->nodes[newNode].next = this->nodes[prev].next;
			this->nodes[prev].next = newNode;
		}
		if (this->nodes[newNode].next == -1) {  // update tail
			this->tail = newNode;
		}
	}
}

//BC=WC=OC=O(1)
//throws exception if the queue is empty
Element PriorityQueue::top() const {
	//TODO - Implementation
	if (this->size == 0) {
		throw out_of_range("PriorityQueue is empty");
	}
	return this->nodes[this->head].info;
}

//BC=WC=OC=O(1)
Element PriorityQueue::pop() {
	//TODO - Implementation
	if (this->size == 0) {
		throw out_of_range("PriorityQueue is empty");
	}
	int current = this->head;
	Element elem_with_highest_priority = this->nodes[current].info;
	this->head = this->nodes[current].next;
	this->nodes[current].next = this->firstEmpty;
	this->firstEmpty = current;
	this->size--;
	if (this->size == 0) 
		this->tail = -1;
	
	return elem_with_highest_priority;
}

//BC=WC=OC=O(1)
bool PriorityQueue::isEmpty() const {
	//TODO - Implementation
	if (this->size == 0)
		return true;
	return false;
}

TPriority PriorityQueue::priorityOf(TElem elem) const
{
	TPriority return_value = -1;
	int current = this->head;
	while (current != this->nodes[this->tail].next && this->nodes[current].info.first != elem) {
		current = this->nodes[current].next;
	}
	if (current != this->nodes[this->tail].next)
		return_value = this->nodes[current].info.second;
	return return_value;
}

//BC=WC=OC=O(1)
PriorityQueue::~PriorityQueue() {
	//TODO - Implementation
	delete[] this->nodes;
};

