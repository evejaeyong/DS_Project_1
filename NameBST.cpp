#include "NameBST.h"
#include <iostream>
using namespace std;

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
		if (a->getName().compare(newNode->getName()) < 0) {
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
NameBSTNode* NameBST::searchData(string name) {
	NameBSTNode* a = root;

	while(1) {
		if (a == NULL) break;
		if (name.compare(a->getName()) == 0) {
			return a;
		}
		else if (name.compare(a->getName()) > 0) {
			a = a->getLeft();
		}
		else a = a->getRight();

	}
	return NULL;
}

// print
void NameBST::print() {
	if(root == NULL) {
		cout << "===== ERROR =====\n";
		cout << "500\n";
		cout << "==============\n";
	}

	else {
		cout << "===== PRINT =====\n";
		cout << "Name_BST\n";
		printData(root);
		cout << "==============\n";
	}
	return;
}

void NameBST::printData(NameBSTNode* node) {
	if (node == NULL) return;

	printData(node->getLeft());
	cout << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-" << node->getStart().month << "-" << node->getStart().day << "/"
			<< node->getEnd().year << "-" << node->getEnd().month << "-" << node->getEnd().day << "\n";
	printData(node->getRight());

	return;
}

// delete
bool NameBST::deleteData(string name) {
	
}