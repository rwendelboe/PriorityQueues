#include "SkewHeap.h"

SkewHeap::SkewHeap(string name){
	this->name = name;
}
string SkewHeap::toString(int size) const{
	return toString(this->root, size, " ", 0);
}
string SkewHeap::toString(Node * t, int size, string indent, int current) const{
	stringstream ss;
	if (t == NULL) return "";
	if (t != NULL && current < size){
		indent += "   ";
		current++;
		ss << toString(t->right, size, indent, current);
		ss << indent << t->element.toString() << endl;
		ss << toString(t->left, size, indent, current);
		return ss.str();
	}
	return "";
}
void SkewHeap::insert(ItemType & x){
	Node * newNode = new Node(x, NULL, NULL);
	if (root == NULL) {
		root = newNode;
	}
	else{
		this->root = merge(this->root, newNode);
	}
	this->size++;
}
void SkewHeap::merge(PQ * second) {
	root = merge(this->root, second->root);
	size += second->size;
}
Node * SkewHeap::merge(Node * p1, Node *p2){

	if (p1 == NULL) return p2;
	if (p2 == NULL) return p1;
	if (p1->element.priority < p2->element.priority)
	{
		p1->right = merge(p1->right, p2);

		Node * temp = p1->right;
		p1->right = p1->left;
		p1->left = temp;

		return p1;
	}
	else{
		p2->right = merge(p2->right, p1);

		Node * temp = p2->right;
		p2->right = p2->left;
		p2->left = temp;

		return p2;
	}
}
ItemType SkewHeap::deleteMax(){
	Node * temp;
	ItemType it = root->element;
	temp = this->root;
	this->root = merge(root->right, root->left);
	delete temp;
	this->size--;
	return it;
}
void SkewHeap::makeEmpty() {
	size = 0;
}