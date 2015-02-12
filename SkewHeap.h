#ifndef SKEWHEAP_H
#define SKEWHEAP_H

#include "PQ.h"

class SkewHeap : public PQ
{
public:
	SkewHeap(string name);
	ItemType deleteMax();
	virtual string toString(int size) const;
	virtual void insert(ItemType & x) ;
	virtual void merge(PQ * second) ;
	virtual void makeEmpty();
private:
	Node * merge(Node * p1, Node * p2);	
	string toString(Node * t, int size, string indent, int current) const;
};
#endif