#include "DHeap.h"
//Create a heap with maximum size "physicalSize" 

DHeap::DHeap(string name, int physicalSize)
{
	this->name = name;
	size = 0;
	heap = new ItemType[physicalSize];
	this->physicalSize = physicalSize;
}

// insert element and re-heapify
void DHeap::insert(ItemType &newVal)
{
	int curr = size;
	assert(size < physicalSize);
	int parent = (curr - 1) / KIDS; // round down
	while (curr>0 && newVal.priority >heap[parent].priority) {
		heap[curr] = heap[parent];
		curr = parent;
		parent = (curr - 1) / KIDS;
	}
	heap[curr] = newVal;
	size++;
}
// Delete maximum value, re-heapify, and return max element
ItemType DHeap::deleteMax()
{
	if (size == 0)
		return ItemType("error", -1);
	ItemType toReturn = heap[0];
	size--;
	ItemType currVal = heap[size];
	int curr = 0;
	int left = 1;
	int right = left + 1;
	while ((left < size && currVal.priority < heap[left].priority) ||
		(right < size && currVal.priority < heap[right].priority)){
		int bestChild = left;
		if (right < size && heap[right].priority > heap[left].priority)
			bestChild = right;
		heap[curr] = heap[bestChild];
		curr = bestChild;
		left = KIDS*bestChild + 1;
		right = left + 1;
	} // endwhile
	heap[curr] = currVal;
	return toReturn;
}
// merge second into current  heap
void DHeap::merge(PQ * second)
{
	for (int i = 0; i < second->getSize(); i++)
		insert(dynamic_cast<DHeap*>(second)->heap[i]);
	second->makeEmpty();
}
// Convert first "size: elements of PQ to a string.
string DHeap::toString(int maxSize) const
{
	const int PERLINE = 5;
	stringstream out;
	out << name << "  current size=" << size;
	if (maxSize > size)
		maxSize = size;
	for (int i = 0; i <maxSize; i++)
	{
		if (i%PERLINE == 0) out << endl;
		out << heap[i].toString() << "\t";
	}
	out << endl;
	return out.str();
}