#include "NameBST.h"

NameBST::NameBST() : root(nullptr) {

}
NameBST::~NameBST() {

}

NameBSTNode* NameBST::getRoot() {
	return root;
}

// insert
void NameBST::insertData(MemberQueueNode* add) {
	NameBSTNode* newNode = new NameBSTNode;
	newNode->setName(add->getName());
	newNode->setAge(add->getAge());
	newNode->setType(add->getType());
	newNode->setDay(add->getDate());

	if (root = NULL) {
		root = newNode;
		return;
	}
	NameBSTNode* a = root;
	while(1) {
		if (a->getName().compare(newNode->getName()) >= 1) {
			if (a->getRight() == NULL) {
				a->setRight(newNode);
				break;
			}
			else a = a->getRight();
		}
		else {
			if(a->getLeft() == NULL) {
				a->setLeft(newNode);
				break;
			}
			else a = a->getLeft();
		}
	}
}
// search

// print

// delete