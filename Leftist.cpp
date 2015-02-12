#include "Leftist.h"


Leftist::Leftist(string name){
	this->name = name;
	root = NULL;
}

string Leftist::toString(int size) const{
	return toString(this->root, size, " ", 0);
}
string Leftist::toString(Node * t, int size, string indent, int current) const{
	stringstream ss;
	if (t == NULL) return "";
	if (t != NULL && current < size){
		indent += "   ";
		current++;
		ss << toString(t->right, size, indent, current);
		ss << indent << t->element.toString() << endl;
		ss << toString(t->left, size, indent, current); 
		ss << count;
		return ss.str();
	}
	return "";
}

void Leftist::insert(ItemType & x) {
	Node * newNode = new Node(x, NULL, NULL);
	if (root == NULL) {
		root = newNode;
	}
	else{
		this->root = merge(this->root, newNode);
	}
	this->size++;
	
}

void Leftist::merge(PQ * second) {
	root = merge(this->root, second->root);
	size += second->size;
}
Node * Leftist::merge(Node * p1, Node *p2){
	count++;
	if (p1 == NULL) return p2;
	if (p2 == NULL) return p1;
	count += 3;
	if (p1->element.priority < p2->element.priority)
	{
		count += 2;
		p1->right = merge(p1->right, p2);
		if (getNPL(p1->left) < getNPL(p1->right)){
			Node * temp = p1->right;
			p1->right = p1->left;
			p1->left = temp;
		}
		p1->npl = getNPL(p1->right) + 1;
		return p1;
	}
	else{
		count += 2;
		p2->right = merge(p2->right, p1);
		if (getNPL(p2->left) < getNPL(p2->right)){
			Node * temp = p2->right;
			p2->right = p2->left;
			p2->left = temp;
			count += 3;
		}
		p2->npl = getNPL(p2->right) + 1;
		return p2;
	}
}
int Leftist::getNPL(Node * t){
	if (t == NULL) return -1;
	return t->npl;
}
ItemType Leftist::deleteMax(){
	Node * temp;
	ItemType it = root->element;
	temp = this->root;
	this->root = merge( root->right, root->left);
	delete temp;
	this->size--;
	return it;
}
void Leftist::makeEmpty() { 
	 size = 0;
}

