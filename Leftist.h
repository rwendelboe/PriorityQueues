#ifndef LEFTIST_H
#define LEFTIST_H
#include "PQ.h"

class Leftist : public PQ
{
public:
	Leftist(string name);
	virtual string toString(int size) const;
	ItemType deleteMax();
	virtual void insert(ItemType & x);
	virtual void merge(PQ * second);
	virtual void makeEmpty();
	int getNPL(Node * t);
private: 
	Node * merge(Node * p1, Node * p2);
	string toString(Node * t, int size, string indent, int current) const;

};
#endif

